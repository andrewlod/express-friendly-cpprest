#include "App.hpp"
#include "InterruptHandler.hpp"
#include "RequestObject.hpp"

#include <iostream>

using namespace efc;

class TestObject : public RequestObject {
public:
    TestObject() {};
    ~TestObject() {};
    std::string message;
};

void createSomeStuff(Request& req);
void ping(Request& req);

int main(int argc, char const *argv[])
{
    App app;

    app.use(L"/", &createSomeStuff);
    app.get(L"/ping/test/very/long/path", &ping);
    app.listen(L"127.0.0.1", L"3000");

    std::cout << "Server started." << std::endl;
    
    InterruptHandler::waitForInterrupt();

    std::cout << "Server is closing." << std::endl;

    return 0;
}

void createSomeStuff(Request& req) {
    auto obj = std::make_shared<TestObject>();
    obj->message = "123134445";
    req.add_attribute("my_message", obj);
}
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