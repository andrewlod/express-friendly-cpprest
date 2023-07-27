#include "ErrorHandlers.hpp"

#include <efc/Request.hpp>
#include <cpprest/http_msg.h>

#include <exception>
#include <iostream>

void onError(efc::Request& req) {
	std::exception_ptr ex = std::current_exception();
	try {
		std::rethrow_exception(ex);
	}
	catch (std::out_of_range& e) {
		std::cout << "An exception occurred: " << e.what() << std::endl;
		req.reply(web::http::status_codes::InternalError, "Somewhing went wrong!");
	}
}