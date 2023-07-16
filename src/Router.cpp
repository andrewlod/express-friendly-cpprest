#include "Router.hpp"
#include "Constants.hpp"
#include "Utils.hpp"

#include <vector>
#include <queue>
#include <map>

namespace efc {
    void Router::get(const utility::string_t& path, const std::function<void(Request&)> handler) {
        this->registerRoute(web::http::methods::GET, splitPath(path), handler);
    }

    void Router::post(const utility::string_t& path, const std::function<void(Request&)> handler) {
        this->registerRoute(web::http::methods::POST, splitPath(path), handler);
    }

    void Router::put(const utility::string_t& path, const std::function<void(Request&)> handler) {
        this->registerRoute(web::http::methods::PUT, splitPath(path), handler);
    }

    void Router::del(const utility::string_t& path, const std::function<void(Request&)> handler) {
        this->registerRoute(web::http::methods::DEL, splitPath(path), handler);
    }

    void Router::use(const utility::string_t& path, const std::function<void(Request&)> handler) {
        this->registerMiddleware(splitPath(path), handler);
    }

    void Router::registerRoute(const web::http::method& method, std::queue<utility::string_t> path, const std::function<void(Request&)> handler) {
        if (path.size() == 0) {
            if (!this->callbacks.count(method)) {
                this->callbacks[method] = std::vector<std::function<void(Request&)> >();
            }

            this->callbacks[method].push_back(handler);
            return;
        }

        utility::string_t first = path.front();
        if (!this->routers.count(first)) {
            this->routers[first] = std::make_unique<Router>();
        }

        path.pop();
        this->routers[first]->registerRoute(method, path, handler);
    }

    void Router::route(const web::http::method& method, std::queue<utility::string_t> path, std::shared_ptr<Request> req) {
        if (this->middlewares.size()) {
            for (int i = 0; i < this->middlewares.size(); i++) {
                this->middlewares[i](*req);
            }
        }

        if (path.size() == 0) {
            if (!this->callbacks.count(method)) {
                req->reply(web::http::status_codes::NotFound);
                return;
            }

            std::vector<std::function<void(Request&)> > callbackList = this->callbacks[method];
            for (int i = 0; i < callbackList.size(); i++) {
                callbackList[i](*req);
            }
            return;
        }

        utility::string_t first = path.front();
        if (!this->routers.count(first)) {
            req->reply(web::http::status_codes::NotFound);
            return;
        }

        path.pop();
        this->routers[first]->route(method, path, req);
    }


    void Router::registerMiddleware(std::queue<utility::string_t> path, const std::function<void(Request&)> handler) {
        if (path.size() == 0) {
            this->middlewares.push_back(handler);
            return;
        }

        utility::string_t first = path.front();
        if (!this->routers.count(first)) {
            this->routers[first] = std::make_unique<Router>();
        }

        path.pop();
        this->routers[first]->registerMiddleware(path, handler);
    }
}