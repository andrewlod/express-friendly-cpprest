#include "App.hpp"

using namespace efc;

int main(int argc, char const *argv[])
{
    App app;

    app.listen("0.0.0.0", 3000);
    return 0;
}
