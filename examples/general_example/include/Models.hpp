#pragma once

#include <efc/Request.hpp>
#include <efc/RequestObject.hpp>
#include <cpprest/json.h>

#include <memory>

class ModelDemo : public efc::RequestObject {
public:
	ModelDemo();
	ModelDemo(int _myInt, const utility::string_t& _myString, std::shared_ptr<web::json::array> _myArr);
	~ModelDemo();

	int myInt;
	utility::string_t myString;
	std::shared_ptr<web::json::array> myArr;

	static void validate(efc::Request& req);
};