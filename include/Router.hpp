#pragma once

#include "Request.hpp"

#include <cpprest/http_client.h>

#include <map>
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace efc {
    class Router {
    public:
        void get(const utility::string_t& path, const std::function<void(Request&)> handler);
        void post(const utility::string_t& path, const std::function<void(Request&)> handler);
        void put(const utility::string_t& path, const std::function<void(Request&)> handler);
        void del(const utility::string_t& path, const std::function<void(Request&)> handler);

        void use(const utility::string_t& path, const std::function<void(Request&)> handler);

        void route(const web::http::method& method, std::queue<utility::string_t> path, std::shared_ptr<Request> req);
        void registerRoute(const web::http::method& method, std::queue<utility::string_t> path, const std::function<void(Request&)> handler);
    private:

        std::map<utility::string_t, std::unique_ptr<Router> > routers;
        std::map<
            web::http::method, std::vector<
                    std::function<void(Request&)> > > callbacks;
    };
}