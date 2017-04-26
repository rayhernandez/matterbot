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


			std::map<Md5Digest, std::string> list;	//map insertion

			for (unsigned long i = 0; i < 10; i++)
			{
				Combinator c{ "hosj", i };
				c.next(); //return 'h', 'h', 'h', 'h', 'h'
				c.next(); //return 'h', 'h', 'h', 'h', 's'

				while (c.has_next())
				{
					auto combo = c.next();

					std::string x{ combo.begin(), combo.end() };
					
					x.append("op0y21");		//append the password to combo

					auto md5 = compute_md5(x.data(), (unsigned long)x.size());

					list.emplace(md5,x);

				}
			}

			/*
			Md5Digest hash;
			auto result = lookup.find(hash);
			if (result == lookup.end())
			{
				//Key not found!
			}
			*/




		//private:
		//	bool is_raining;
		};
	};
}

