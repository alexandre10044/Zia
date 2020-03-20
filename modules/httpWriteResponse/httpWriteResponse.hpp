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
class httpWriteResponse : public oZ::IModule
{
public:
    /**
         * @brief Construct a new httpWriteResponse object
         */
    httpWriteResponse();
    /**
         * @brief Destroy the httpWriteResponse object
         */
    ~httpWriteResponse();
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "httpWriteResponse";
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
            (oZ::Priority)(oZ::Priority::ASAP - 10),
            this,
            &httpWriteResponse::onInterpret);
    }
    bool onInterpret(oZ::Context &context)
    {
          // There it should be ok for most of the requests
          oZ::HTTP::Response response = context.getResponse();
          std::string responseMsg = "";
          std::string version;

          version += std::to_string(response.getVersion().majorVersion);
          version += ".";
          version += std::to_string(response.getVersion().minorVersion);
          responseMsg += "HTTP/" + version + " ";
          responseMsg += std::to_string((int)response.getCode());

          // Http Code Message
          responseMsg += "\r\n";
          // Date of request
          responseMsg += "Date: ";
          time_t rawtime;
          struct tm *timeinfo;
          char buffer[80];

          time(&rawtime);
          timeinfo = localtime(&rawtime);

          strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
          std::string str(buffer);
          responseMsg += str + "\r\n";

           // Length of response
          responseMsg += "Content-Length: " + std::to_string(response.getBody().length()) + "\r\n";
          responseMsg += "Connection: keep-alive\r\n";
          oZ::HTTP::StringMultimap map = response.getHeader().getStringMultimap();
          try {
          responseMsg += "Content-Type: " + response.getHeader().get("Content-Type") + "\r\n\r\n";

          } catch (std::exception e) {

          }
         // Content type

          // Body
          responseMsg += response.getBody() + "\r\n";
          context.getPacket().getByteArray().clear();
          for (int i = 0; i < responseMsg.length(); i++)
          {
               uint8_t     chr = responseMsg[i];
               context.getPacket().getByteArray().push_back(chr);
          }
          oZ::Log(oZ::Information) << "Wrote packet";
          return (true);
    }

protected:
private:
};

#endif /* !TEMPLATE_HPP_ */
