#pragma once
#include "../app/stdafx.h"
#include "../menu/MenuItem.h"

using namespace std;

namespace Client
{
	class HttpClient
	{
	public:
		HttpClient(str address, str port);
		~HttpClient();

		bool Login(str username, str password);
		vector<str> GetActiveUsers();	// getActiveUser
		str GetMessage(str fromUser);	// getMessages?username=<username>
		bool Send(str fromUser, str toUser, str message);	// send?username=<username>&massege=<massege>
		bool SendAll();	// sendAll?username=<username>&massege=<massege>
		bool Ban(str username);		// banUser
		bool Unban(str username);	// unbanUser
		void PrintMenu();

	private:
		web::http::http_response HttpPostRequest(str path, web::json::value data);

		str m_username;
		str m_password;
		str m_baseAddress;
		unordered_map<size_t, MenuItem> m_menu;
	};
	
}



