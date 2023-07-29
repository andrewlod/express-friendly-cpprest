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
        Router();
        Router(const utility::string_t& path);
        ~Router();

        /*
        Register a GET request handler in a given path/route.
        */
        void get(const utility::string_t& path, const std::function<void(Request&)> handler);

        /*
        Register a POST request handler in a given path/route.
        */
        void post(const utility::string_t& path, const std::function<void(Request&)> handler);

        /*
        Register a PUT request handler in a given path/route.
        */
        void put(const utility::string_t& path, const std::function<void(Request&)> handler);

        /*
        Register a DELETE request handler in a given path/route.
        */
        void del(const utility::string_t& path, const std::function<void(Request&)> handler);

        void get(const utility::string_t& path, const std::function<void(Request&)> handler, const std::function<void(Request&)> validator);
        void post(const utility::string_t& path, const std::function<void(Request&)> handler, const std::function<void(Request&)> validator);
        void put(const utility::string_t& path, const std::function<void(Request&)> handler, const std::function<void(Request&)> validator);
        void del(const utility::string_t& path, const std::function<void(Request&)> handler, const std::function<void(Request&)> validator);


        /*
        Register a middleware request handler in a given path/route, which is called before HTTP method handlers.
        Multiple middlewares may be registered for the same path. The order is given by the order that the callbacks are registered.
        */
        void use(const utility::string_t& path, const std::function<void(Request&)> handler);


        /*
        Routes a request to its respective path callback.
        Sends 404 NOT FOUND if there is no corresponding callback for its path.
        */
        void route(const web::http::method& method, std::queue<utility::string_t> path, std::shared_ptr<Request> req);

        /*
        Registers a route recursively. Used by get, post, put and del methods.
        */
        void registerRoute(const web::http::method& method, std::queue<utility::string_t> path, const std::function<void(Request&)> handler);


        /*
        Registers a middleware recursively. Used by 'use' method.
        */
        void registerMiddleware(std::queue<utility::string_t> path, const std::function<void(Request&)> handler);
    private:
        utility::string_t path;

        std::map<utility::string_t, std::unique_ptr<Router> > routers;

        std::vector<
            std::function<void(Request&)> > middlewares;

        std::map<
            web::http::method, std::vector<
                    std::function<void(Request&)> > > callbacks;
    };
}