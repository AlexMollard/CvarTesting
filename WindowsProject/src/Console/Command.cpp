#include "Command.h"

Command::Command(std::function<void(std::string_view)> function, std::string_view description) : m_function(std::move(function)), m_description(description)
{
}

void Command::execute(std::string_view value) const
{
	m_function(value);
}

const std::string_view& Command::getDescription() const
{
	return m_description;
}