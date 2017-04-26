#pragma once
#include "Matterbot.h"
#include <string>

namespace lospi
{
	struct ConvertTempCommand : ICommand {
		////ConvertTempCommand()
		////{
		////	is_raining = true;
		////}

		std::wstring get_name() override {
			return L"ConvertTemp";
		}

		std::wstring get_help() override {
			return L"`ConvertTemp [CMD]`:\n`ConvertTemp F`: Convert Fahrenheit to Celsius\n`ConvertTemp C`: Convert Celsius to Fahrenheit";
			//This program will convert between Fahrenheit and Celsius or Celsius and Fahrenheit \n
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text)
			override {

			auto my_length = user.length();
			auto other_string = user.substr(10);

			//auto userInput = command_text.substr(256);
			wchar_t userInput[256];
			auto returnValue = command_text.substr(256);

			if (command_text == L"F") //convert Temp
			{
				////////returnValue = ((command_text.substr*1.8) + 32);
				std::wcstoul(userInput, NULL, 0);
				returnValue = std::to_string((command_text.substr*1.8) + 32);
				return returnValue;
				////double fahrenheit_temp;
				////std::wcin >> fahrenheit_temp;
				////double celsius_temp = (fahrenheit_temp - 32) * 5.0 / 9.0;
				////std::wcout << "Expected output: The equivalent Celsius temperature is " << celsius_temp << " degrees." << std::endl;
				////return command_text;
			}
			else if (command_text == L"C") //make it rain
			{
				////////returnValue = ((command_text.substr - 32) * .5556);
				std::wcstoul(userInput, NULL, 0);
				returnValue = std::to_string((command_text.substr - 32) * .5556);
				return returnValue;
				////double celsius_temp;
				////std::wcin >> celsius_temp;
				////double fahrenheit_temp = (celsius_temp - 32) * 5.0 / 9.0;
				////std::wcout << "Expected output: The equivalent Fahrenheit temperature is " << fahrenheit_temp << " degrees." << std::endl;
				////return command_text;
			}
			////else if (command_text == L"report") //get the report
			////{
			////	if (is_raining)
			////	{
			////		return L"get your umbrella";
			////	}
			////	else
			////	{
			////		return L"Put yer sunglasses on";
			////	}
			////}
			return command_text;
		}
	};
}
