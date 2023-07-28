#pragma once

#include <cpprest/json.h>

#include <memory>

namespace efc {
	class Validator {
	private:
		static void checkKey(const web::json::value& root, const utility::string_t& key);

	public:
		static utility::string_t validateString(const web::json::value& root, const utility::string_t& key);
		static int validateInt(const web::json::value& root, const utility::string_t& key);
		static double validateDouble(const web::json::value& root, const utility::string_t& key);
		static bool validateBool(const web::json::value& root, const utility::string_t& key);
		static std::shared_ptr<web::json::array> validateArray(const web::json::value& root, const utility::string_t& key);
		static std::shared_ptr<web::json::object> validateObject(const web::json::value& root, const utility::string_t& key);
	};
}