#include "User.h"

const str USER_NAME = L"username";
const str USER_PASSWORD = L"password";

namespace Entities
{
	User::User()
	{
	}

	User::User(str username, str password)
		: m_name(username), m_pass(password)
	{
	}

	User::~User()
	{
	}

	bool User::SetPassword(str newPassword)
	{
		// Todo: check for password restrictions
		this->m_pass.assign(newPassword);
		return true;
	}

	str User::GetUsername() const
	{
		return m_name;
	}

	std::vector<str> User::GetBannedUsers() const
	{
		return std::vector<str>();
	}

	void User::AddBannedUser(str username)
	{
		this->m_bannedUserList.push_back(username);
	}

	void User::RemoveBannedUser(str username)
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

	bool User::IsBanned(str username)
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

	web::json::value User::Serialize()
	{
		web::json::value user;
		
		user[USER_NAME] = web::json::value(m_name);
		user[USER_PASSWORD] = web::json::value(m_pass);

		return user;
	}

	User User::Deserialize(web::json::value user)
	{
		return User(user[USER_NAME].as_string(), L"Hidden");
	}

}
