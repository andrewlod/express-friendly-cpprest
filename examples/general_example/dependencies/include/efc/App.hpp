#pragma once

#include "Router.hpp"
#include "Request.hpp"

#include <string>
#include <functional>

#include <cpprest/http_listener.h>

namespace efc {
    class App : public Router {
    public:
        App() {}
        ~App() {}

        void listen(const utility::string_t& address, const utility::string_t& port, const utility::string_t& protocol = L"http");
        void close();

        void on_error(std::function<void(Request&)> handler);

        void handleRequest(web::http::http_request req);
    private:
        web::http::experimental::listener::http_listener listener;
        std::function<void(Request&)> errorHandler;
    };
}