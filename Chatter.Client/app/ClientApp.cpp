#include "stdafx.h"
#include "../client/Client.h"


const str DEFAULT_PORT = L"34568";
const str LOCAL_HOST = U("http://localhost:");

inline void PromptExit(std::string message)
{
	std::cin.clear();
	std::cin.ignore(INT_MAX);
	std::cout << message << std::endl;
	std::string line;
	getline(std::cin, line);
}

inline void Input(str message, str& value)
{
	std::wcout << message;
	wcin >> value;
}



int wmain(int argc, wchar_t * argv[])
{
	str address = argc == 3 ? argv[1] : LOCAL_HOST;
	str port = argc == 3 ? argv[2] : DEFAULT_PORT;
	bool connected = false;

	Client::HttpClient client(address, port);

	str username;
	str password;

	do
	{
		system("cls");

		Input(L"Enter Username: ", username);
		Input(L"Enter Password: ", password);

		connected = client.Login(username, password);
		
	} while(!connected);

	
	return 0;
}