#include "Request.hpp"

#include <cpprest/http_msg.h>

namespace efc {
	Request::Request(web::http::http_request req) {
		this->req = req;
	}
	Request::~Request() {

	}

	void Request::reply(web::http::status_code status) {
		this->req.reply(status);
	}
}