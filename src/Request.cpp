#include "Request.hpp"

#include <cpprest/http_msg.h>

namespace efc {
	Request::Request(web::http::http_request req) {
		this->req = req;
	}
	Request::~Request() {

	}

	void Request::reply(web::http::status_code status, const concurrency::streams::istream& body, utility::size64_t content_length, const utility::string_t& content_type) const {
		this->req.reply(status, body, content_length, content_type).wait();
	}

	void Request::reply(web::http::status_code status, const concurrency::streams::istream& body, const utility::string_t& content_type) const {
		this->req.reply(status, body, content_type).wait();
	}

	void Request::reply(web::http::status_code status, const utf16string& body_data, const utf16string& content_type) const {
		this->req.reply(status, body_data, content_type).wait();
	}

	void Request::reply(web::http::status_code status, utf8string&& body_data, const utf8string& content_type) const {
		this->req.reply(status, body_data, content_type).wait();
	}

	void Request::reply(web::http::status_code status, const web::json::value& body_data) const {
		this->req.reply(status, body_data).wait();
	}

	void Request::reply(web::http::status_code status) const {
		this->req.reply(status).wait();
	}

	void Request::reply(const web::http::http_response& response) const {
		this->req.reply(response).wait();
	}

	web::json::value Request::extract_json(bool ignore_content_type) const {
		return this->req.extract_json(ignore_content_type).get();
	}

	utility::string_t Request::extract_string(bool ignore_content_type) {
		return this->req.extract_string(ignore_content_type).get();
	}

	utf8string Request::extract_utf8string(bool ignore_content_type) {
		return this->req.extract_utf8string(ignore_content_type).get();
	}

	utf16string Request::extract_utf16string(bool ignore_content_type) {
		return this->req.extract_utf16string(ignore_content_type).get();
	}

	std::vector<unsigned char> Request::extract_vector() const {
		return this->req.extract_vector().get();
	}

	void Request::add_attribute(const std::string& key, std::shared_ptr<RequestObject> value) {
		this->attributes[key] = value;
	}

	std::shared_ptr<RequestObject> Request::get_attribute(const std::string& key) {
		return this->attributes[key];
	}
}