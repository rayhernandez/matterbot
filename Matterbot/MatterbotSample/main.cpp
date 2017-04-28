#include "Matterbot.h"
#include <iostream>
#include <sstream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "ReverseCommand.h"
#include "WeatherCommand.h"
#include "CountCommand.h"
//#include "CalcCommand.h"
//#include "ConvertTempCommand.h"
#include "MD5Command.h"
#include "Md5Utilities.h"
#include "ChallengesCommand.h"
#include "ScrapsCommand.h"
#include <windows.h>
#include <vector>
#include <map>
#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() {

  wstring mattermost_url = L"https://hooks.slack.com",
    incoming_hook_route = L"services/T4Z1QAKSS/B4ZVC0Q8K/aYrHIg9uMAIl2xc13Si550NB",
    outgoing_hook_route = L"http://127.0.0.1:8000/",
    outgoing_hook_token = L"q2ihUw3S6RbQhOBUxuEWv7tO",
    welcome_message = L"bot is running.";

  try {
    auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
    bot->set_logger(make_unique<ConsoleLogger>());
    bot->register_command(make_shared<EchoCommand>());
	//bot->register_command(make_shared<ConvertTempCommand>());
	bot->register_command(make_shared<WeatherCommand>());
	//bot->register_command(make_shared<CalcCommand>());
	bot->register_command(make_shared<md5Command>());
	//bot->register_command(make_shared<challenges>());
	bot->register_command(make_shared<ChallengesCommand>(bot));
	bot->register_command(make_shared<ScrapsCommand>(bot));
	bot->register_command(make_shared<CountCommand>(bot));
    //bot->register_command(make_shared<ReverseCommand>(bot));
    bot->post_message(welcome_message);

	std::map<Md5Digest, std::vector<char>> createMap();	//map insertion

	//if (lookup.empty())
	//{
		std::string alpha = "josh";
		std::string myPass = "nbiass";

		for (size_t i = 0; i <= 13; i++)
		{
			Combinator c{ alpha, (i) };
			while (c.has_next())
			{
				auto combo = c.next();
				//std::string x{ combo.begin(), combo.end() };
				std::copy(myPass.begin(), myPass.end(), back_inserter(combo)); //appends the password to combo
				//x.append("5sr1di");		//append the password to combo
				auto md5_Preimage = compute_md5(combo.data(), (unsigned long) combo.size());
				lospi::lookup.emplace(md5_Preimage, combo);
			}
		}
	//}
	std::cout << "lookup table is ready";
	bot->post_message(L"lookup table is ready");

    wstring console;
    wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;
    while (getline(wcin, console)) {
      if (L"quit" == console) {
        wclog << ">> Quitting." << endl;
        return ERROR_SUCCESS;
      }
      if (L"" != console) { bot->post_message(console); }
    }
  }
  catch (exception e) {
    wcerr << "[-] Unhandled exception:" << e.what() << endl;
    return ERROR_FAILURE;
  }
}
