#pragma once

namespace efc {
	/*
	An object that may be inherited in order to pass values to other callbacks of the same request
	*/
	class RequestObject {
	public:
		RequestObject() {}
		virtual ~RequestObject() {}
	};
}