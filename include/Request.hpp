#pragma once

#include <cpprest/http_msg.h>

namespace efc {
    class Request {
    public:
        Request(web::http::http_request req);
        ~Request();

        void reply(web::http::status_code statusCode);
    private:
        web::http::http_request req;
    };
}