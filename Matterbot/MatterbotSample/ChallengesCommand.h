#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include "Md5.h"
#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace lospi {
	std::map<Md5Digest, std::vector<char>> lookup;
	std::vector<std::string> getNewChallenges;
	std::wstring returnValue;

	struct ChallengesCommand : ICommand {
		explicit ChallengesCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"challenges"; }

		std::wstring get_help() override { return L"`challenges[CMD]`: `challenges` computes the hashes"; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			auto strLen = (command_text.size());

			while (strLen) {
				std::stringstream ss;
				std::string text = wstring_to_string(command_text);
				ss.str(text);
				std::string str;
				getNewChallenges.clear();

			while (std::getline(ss, str, ' ')) {
				getNewChallenges.push_back(str);
				}
				inputHash();
				bot->post_message(L"rivestment try " + returnValue);
				Sleep(2000);
				bot->post_message(L"rivestment challenge 200");
				return L"";
			}
		}

void inputHash() 
{
	std::vector<std::wstring> hashVector;
	hashVector.clear();
	std::wstring hash;
	auto newStrLen = (getNewChallenges.size());

	for (int i = 0; i < newStrLen; i++) {
		auto challengeStr = getNewChallenges[i];
		auto result = lookup[get_md5_from_str(string_to_wstring(challengeStr))];
		std::wstring hash(result.begin(), result.end());
		hashVector.emplace_back(hash);
	}
	returnValue.clear();
	for (int i = 0; i < hashVector.size(); i++) {
		returnValue += hashVector[i] + L" ";
	}
	returnValue.pop_back();
}

	private:
		std::shared_ptr<Matterbot> bot;
		std::shared_ptr<ChallengesCommand> challenges;
	};
}