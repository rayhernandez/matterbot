#pragma once
#include "Matterbot.h"
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <string>

namespace lospi {
	struct CountCommand : ICommand {
		explicit CountCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"count"; }

		std::wstring get_help() override { return L"`count [MESSAGE]`: `count` will respond with the string length of the message."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
									const std::wstring& user, const std::wstring& command_text) override {
			bot->post_message(command_text);
			auto numOfChars{command_text};
			//NumOfChars.length();
			//////for (std::size_t numOfChars = 0, length = command_text.length(); numOfChars != length; ++numOfChars);
			//////{
			//////	return numOfChars;
			//////}
			////for (int i = 0; command_text[i] != '\0'; i++)
			////{
			////	numOfChars++;
			////}
			//gets(command_text);

			//wstring numOfChars(command_text);
			//distance(numOfChars.begin(), numOfChars.end());
			std::wstring str(command_text);
			//distance(numOfChars.begin(), numOfChars.end());
			//std::cout << "The size of str is " << str.length() << " characters.\n";
			//numOfChars = command_text.length();
			//return numOfChars;
			//return L"The size of str is " << str.length() << " characters.\n";
			//numOfChars = str.length();
			//numOfChars = std::wstring << "The size of str is " << str.length() << " characters.\n";
			//numOfChars = str.length();
			return numOfChars;
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}