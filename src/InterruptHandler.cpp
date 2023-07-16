#include "InterruptHandler.hpp"
#include <signal.h>

namespace efc {
	std::condition_variable InterruptHandler::interruptCondition;
	std::mutex InterruptHandler::mutex;

	void InterruptHandler::waitForInterrupt() {
		signal(SIGINT, onSignal);

		std::unique_lock<std::mutex> lock(InterruptHandler::mutex);
		InterruptHandler::interruptCondition.wait(lock);

		lock.unlock();
	}

	void InterruptHandler::onSignal(int _signal) {
		if (_signal != SIGINT) return;
		
		InterruptHandler::interruptCondition.notify_one();
	}
}