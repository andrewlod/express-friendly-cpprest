#include "App.hpp"

using namespace efc;

int main(int argc, char const *argv[])
{
    App app;

    app.listen(L"127.0.0.1", L"3000");
    while (true); // Change to interrupt
    return 0;
}
