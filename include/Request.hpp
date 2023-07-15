#pragma once

#include <cpprest/http_msg.h>

namespace efc {
    class Request {
    private:
        web::http::http_request req;
    };
}