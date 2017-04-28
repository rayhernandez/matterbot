#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include "Md5.h"
//#include "LookupMap.h"
#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


namespace lospi {
	//std::map<Md5Digest, std::vector<char>> lookup;
	std::vector<std::string> scraps_getNewChallenges;
	std::wstring scraps_returnValue;

	struct ScrapsCommand : ICommand {
		explicit ScrapsCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"scraps"; }

		std::wstring get_help() override { return L"`scraps[CMD]`: `scraps` unsolved hashes"; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			auto scraps_strLen = (command_text.size());

			while (scraps_strLen) {
				std::stringstream ss;
				std::string text = wstring_to_string(command_text);
				ss.str(text);
				std::string scraps_str;
				scraps_getNewChallenges.clear();

				while (std::getline(ss, scraps_str, ' ')) {
					scraps_getNewChallenges.push_back(scraps_str);
				}
				scraps_inputHash();
				bot->post_message(L"rivestment try " + scraps_returnValue);
				Sleep(2000); //_sleep(2000);
				bot->post_message(L"rivestment challenge 10");
				return L"";
			}
		}

		void scraps_inputHash()
		{
			std::vector<std::wstring> scraps_hashVector;
			scraps_hashVector.clear();
			std::wstring hash;
			auto newStrLen = (scraps_getNewChallenges.size());

			for (int i = 0; i < newStrLen; i++) {
				auto scraps_challengeStr = scraps_getNewChallenges[i];
				auto scraps_result = lookup[get_md5_from_str(string_to_wstring(scraps_challengeStr))];
				std::wstring scraps_hash(scraps_result.begin(), scraps_result.end());
				scraps_hashVector.emplace_back(scraps_hash);
			}
			scraps_returnValue.clear();
			for (int i = 0; i < scraps_hashVector.size(); i++) {
				scraps_returnValue += scraps_hashVector[i] + L" ";
			}
			scraps_returnValue.pop_back();
		}

	private:
		std::shared_ptr<Matterbot> bot;
		std::shared_ptr<ScrapsCommand> scraps;
	};
}