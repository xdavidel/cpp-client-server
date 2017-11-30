#pragma once
#include "../app/stdafx.h"

namespace Entities
{
	/**
	Contains user details and bun list of usernames 
	*/
	class User
	{
	public:
		User();
		User(utility::string_t, utility::string_t);
		~User();

		bool SetPassword(utility::string_t);
		utility::string_t GetUsername() const;
		std::vector<utility::string_t> GetBannedUsers() const;
		void AddBannedUser(utility::string_t username);
		void RemoveBannedUser(utility::string_t username);
		bool IsBanned(utility::string_t username);

		web::json::value Serialize();
		static User Deserialize(web::json::value user);

	private:
		utility::string_t m_name;
		utility::string_t m_pass;
		std::vector<utility::string_t> m_bannedUserList;
	};
}

