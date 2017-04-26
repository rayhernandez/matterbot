#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>


namespace lospi {
	struct challenges : ICommand {
		explicit challenges(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"scraps"; }

		std::wstring get_help() override { return L"`scraps [hashes]`: `challenges`it starts a challenge"; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

/*
namespace lospi
{
	struct challenges : ICommand {

		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			return L"`challenges [CMD]`:\n`it starts a challenge";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text)
			override {
*/

			Md5Digest md5_str;
			//Md5Digest hash;

			auto md5_string = wstring_to_string(command_text);

			auto *data = md5_string.c_str();
			auto size = md5_string.size();

			md5_str = compute_md5(data, (unsigned long)size);
			auto md5Digest = get_str_from_md5(md5_str);

			//std::cout << "Expected Result: Md5 " << get_str_from_md5(md5_str) << "\n";

			return L"MD5 " + get_str_from_md5(md5_str);


			std::map<Md5Digest, std::string> lookup;	//map insertion
			
			auto result = lookup.find(md5_str);
			if (result == lookup.end())
			{
				return L"Error";	//BAD / Key not found!
			}
									//Result is valid pair or pare
			auto key = result->first;
			auto value = result->second;
			
			auto key_string = wstring_to_string(command_text);
			auto key_data = key_string.c_str();
			auto key_size = key_string.size();

			std::wstringstream ss(command_text);
			while (std::getline(ss, ' '))

			if (key == compute_md5(key_data, key_size))
			{
				//string_to_wstring(value);
				return L"rivestment try" + string_to_wstring(value);
			}


			bot->post_message(command_text);
			

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

					auto md5_Preimage = compute_md5(x.data(), (unsigned long)x.size());

					lookup.emplace(md5_Preimage, x);

				}
			}

		};
	private:
		std::shared_ptr<Matterbot> bot;
		//	bool is_raining;
	};
}