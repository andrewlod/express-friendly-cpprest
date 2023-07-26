#include "Middlewares.hpp"
#include "Objects.hpp"

using namespace efc;

void createSomeStuff(Request& req) {
    auto obj = std::make_shared<TestObject>();
    obj->message = "123134445";
    req.add_attribute("my_message", obj);
}