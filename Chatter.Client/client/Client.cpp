#include "Client.h"

using namespace web::http;

Client::HttpClient::HttpClient(str address, str port)
	: m_baseAddress(address.append(port))
{
	m_menu.emplace(std::make_pair(1, MenuItem(L"Get Active Users")));
	m_menu.emplace(std::make_pair(2, MenuItem(L"Send Private Message")));
	m_menu.emplace(std::make_pair(3, MenuItem(L"Send Group Message")));
	m_menu.emplace(std::make_pair(4, MenuItem(L"Ban User")));
	m_menu.emplace(std::make_pair(5, MenuItem(L"Unban User")));
	m_menu.emplace(std::make_pair(6, MenuItem(L"Get Pending Messages")));
	m_menu.emplace(std::make_pair(0, MenuItem(L"Exit")));

}


Client::HttpClient::~HttpClient()
{
}

bool Client::HttpClient::Login(str username, str password)
{
	return true;
}

str Client::HttpClient::GetActiveUsers()
{
	return str();
}

str Client::HttpClient::GetMessage(str fromUser)
{
	return str();
}

bool Client::HttpClient::Send(str fromUser, str toUser, str message)
{
	return false;
}

bool Client::HttpClient::SendAll()
{
	return false;
}

bool Client::HttpClient::Ban(str username)
{
	return false;
}

bool Client::HttpClient::Unban(str username)
{
	return false;
}

void Client::HttpClient::PrintMenu()
{
	std::cout << "Menu" << std::endl;
	std::cout << "----------------------------" << std::endl;

	for(auto it = m_menu.begin(); it != m_menu.end(); it++)
	{
		std::cout << it->first;
		it->second.Display();
	}
}
