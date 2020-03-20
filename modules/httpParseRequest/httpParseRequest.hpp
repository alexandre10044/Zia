/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Template
*/

#ifndef TEMPLATE_HPP_
#define TEMPLATE_HPP_

#include <openZia/IModule.hpp>
#include <openZia/Context.hpp>
#include <openZia/Pipeline.hpp>
#include <openZia/Log.hpp>
#include <map>
#include <cstdint>
class httpParseRequest : public oZ::IModule
{
public:
    /**
         * @brief Construct a new httpParseRequest object
         */
    httpParseRequest();
    /**
         * @brief Destroy the httpParseRequest object
         */
    ~httpParseRequest();
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "httpParseRequest";
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
            (oZ::Priority)(oZ::Priority::ASAP - 1),
            this,
            &httpParseRequest::onInterpret);
    }
    std::string parseWith(std::string delimiter, std::string &str)
    {
        std::string token = str.substr(0, str.find(delimiter));
        str.erase(0, str.find(delimiter) + delimiter.length());
        return (token);
    }
    bool onInterpret(oZ::Context &context)
    {
        oZ::Log(oZ::Information) << "Starting http parse request";
        std::string request = "";
        for (int8_t chr : context.getPacket().getByteArray())
            request += (char)chr;
        // Parsing header
        std::string methodString = parseWith(" ", request);
        std::string URI = parseWith(" ", request);
        context.getRequest().getURI() = URI;
        // Get http version
        std::string version = parseWith("\r\n", request);
        //
        std::string version_nohttp = parseWith("/", version);
        std::string version_major = parseWith(".", version);
        std::string version_minor = version;
        uint8_t minorVersion = (uint8_t)std::atoi(version_minor.c_str());
        uint8_t majorVersion = (uint8_t)std::atoi(version_major.c_str());
        context.getResponse().setVersion(oZ::HTTP::Version(majorVersion, minorVersion));
        context.getRequest().setVersion(oZ::HTTP::Version(majorVersion, minorVersion));
        std::vector<std::string>    lines;
        while (request.length() > 0)
        {
            lines.push_back(parseWith("\r\n", request));
        }
        bool   isBody = false;
        std::string body;
        for (std::string line : lines)
        {
            if (line == "") {
                isBody = true;
                continue;
            }
            if (isBody) {
                body += line + "\r\n";
            } else {
                std::string key = parseWith(": ", line);
                context.getRequest().getHeader().set(key, line);
            }
        }
        for (int i = 0; i <= (int)oZ::HTTP::Method::MethodCount; i++)
        {
            if (i == (int)oZ::HTTP::Method::MethodCount || oZ::HTTP::MethodName((oZ::HTTP::Method)i) == methodString) {
                context.getRequest().setMethod((oZ::HTTP::Method)i);
                break;
            }
        }
        context.getPacket().clear();
        oZ::Log(oZ::Information) << "Parsed header";
        return (true);
    }

protected:
private:
};

#endif /* !TEMPLATE_HPP_ */
