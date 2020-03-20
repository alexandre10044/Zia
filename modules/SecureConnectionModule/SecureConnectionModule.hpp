/*
** EPITECH PROJECT, 2020
** Secure connection
** File description:
** zia
*/

#ifndef SECURE_HPP_
#define SECURE_HPP_

#include <memory>
#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openZia/IModule.hpp>
#include <openZia/Pipeline.hpp>

class SecureConnectionModule : public oZ::IModule {
    public:

        SecureConnectionModule();
        ~SecureConnectionModule();

        virtual const char *getName(void) const { return "SecureConnectionModule"; }

        void onConnection(const oZ::FileDescriptor fd, const oZ::Endpoint endpoint, const bool useEncryption) {
            std::cout << "Set the FileDescriptor" << std::endl;
            sslSetFd((int)fd);
	    }

        virtual void onDisconnection(const oZ::FileDescriptor fd , const oZ::Endpoint, const bool) {
            std::cout << "On disconnection" << std::endl;
        }

        virtual void onRegisterCallbacks(oZ::Pipeline &pipeline)
        {
            pipeline.registerCallback(
                oZ::State::BeforeInterpret,
                oZ::Priority::ASAP,
                this,
                &SecureConnectionModule::readSSL);
	    }
        SSL_CTX *create_context();
        void ShowCerts(SSL*);
        bool sslSetFd(int);
        bool readSSL(oZ::Context &);
        bool writeSSL(std::string, oZ::Context &);

    private:
        SSL *ssl;
        SSL_CTX *sslContext;
};

#endif /* !SECURE_HPP_ */
