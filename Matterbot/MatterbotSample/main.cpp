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

#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() {
  wstring mattermost_url = L"https://hooks.slack.com",
    incoming_hook_route = L"X",
    outgoing_hook_route = L"http://127.0.0.1:8000/",
    outgoing_hook_token = L"X",
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
	bot->register_command(make_shared<challenges>(bot));
	bot->register_command(make_shared<CountCommand>(bot));
    //bot->register_command(make_shared<ReverseCommand>(bot));
    bot->post_message(welcome_message);

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
