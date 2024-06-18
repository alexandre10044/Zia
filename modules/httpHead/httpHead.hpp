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
class httpHead : public oZ::IModule
{
public:
    /**
         * @brief Construct a new httpHead object
         */
    httpHead();
    /**
         * @brief Destroy the httpHead object
         */
    ~httpHead();
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "httpHead";
    }
    /**
         * @brief Get the Dependencies object
         * @return Dependencies
         */
    virtual Dependencies getDependencies(void) const noexcept { return {"httpParseRequest", "httpCheckRequest", "httpGet"}; }
    // Register your callback to the pipeline
    virtual void onRegisterCallbacks(oZ::Pipeline &pipeline)
    {
        pipeline.registerCallback(
            oZ::State::Interpret,
            (oZ::Priority)(oZ::Priority::ASAP - 6),
            this,
            &httpHead::onInterpret);
    }
    bool onInterpret(oZ::Context &context)
    {
        if (context.getRequest().getMethod() == oZ::HTTP::Method::Head)
        {
          // Here the GET request already filled this for us.
          // We only have to empty the body.
          // TODO for php also ?
             context.getResponse().getBody() = "";
        }
        return (true);
    }

protected:
private:
};

#endif /* !TEMPLATE_HPP_ */
