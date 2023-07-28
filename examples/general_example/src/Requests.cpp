#include "Requests.hpp"
#include "Objects.hpp"
#include "Models.hpp"

#include <efc/Request.hpp>
#include <efc/RequestObject.hpp>
#include <cpprest/http_msg.h>

#include <iostream>
#include <string>

using namespace efc;

void ping(Request& req) {
    RequestObject* baseObj = req.get_attribute("my_message").get();
    TestObject* obj = dynamic_cast<TestObject*>(baseObj);
    if (obj == nullptr) {
        std::cout << "NULL" << std::endl;
        return;
    }
    std::cout << obj->message << std::endl;
    req.reply(web::http::status_codes::OK, "Pong!");
}

void throw_error(Request& req) {
    std::string().at(1);
}

void validation_demo(Request& req) {
    auto body = std::dynamic_pointer_cast<ModelDemo>(req.get_attribute("body"));
    std::wcout << L"myInt: " << body->myInt << std::endl;
    std::wcout << L"myString: " << body->myString << std::endl;

    auto myArr = body->myArr;
    for (int i = 0; i < myArr->size(); i++) {
        std::wcout << L"myArr[" << i << L"]: " << myArr->at(i) << std::endl;
    }

    req.reply(web::http::status_codes::OK, body->myInt);
}