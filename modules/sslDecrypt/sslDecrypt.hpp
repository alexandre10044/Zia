/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Template
*/

#ifndef TEMPLATE_HPP_
#define TEMPLATE_HPP_

#include <openZia/IModule.hpp>
#include <openZia/Pipeline.hpp>
#include <openZia/Log.hpp>
#include <map>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <iostream>
#include <unistd.h>

class sslDecrypt : public oZ::IModule
{
public:
    /**
         * @brief Construct a new sslDecrypt object
         */
    sslDecrypt() {
          SSL_library_init();
          SSL_load_error_strings();
          OpenSSL_add_all_algorithms();
          sslContext = SSL_CTX_new(SSLv23_server_method());

          if (sslContext) {
               if (SSL_CTX_use_certificate_file(sslContext, "./mycert.pem", SSL_FILETYPE_PEM) > 0) {
                    if (SSL_CTX_use_PrivateKey_file(sslContext, "./mykey.pem", SSL_FILETYPE_PEM) > 0) {
                         if (SSL_CTX_check_private_key(sslContext) > 0)
                              std::cout << "SSL Initiated" << std::endl;
                         else
                              std::cerr << "SSL Private key check failed" << std::endl;
                    }
                    else
                         std::cerr << "SSL Cannot use private key" << std::endl;
               }
               else
                    std::cerr << "SSL Cannot use that certificate" << std::endl;
          }
          else
               std::cerr << "SSL Could not init context" << std::endl;
    }
    /**
         * @brief Destroy the sslDecrypt object
         */
    ~sslDecrypt() {
     SSL_shutdown(ssl);
     SSL_free(ssl);
     ERR_free_strings();
     EVP_cleanup();
    }
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "sslDecrypt";
    }
    void onConnection(oZ::Context &context) {
          int err = 0;
          struct timeval timeout;
          fd_set  fdset;

          ssl = SSL_new(sslContext);
          if (!ssl)
               std::cout << "Failed to create ssl" << std::endl;
          SSL_set_fd(ssl, context.getMetadata<int>("fd"));
          context.setMetadata("ssl", ssl);
          timeout.tv_sec = 1;
          fd = context.getMetadata<int>("fd");
          FD_ZERO(&fdset);
          FD_SET(fd, &fdset);
          accepted = false;
          std::cout << "Setting the FileDescriptor" << std::endl;
          if ((err = SSL_set_fd(ssl, (int)fd)) == 1) {
               err = 0;
                    while (select(fd + 1, &fdset, NULL, NULL, &timeout) <= 0) {}
                    while ((err = SSL_accept(ssl)) <= 0) {}
                    std::cout << "Accepted" << std::endl;
          }
          else {
               std::cout << "Failed to set fd .. (" << fd << ")" << std::endl;
          }
     }

    /**
         * @brief Get the Dependencies object
         * @return Dependencies
         */
    virtual Dependencies getDependencies(void) const noexcept { return {}; }
    // Register your callback to the pipeline
    virtual void onRegisterCallbacks(oZ::Pipeline &pipeline)
    {
        pipeline.registerCallback(
            oZ::State::Interpret,
            (oZ::Priority)(oZ::Priority::ASAP + 10),
            this,
            &sslDecrypt::onInterpret);
    }
    bool onInterpret(oZ::Context &context)
    {   
          uint8_t       buff[20480] = {0};
          int        read = 0;
          int            tot = 0;
          
          std::cout << "Reading ..." << std::endl;
          context.getPacket().getByteArray().clear();
          context.getPacket().clear();

          // Gets the specific ssl created for client
          ssl = context.getMetadata<SSL*>("ssl");
          while (SSL_want_write(ssl)) {}
          while ((read = SSL_read(ssl, buff, 20480)) == 20480) {
               std::cout << "Read " << read << " bytes." << std::endl;
               for (int i = 0; i < read; i++)
                    context.getPacket().getByteArray().push_back(buff[i]);
               std::cout << buff;
               tot += read;
          }
          tot += read;
          if (read > 0) {
               std::cout << buff;
               std::cout << std::endl;
          }
          for (int i = 0; i < read; i++)
               context.getPacket().getByteArray().push_back(buff[i]);
          context.setMetadata("ssl", ssl);
          if (tot <= 0)
               return (false);
          return (true);
    }

protected:
private:
     SSL       *ssl;
     SSL_CTX   *sslContext;
     int       fd;
     bool      accepted;
};

#endif /* !TEMPLATE_HPP_ */
