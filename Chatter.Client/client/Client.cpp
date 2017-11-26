#include "Client.h"

using namespace web::http;

Client::Client()
{
}


Client::~Client()
{
}

bool Client::Login(String username, String password)
{
	return false;
}

String Client::GetActiveUsers()
{
	return String();
}

String Client::GetMessage(String fromUser)
{
	return String();
}

bool Client::Send(String fromUser, String toUser, String message)
{
	return false;
}

bool Client::SendAll()
{
	return false;
}

bool Client::Ban(String username)
{
	return false;
}

bool Client::Unban(String username)
{
	return false;
}
