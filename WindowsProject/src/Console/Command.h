#pragma once
#include <functional>
#include <string>

class Command
{
public:
	Command(std::function<void(std::string_view)> function, std::string_view description = "");

	void execute(std::string_view value) const;
	const std::string_view& getDescription() const;

private:
	std::function<void(std::string_view)> m_function;
	std::string m_description;
};
