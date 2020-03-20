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
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
class sslEncrypt : public oZ::IModule
{
public:
    /**
         * @brief Construct a new sslEncrypt object
         */
    sslEncrypt() {
         
    }
    /**
         * @brief Destroy the sslEncrypt object
         */
    ~sslEncrypt() {
          
    }
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "sslEncrypt";
    }

    void  onDisconnection(oZ::Context &context) {
        
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
            oZ::State::Completed,
            (oZ::Priority)(oZ::Priority::ASAP - 20),
            this,
            &sslEncrypt::onInterpret);
    }
    bool onInterpret(oZ::Context &context)
    {
        uint8_t     buffer[context.getPacket().getByteArray().size()];
     
        ssl = context.getMetadata<SSL*>("ssl");
        for (int i = 0; i < context.getPacket().getByteArray().size(); i++)
        {
            buffer[i] = context.getPacket().getByteArray()[i];
        }
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set, SIGPIPE);
        if (pthread_sigmask(SIG_BLOCK, &set, NULL) != 0)
            return false;
        if (context.getPacket().getByteArray().size() <= 0)
            return (false);
        while (SSL_want_read(ssl)) {

        }
        if (SSL_write(ssl, buffer, sizeof(buffer)) != sizeof(buffer)) {
            std::cout << "Failed .." << std::endl;
        }
        std::cout << "Sent response" << std::endl;
        return (true);
    }

protected:
private:
    SSL *ssl;
};

#endif /* !TEMPLATE_HPP_ */
