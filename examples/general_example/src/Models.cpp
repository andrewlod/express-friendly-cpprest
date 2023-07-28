#include "Models.hpp"

#include <efc/Validator.hpp>
#include <cpprest/json.h>

#include <memory>

using namespace efc;

ModelDemo::ModelDemo() : myInt(0), myString(L""), myArr(nullptr) {

}

ModelDemo::ModelDemo(int _myInt, const utility::string_t& _myString, std::shared_ptr<web::json::array> _myArr) : myInt(_myInt), myString(_myString), myArr(_myArr) {

}

ModelDemo::~ModelDemo() {

}

void ModelDemo::validate(Request& req) {
	auto obj = req.get_json();

	auto model = std::make_shared<ModelDemo>(
		Validator::validateInt(*obj, L"myInt"),
		Validator::validateString(*obj, L"myString"),
		Validator::validateArray(*obj, L"myArr")
	);

	req.add_attribute("body", model);
}