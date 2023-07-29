#pragma once

#include <cpprest/json.h>

#include <memory>

namespace efc {
	class Validator {
	private:
		/*
		Checks if key exists in the root object.
		*/
		static void checkKey(const web::json::value& root, const utility::string_t& key);

	public:
		/*
		Validates if a key in the root object is a string.
		*/
		static utility::string_t validateString(const web::json::value& root, const utility::string_t& key);

		/*
		Validates if a key in the root object is an integer.
		*/
		static int validateInt(const web::json::value& root, const utility::string_t& key);

		/*
		Validates if a key in the root object is a double.
		*/
		static double validateDouble(const web::json::value& root, const utility::string_t& key);

		/*
		Validates if a key in the root object is a boolean.
		*/
		static bool validateBool(const web::json::value& root, const utility::string_t& key);

		/*
		Validates if a key in the root object is an array.
		*/
		static std::shared_ptr<web::json::array> validateArray(const web::json::value& root, const utility::string_t& key);

		/*
		Validates if a key in the root object is an object.
		*/
		static std::shared_ptr<web::json::object> validateObject(const web::json::value& root, const utility::string_t& key);
	};
}