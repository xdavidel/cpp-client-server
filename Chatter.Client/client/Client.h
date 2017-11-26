#pragma once
#include "../app/stdafx.h"

using namespace std;

class Client
{
private:
	const String SERVER = L"server";
	const int PORT = 1234;

	String m_username;
	String m_password;
public:
	Client();
	~Client();

	bool Login(String username, String password);	// login?username=<username>&password=<password>
	String GetActiveUsers();	// getActiveUser
	String GetMessage(String fromUser);	// getMessages?username=<username>
	bool Send(String fromUser, String toUser, String message);	// send?username=<username>&massege=<massege>
	bool SendAll();	// sendAll?username=<username>&massege=<massege>
	bool Ban(String username);		// banUser
	bool Unban(String username);	// unbanUser
};

