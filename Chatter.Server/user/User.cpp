#include "User.h"

Server::User::User()
{}

Server::User::User(utility::string_t username, utility::string_t password)
	: m_name(username), m_pass(password)
{}

Server::User::~User()
{}

bool Server::User::SetPassword(utility::string_t newPassword)
{
	// Todo: check for password restrictions
	this->m_pass.assign(newPassword);
	return true;
}

utility::string_t Server::User::GetUsername() const
{
	return m_name;
}

std::vector<utility::string_t> Server::User::GetBannedUsers() const
{
	return std::vector<utility::string_t>();
}

void Server::User::AddBannedUser(utility::string_t username)
{
	this->m_bannedUserList.push_back(username);
}

void Server::User::RemoveBannedUser(utility::string_t username)
{
	std::vector<size_t> indexesToDelete;

	for(size_t i = 0; i < this->m_bannedUserList.size(); i++)
	{
		if(m_bannedUserList[i] == username)
		{
			indexesToDelete.push_back(i);
		}
	}

	for(size_t i = 0; i < indexesToDelete.size(); i++)
	{
		this->m_bannedUserList.erase(m_bannedUserList.begin() + indexesToDelete[i]);
	}
}

bool Server::User::IsBanned(utility::string_t username)
{
	for(size_t i = 0; i < this->m_bannedUserList.size(); i++)
	{
		if(this->m_bannedUserList[i] == username)
		{
			return true;
		}
	}

	return false;
}
