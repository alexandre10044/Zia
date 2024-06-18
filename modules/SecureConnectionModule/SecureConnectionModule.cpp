/*
** EPITECH PROJECT, 2020
** Secure Connection
** File description:
** zia
*/

#include "SecureConnectionModule.hpp"

SecureConnectionModule::SecureConnectionModule()
{
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    sslContext = create_context();
    ssl = SSL_new(sslContext);
}

SSL_CTX *SecureConnectionModule::create_context()
{
    const SSL_METHOD *method;
    method = SSLv23_server_method();
    SSL_CTX *ctx = SSL_CTX_new(method);

    if (!ctx){
        std::cerr << "Unable to create SSL context" << std::endl;
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    if (SSL_CTX_use_certificate_file(ctx, "./mycert.pem", SSL_FILETYPE_PEM) <= 0) {
        std::cout << "Error with the certificate" << std::endl;
        ERR_print_errors_fp(stderr);
        //abort();
    } else {
        std::cout << "Cert used" << std::endl;
    }
    if (SSL_CTX_use_PrivateKey_file(ctx, "./mykey.pem", SSL_FILETYPE_PEM) <= 0) {
        std::cout << "Error with the certificate" << std::endl;
        ERR_print_errors_fp(stderr);
        //abort();
    } else {
        std::cout << "Key used" << std::endl;
    }
    if (!SSL_CTX_check_private_key(ctx)) {
        std::cout << "Private key does not match the public certificate\n";
        //abort();
    } else {
        std::cout << "Key checked" << std::endl;
    }
    return ctx;
}

SecureConnectionModule::~SecureConnectionModule()
{
    SSL_shutdown(ssl);
    SSL_free(ssl);
    ERR_free_strings();
    EVP_cleanup();
}

bool SecureConnectionModule::sslSetFd(int fd)
{
    int i = SSL_set_fd(ssl, fd);
    int j;
    std::cout << "-----------------" << std::endl;

    if (i == 0) {
        std::cout << "set fd error\n";
        ERR_print_errors_fp(stderr);
        return false;
    }
    j = SSL_accept(ssl);
    std::cout << j << std::endl;
    if (j <= 0)
    {
        std::cout << "accept error\n";
        std::cout << SSL_get_error(ssl, j) << " => Get ERROR\n";
        std::cout << "-----------------" << std::endl;
        return false;
    }
    std::cout << "-----------------" << std::endl;
    return true;
}

bool SecureConnectionModule::readSSL(oZ::Context &context)
{
    char buffer[1024];

    std::cout << "-----------------" << std::endl;
    int bytes = SSL_read(ssl, buffer, sizeof(buffer));
    if (bytes < 0) {
        std::cerr << SSL_get_error(ssl, bytes) << std::endl;
        std::cerr << "Error in read" << std::endl;
        std::cout << "-----------------" << std::endl;
        return false;
    } else {
        buffer[bytes] = '\0';
        std::cout << "Client message : " << buffer << std::endl;
        if (!writeSSL("Hello there !", context))
            std::cerr << "Error in write of the answer" << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    return true;
}

bool SecureConnectionModule::writeSSL(std::string reply, oZ::Context &context)
{
    if (context.hasError()) {
        context.setErrorState();
        return false;
    }
    if (SSL_write(ssl, reply.c_str(), reply.length()) <= 0)
        return false;
    return true;
}

OPEN_ZIA_MAKE_ENTRY_POINT(SecureConnectionModule);