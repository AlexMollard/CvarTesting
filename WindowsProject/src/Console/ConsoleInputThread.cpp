#include "ConsoleInputThread.h"

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <thread>

ConsoleInputThread::ConsoleInputThread(const CommandManager& commandManager) : m_commandManager(commandManager)
{
}

void ConsoleInputThread::run()
{
	std::string input;
	std::string current_command;
	std::string current_argument;

	while (m_isRunning)
	{
		std::cout << "\033[1;33mEnter Command:\033[0m ";
		std::getline(std::cin, input);

		if (!input.empty())
		{
			// Parse command name and value
			std::istringstream iss(input);
			std::string commandName;
			std::getline(iss, commandName, ' ');

			std::string value;
			std::getline(iss, value);

			// Update current command and argument
			current_command  = commandName;
			current_argument = value;

			// Execute command
			m_commandManager.executeCommand(current_command, current_argument);
		}
	}

	FreeConsole();
}

void ConsoleInputThread::SetIsRunning(bool value)
{
	m_isRunning = value;
}
