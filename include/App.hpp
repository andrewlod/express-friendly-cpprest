#pragma once

#include "Router.hpp"

#include <string>
#include <cpprest/http_listener.h>

namespace efc {
    class App : public Router {
    public:
        void listen(const std::string& address, const int& port, const std::string& protocol = "http");
        void close();

        void route(web::http::http_request req);
    private:
        web::http::experimental::listener::http_listener listener;
    };
}