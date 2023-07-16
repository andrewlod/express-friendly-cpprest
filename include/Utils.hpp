#pragma once

#include <cpprest/asyncrt_utils.h>

#include <queue>
#include <string>

namespace efc {
	std::queue<utility::string_t> splitPath(const utility::string_t& path);
}