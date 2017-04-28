#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <map>
//#include <string>
//#include <iostream>

namespace lospi
{
	struct md5Command : ICommand {

		std::wstring get_name() override {
			return L"md5";
		}

		std::wstring get_help() override {
			return L"`md5 [CMD]`:\n`md5 hash`: abcd1234";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text)
			override {


			//auto data = command_text.substr(10);
			//auto size = command_text.length();

			//const char data = *command_text.c_str();
			//auto data = *command_text.c_str();
			//unsigned long size = command_text.size();
			//auto size = command_text.size();

			Md5Digest md5_str;
			//Md5Digest hash;

			auto md5_string = wstring_to_string(command_text);

			auto *data = md5_string.c_str();
			auto size = md5_string.size();

			md5_str = compute_md5(data, (unsigned long)size);
			auto md5Digest = get_str_from_md5(md5_str);

			//std::cout << "Expected Result: Md5 " << get_str_from_md5(md5_str) << "\n";

			return L"MD5 " + get_str_from_md5(md5_str);

		//private:
		//	bool is_raining;
		};
	};
}

