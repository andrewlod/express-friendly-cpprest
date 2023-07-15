#include "App.hpp"

#include <iostream>
#include <string>

namespace efc {
    void App::listen(const std::string& address, const int& port, const std::string& protocol) {
        web::uri_builder builder;
        const utility::string_t host = utility::conversions::to_string_t(protocol + "://" + address);
        builder.set_host(host);

        builder.set_port(port);

        this->listener = web::http::experimental::listener::http_listener(builder.to_uri());
        this->listener.open().wait();

        this->listener.support(std::bind(&App::route, this, std::placeholders::_1));
    }

    void App::close() {
        this->listener.close().wait();
    }

    void App::route(web::http::http_request req){
        std::cout << req.method().c_str() << std::endl;
    }
}