#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct WeatherCommand : ICommand {
		WeatherCommand()
		{
			is_raining = true;
		}

		std::wstring get_name() override {
			return L"weather";
		}

		std::wstring get_help() override {
			return L"`weather [CMD]`:\n`weather rain`: Make it rain\n`weather sunny`: make it sunny\n`weather report`: Print the status";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text)
			override {
			
			auto my_length = user.length();
			auto other_string = user.substr(10);

			if (command_text == L"sunny") //make it sunny
			{
				is_raining = false;
			}
			else if (command_text == L"rain") //make it rain
			{
				is_raining = true;
			}
			else if (command_text == L"report") //get the report
			{
				if (is_raining)
				{
					return L"get your umbrella";
				}
				else
				{
					return L"Put yer sunglasses on";
				}
			}
			return command_text;
		}
	private: 
			bool is_raining;
	};
}
