#include "Requests.hpp"
#include "Objects.hpp"

#include <efc/Request.hpp>
#include <efc/RequestObject.hpp>
#include <cpprest/http_msg.h>

#include <iostream>

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