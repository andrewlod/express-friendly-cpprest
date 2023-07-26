#include "Request.hpp"

#include <cpprest/http_msg.h>

#include <memory>
#include <vector>

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

	std::shared_ptr<web::json::value> Request::get_json(bool ignore_content_type) {
		if (this->jsonBody == nullptr && this->stringBody == nullptr && this->vectorBody == nullptr)
			this->jsonBody = std::make_shared<web::json::value>(this->req.extract_json(ignore_content_type).get());

		return this->jsonBody;
	}

	std::shared_ptr<utility::string_t> Request::get_string(bool ignore_content_type) {
		if (this->jsonBody == nullptr && this->stringBody == nullptr && this->vectorBody == nullptr)
			this->stringBody = std::make_shared<utility::string_t>(this->req.extract_string(ignore_content_type).get());

		return this->stringBody;
	}

	std::shared_ptr<std::vector<unsigned char> > Request::get_vector() {
		if (this->jsonBody == nullptr && this->stringBody == nullptr && this->vectorBody == nullptr)
			this->vectorBody = std::make_shared<std::vector<unsigned char> >(this->req.extract_vector().get());

		return this->vectorBody;
	}

	void Request::add_attribute(const std::string& key, std::shared_ptr<RequestObject> value) {
		this->attributes[key] = value;
	}

	std::shared_ptr<RequestObject> Request::get_attribute(const std::string& key) {
		return this->attributes[key];
	}
}