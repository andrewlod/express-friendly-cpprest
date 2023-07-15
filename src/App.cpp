#include "App.hpp"

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
        this->listener.support(std::bind(&App::route, this, std::placeholders::_1));
    }

    void App::close() {
        this->listener.close().wait();
    }

    void App::route(web::http::http_request req){
        std::wcout << req.method() << std::endl;
    }
}