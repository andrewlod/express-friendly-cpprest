#pragma once

#include "Request.hpp"

#include <functional>
#include <memory>
#include <map>

#include <cpprest/http_msg.h>

namespace efc {
	class ValidationManager {
	public:
		static void validate(const utility::string_t& route, Request& req);
		static void registerValidator(const utility::string_t& route, const std::function<void(Request&)> validator);
	private:
		static std::shared_ptr<ValidationManager> getInstance();

		static std::shared_ptr<ValidationManager> instance;
		std::map<utility::string_t, std::function<void(Request&)> > validators;
	};
}