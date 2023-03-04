#pragma once
#include "CommandManager.h"

#include <atomic>
class ConsoleInputThread
{
public:
	ConsoleInputThread(const CommandManager& commandManager);;

	void run();
	void SetIsRunning(bool value);

private:
	CommandManager m_commandManager;
	std::atomic<bool> m_isRunning = true;
};
