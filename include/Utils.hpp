#pragma once

#include <cpprest/asyncrt_utils.h>

#include <queue>
#include <string>

namespace efc {
	/*
	Splits the path by '/' and transforms it into a queue.
	*/
	std::queue<utility::string_t> splitPath(const utility::string_t& path);
}