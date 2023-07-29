#pragma once

#include "Request.hpp"

#include <functional>
#include <memory>
#include <map>

#include <cpprest/http_msg.h>

namespace efc {
	class ValidationManager {
	public:
		/*
		Calls a validator in its respective path/route, if available.
		*/
		static void validate(const utility::string_t& route, Request& req);

		/*
		Registers a validator in a given path/route.
		*/
		static void registerValidator(const utility::string_t& route, const std::function<void(Request&)> validator);
	private:
		static std::shared_ptr<ValidationManager> getInstance();

		static std::shared_ptr<ValidationManager> instance;
		std::map<utility::string_t, std::function<void(Request&)> > validators;
	};
}