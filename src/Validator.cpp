#include "Validator.hpp"

#include <cpprest/json.h>

#include <memory>

namespace efc {
	void Validator::checkKey(const web::json::value& root, const utility::string_t& key) {
		if (!root.has_field(key)) {
			const utility::string_t message = L"Key '" + key + L"' is missing!";
			throw web::json::json_exception(message.c_str());
		}
	}

	utility::string_t Validator::validateString(const web::json::value& root, const utility::string_t& key) {
		checkKey(root, key);

		const web::json::value field = root.at(key);
		if (!field.is_string()) {
			const utility::string_t message = L"Key '" + key + L"' must be a string!";
			throw web::json::json_exception(message.c_str());
		}

		return field.as_string();
	}

	int Validator::validateInt(const web::json::value& root, const utility::string_t& key) {
		checkKey(root, key);

		const web::json::value field = root.at(key);
		if (!field.is_integer()) {
			const utility::string_t message = L"Key '" + key + L"' must be an integer!";
			throw web::json::json_exception(message.c_str());
		}

		return field.as_integer();
	}

	double Validator::validateDouble(const web::json::value& root, const utility::string_t& key) {
		checkKey(root, key);

		const web::json::value field = root.at(key);
		if (!field.is_double()) {
			const utility::string_t message = L"Key '" + key + L"' must be a double!";
			throw web::json::json_exception(message.c_str());
		}

		return field.as_double();
	}

	bool Validator::validateBool(const web::json::value& root, const utility::string_t& key) {
		checkKey(root, key);

		const web::json::value field = root.at(key);
		if (!field.is_boolean()) {
			const utility::string_t message = L"Key '" + key + L"' must be a boolean!";
			throw web::json::json_exception(message.c_str());
		}

		return field.as_bool();
	}

	std::shared_ptr<web::json::array> Validator::validateArray(const web::json::value& root, const utility::string_t& key) {
		checkKey(root, key);

		const web::json::value field = root.at(key);
		if (!field.is_array()) {
			const utility::string_t message = L"Key '" + key + L"' must be an array!";
			throw web::json::json_exception(message.c_str());
		}

		std::shared_ptr<web::json::array> arr = std::make_shared<web::json::array>(field.as_array());
		return arr;
	}

	std::shared_ptr<web::json::object> Validator::validateObject(const web::json::value& root, const utility::string_t& key) {
		checkKey(root, key);

		const web::json::value field = root.at(key);
		if (!field.is_object()) {
			const utility::string_t message = L"Key '" + key + L"' must be an object!";
			throw web::json::json_exception(message.c_str());
		}

		std::shared_ptr<web::json::object> obj = std::make_shared<web::json::object>(field.as_object());
		return obj;
	}
}