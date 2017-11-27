#include "Client.h"

using namespace web::http;

Client::Client()
{
}


Client::~Client()
{
}

bool Client::Login(utility::string_t username, utility::string_t password)
{
	return false;
}

utility::string_t Client::GetActiveUsers()
{
	return utility::string_t();
}

utility::string_t Client::GetMessage(utility::string_t fromUser)
{
	return utility::string_t();
}

bool Client::Send(utility::string_t fromUser, utility::string_t toUser, utility::string_t message)
{
	return false;
}

bool Client::SendAll()
{
	return false;
}

bool Client::Ban(utility::string_t username)
{
	return false;
}

bool Client::Unban(utility::string_t username)
{
	return false;
}
