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
class httpCheckRequest : public oZ::IModule
{
public:
    /**
         * @brief Construct a new httpCheckRequest object
         */
    httpCheckRequest();
    /**
         * @brief Destroy the httpCheckRequest object
         */
    ~httpCheckRequest();
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "httpCheckRequest";
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
            (oZ::Priority)(oZ::Priority::ASAP - 2),
            this,
            &httpCheckRequest::onInterpret);
    }

    bool  setError(oZ::Context &context, std::string message)
    {
         context.getResponse().setVersion(oZ::HTTP::Version(1, 1));
         context.getResponse().setCode(oZ::HTTP::Code::BadRequest);
         context.getResponse().getBody() += message;
         context.getResponse().getHeader().set("Content-Type", "text/html");
         oZ::Log(oZ::Information) << "Wrong header sent : " + message;
         return true;
    }

    bool onInterpret(oZ::Context &context)
    {
          // Checks HTTP Version
          if (!(context.getRequest().getVersion() == oZ::HTTP::Version(1, 1)))
               return (setError(context, "Invalid version"));
          // Checks methods
          if ((int)context.getRequest().getMethod() == (int)oZ::HTTP::Method::MethodCount)
               return (setError(context, "Unknown Method"));

         oZ::Log(oZ::Information) << "Header is valid";
         return (true);
    }

protected:
private:
};

#endif /* !TEMPLATE_HPP_ */
