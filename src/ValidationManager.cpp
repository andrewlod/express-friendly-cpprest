#include "ValidationManager.hpp"

#include "Request.hpp"

#include <memory>

namespace efc {
	std::shared_ptr<ValidationManager> ValidationManager::instance;

	std::shared_ptr<ValidationManager> ValidationManager::getInstance() {
		if (ValidationManager::instance == nullptr) {
			ValidationManager::instance = std::make_shared<ValidationManager>();
		}

		return ValidationManager::instance;
	}

	void ValidationManager::validate(const utility::string_t& route, Request& req) {
		auto validationManager = ValidationManager::getInstance();
		if (!validationManager->validators.count(route)) return;

		validationManager->validators[route](req);
	}

	void ValidationManager::registerValidator(const utility::string_t& route, const std::function<void(Request&)> validator) {
		auto validationManager = ValidationManager::getInstance();

		validationManager->validators[route] = validator;
	}
}