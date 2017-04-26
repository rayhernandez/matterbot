#pragma once
#pragma once
#include "Matterbot.h"
#include "cmath"

namespace lospi
{
	struct CalcCommand : ICommand {
		//CalcCommand()
		//{
		//	is_raining = true;
		//}

		std::wstring get_name() override {
			return L"Calculator";
		}

		std::wstring get_help() override {
			//return L"`Calculator [CMD]`:\n`weather rain`: Make it rain\n`weather sunny`: make it sunny\n`weather report`: Print the status";
			return L"`Calculator [CMD]`:Input the formula with two integers separated by an arithmetic operator from one line\n";
			//(e.g., 1 + 1, -8 – 3, 2 * -7, -15 / -4)\n
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text)
			override {

			////auto my_length = user.length();
			////auto other_string = user.substr(10);

			//auto x = 1;
			//auto y = 2;
			//auto solve = 0;
			////auto sum = 0;
			//auto answer = user.substr();

			//if (command_text == L"Add"|| command_text == L"add")
			//{
			//	answer = x + y;
			//	return answer;
			//}
			//else if (command_text == L"Subtract" || command_text == L"subtract")
			//{
			//	answer = x - y;
			//	return answer;
			//}
			//else if (command_text == L"Multiply" || command_text == L"multiply")
			//{
			//	answer = x * y;
			//	return answer;
			//}
			//else if (command_text == L"Divide" || command_text == L"divide")
			//{
			//	answer = (double)x / y;
			//	return answer;
			//}
			//else
			//{
			//	return L"Error: Invalid Input";
			//}
			//return command_text;


			////switch (solve)
			////{
			////case '+':
			////	printf("Sum: %i \n", x + y);
			////	break;
			////case '-':
			////	printf("Difference: %i \n", x - y);
			////	break;
			////case '*':
			////	printf("Product: %i \n", x * y);
			////	break;
			////case '/':
			////	printf("Quotient: %.2lf \n", (double)x / y);
			////	break;
			////default:
			////	return L"Error";
			////	break;
			////}

			////if (command_text == L"sunny") //make it sunny
			////{
			////	is_raining = false;
			////}
			////else if (command_text == L"rain") //make it rain
			////{
			////	is_raining = true;
			////}
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
			////return command_text;
		}
	//private:
	//	bool is_raining;
	};
}
