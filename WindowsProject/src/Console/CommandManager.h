#pragma once

#include <map>
#include <string>
#include <string_view>
#include <vector>
#include "Command.h"

class CommandManager
{
public:
	CommandManager();

	void registerCommand(std::string_view name, const Command& command);
	void emplace(std::string_view name, const Command& command);
	void executeCommand(std::string_view commandName, const std::string& value) const;

	std::vector<std::string> getCommandNames() const;
	std::vector<std::string> getCommandCompletions(const std::string& partialCommand) const;

private:
	std::map<std::string_view, Command> basicCommands;
	std::map<std::string_view, Command> userCommands;

	void registerBasicCommand(std::string_view name, const Command& command);
	void printCommands() const;
	void printCommandMap(const std::string& title, const std::map<std::string_view, Command>& commandMap) const;
};
