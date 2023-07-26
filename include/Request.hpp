#pragma once

#include "RequestObject.hpp"

#include <cpprest/http_msg.h>
#include <memory>
#include <map>

namespace efc {
    class Request {
    public:
        Request(web::http::http_request req);
        ~Request();

        web::http::http_request req;

        void reply(web::http::status_code status, const concurrency::streams::istream& body, utility::size64_t content_length, const utility::string_t& content_type = _XPLATSTR("application/octet-stream")) const;
        void reply(web::http::status_code status, const concurrency::streams::istream& body, const utility::string_t& content_type = _XPLATSTR("application/octet-stream")) const;
        void reply(web::http::status_code status, const utf16string& body_data, const utf16string& content_type = ::utility::conversions::to_utf16string("text/plain")) const;
        void reply(web::http::status_code status, utf8string&& body_data, const utf8string& content_type = "text/plain; charset=utf-8") const;
        void reply(web::http::status_code status, const web::json::value& body_data) const;
        void reply(web::http::status_code statusCode) const;
        void reply(const web::http::http_response& response) const;

        std::shared_ptr<web::json::value> get_json(bool ignore_content_type = false);
        std::shared_ptr<utility::string_t> get_string(bool ignore_content_type = false);
        std::shared_ptr<std::vector<unsigned char> > get_vector();

        void add_attribute(const std::string& key, std::shared_ptr<RequestObject> value);
        std::shared_ptr<RequestObject> get_attribute(const std::string& key);

    private:
        std::map<std::string, std::shared_ptr<RequestObject> > attributes;
        std::shared_ptr<web::json::value> jsonBody;
        std::shared_ptr<utility::string_t> stringBody;
        std::shared_ptr<std::vector<unsigned char> > vectorBody;
    };
}