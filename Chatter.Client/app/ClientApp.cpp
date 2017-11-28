#include "stdafx.h"
#include "../client/Client.h"


const str DEFAULT_PORT = L"34568";
const str LOCAL_HOST = U("http://localhost:");

template<typename T>
inline void Input(str message, T& value)
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


	auto choice = -1;
	do
	{
		system("cls");
		client.PrintMenu();
		Input(L"Select an option: ", choice);

		switch(choice)
		{
			case 1:
				client.GetActiveUsers();
				
				break;
			default:
				break;
		}
		system("pause");
	} while(choice != 0);

	return 0;
}