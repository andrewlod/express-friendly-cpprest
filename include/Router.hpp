#pragma once

#include "Request.hpp"

#include <cpprest/http_client.h>

#include <queue>
#include <string>
#include <memory>
#include <functional>

namespace efc {
    class Router {
    public:
        void get(const std::string& path, const std::function<void(Request&)>& handler);
        void post(const std::string& path, const std::function<void(Request&)>& handler);
        void put(const std::string& path, const std::function<void(Request&)>& handler);
        void del(const std::string& path, const std::function<void(Request&)>& handler);

        void use(const std::string& path, const std::function<void(Request&)>& handler);

        void route(const web::http::method& method, std::queue<std::string> path, std::unique_ptr<Request> req);
    private:
        void registerRoute(const web::http::method& method, const std::string& path, const std::function<void(Request&)>& handler);
    };
}