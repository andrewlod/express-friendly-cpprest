#include "Utils.hpp"

#include <cpprest/uri.h>
#include <queue>
#include <vector>
#include <string>

namespace efc {
	std::queue<utility::string_t> splitPath(const utility::string_t& path) {
		std::vector<utility::string_t> pathVector = web::uri::split_path(path);
		std::queue<utility::string_t> pathQueue (std::deque<utility::string_t>(pathVector.begin(), pathVector.end()));
		return pathQueue;
	}
}