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
class httpPut : public oZ::IModule
{
public:
    /**
         * @brief Construct a new httpPut object
         */
    httpPut();
    /**
         * @brief Destroy the httpPut object
         */
    ~httpPut();
    /**
         * @brief Get the Name object
         * @return const char*
         */
    virtual const char *getName(void) const
    {
        return "httpPut";
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
            (oZ::Priority)(oZ::Priority::ASAP - 8),
            this,
            &httpPut::onInterpret);
    }
    bool onInterpret(oZ::Context &context)
    {

         return (true);
    }

protected:
private:
};

#endif /* !TEMPLATE_HPP_ */
