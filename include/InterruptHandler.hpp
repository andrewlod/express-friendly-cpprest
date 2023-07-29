#pragma once

#include <signal.h>
#include <condition_variable>
#include <mutex>

namespace efc {
	class InterruptHandler {
	public:
		/*
		Waits until an interrupt signal is triggered
		*/
		static void waitForInterrupt();
		static void onSignal(int signal);
	private:
		InterruptHandler() = default;

		static std::condition_variable interruptCondition;
		static std::mutex mutex;
	};
}