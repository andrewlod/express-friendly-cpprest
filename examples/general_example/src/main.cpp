#include <efc/App.hpp>
#include <efc/InterruptHandler.hpp>
#include <efc/RequestObject.hpp>

#include "Middlewares.hpp"
#include "Requests.hpp"

#include <iostream>

using namespace efc;


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