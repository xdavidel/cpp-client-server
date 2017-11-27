#pragma once
#include "../app/stdafx.h"

using namespace std;

class Client
{
private:
	const utility::string_t SERVER = L"server";
	const int PORT = 1234;

	utility::string_t m_username;
	utility::string_t m_password;
public:
	Client();
	~Client();

	bool Login(utility::string_t username, utility::string_t password);	// login?username=<username>&password=<password>
	utility::string_t GetActiveUsers();	// getActiveUser
	utility::string_t GetMessage(utility::string_t fromUser);	// getMessages?username=<username>
	bool Send(utility::string_t fromUser, utility::string_t toUser, utility::string_t message);	// send?username=<username>&massege=<massege>
	bool SendAll();	// sendAll?username=<username>&massege=<massege>
	bool Ban(utility::string_t username);		// banUser
	bool Unban(utility::string_t username);	// unbanUser
};

