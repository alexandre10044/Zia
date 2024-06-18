/*
** EPITECH PROJECT, 2020
** Php
** File description:
** zia
*/

#ifndef PHP_HPP_
#define PHP_HPP_

#include <iostream>
#include <openZia/IModule.hpp>
#include <openZia/Pipeline.hpp>
#include "Config.hpp"
#include <sys/wait.h>

class PhpCgiModule : public oZ::IModule {
	public:
		PhpCgiModule();
		~PhpCgiModule();

		virtual const char *getName(void) const { return "PhpCgiModule"; }

		virtual void onRegisterCallbacks(oZ::Pipeline &pipeline)
		{
			pipeline.registerCallback(
				oZ::State::Interpret,
				(oZ::Priority)(oZ::Priority::ASAP - 5),
				this,
				&PhpCgiModule::exeCgi);
		}
		bool exeCgi(oZ::Context &);
		virtual void onLoadConfigurationFile(const std::string &directory) {
        	conf.read(directory + "/config.conf");
		}
	private:
		Config conf;
};

#endif /* !PHP_HPP_ */
