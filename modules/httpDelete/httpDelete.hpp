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
#include <filesystem>
#include "Config.hpp"
class httpDelete : public oZ::IModule
{
public:
    /**
         * @brief Construct a new httpDelete object
         */
    httpDelete();
    /**
         * @brief Destroy the httpDelete object
         */
    ~httpDelete();
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "httpDelete";
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
            (oZ::Priority)(oZ::Priority::ASAP - 7),
            this,
            &httpDelete::onInterpret);
    }
    bool onInterpret(oZ::Context &context)
    {
          std::string     uri = context.getRequest().getURI();
          std::string     base = conf.get("www_directory");

          // Breaks if request not found
          if (context.getRequest().getMethod() != oZ::HTTP::Method::Delete ||
               context.getResponse().getCode() != oZ::HTTP::Code::Undefined)
               return (true);
          
          if (std::filesystem::exists(uri + base)) {
               std::filesystem::remove(uri + base);
               // 200 OK
               context.getResponse().setVersion(oZ::HTTP::Version(1, 1));
               context.getResponse().setCode(oZ::HTTP::Code::OK);
               context.getResponse().getBody() += "File deleted";
               context.getResponse().getHeader().set("Content-Type", "text/html");
               oZ::Log(oZ::Information) << "DELETE : Success";
          } else {
               // 404 not found    
               context.getResponse().setVersion(oZ::HTTP::Version(1, 1));
               context.getResponse().setCode(oZ::HTTP::Code::NotFound);
               context.getResponse().getBody() += "Not found";
               context.getResponse().getHeader().set("Content-Type", "text/html");
               oZ::Log(oZ::Information) << "DELETE : File not found";
          }
          return (true);
    }
    virtual void onLoadConfigurationFile(const std::string &directory) {
        conf.read(directory + "/config.conf");
    }

protected:
private:
     Config conf;
};

#endif /* !TEMPLATE_HPP_ */
