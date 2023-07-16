#include "App.hpp"
#include "Utils.hpp"
#include "Request.hpp"

#include <memory>
#include <iostream>
#include <string>

namespace efc {
    void App::listen(const utility::string_t& address, const utility::string_t& port, const utility::string_t& protocol) {
        web::uri appUri(protocol + L"://" + address + L":" + port);

        web::uri_builder builder;
        builder.set_scheme(appUri.scheme());
        builder.set_host(appUri.host());
        builder.set_port(appUri.port());
        builder.set_path(appUri.path());

        this->listener = web::http::experimental::listener::http_listener(builder.to_uri());

        this->listener.open().wait();
        this->listener.support(std::bind(&App::handleRequest, this, std::placeholders::_1));
    }

    void App::close() {
        this->listener.close().wait();
    }

    void App::handleRequest(web::http::http_request req) {
        std::shared_ptr<Request> wrappedReq = std::make_shared<Request>(req);

        utility::string_t path = web::uri::decode(req.relative_uri().path());
        this->route(req.method(), splitPath(path), wrappedReq);
    }
}