#include "App.hpp"
#include "InterruptHandler.hpp"

#include <iostream>

using namespace efc;

void ping(Request& req);

int main(int argc, char const *argv[])
{
    App app;

    app.get(L"/ping", &ping);
    app.listen(L"127.0.0.1", L"3000");

    std::cout << "Server started." << std::endl;
    
    InterruptHandler::waitForInterrupt();

    std::cout << "Server is closing." << std::endl;

    return 0;
}

void ping(Request& req) {
    req.reply(web::http::status_codes::OK);
}