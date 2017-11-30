#include "Client.h"
#include "../../Chatter.Entities/user/User.h"

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
	Entities::User user(username, password);
	
	// create post parameters for the body (as json). 
	web::json::value postParameters = user.Serialize();
	//web::json::value postParameters;

	/*postParameters[L"username"] = web::json::value(username);
	postParameters[L"password"] = web::json::value(password);*/

	auto response = HttpPostRequest(L"/login", postParameters);

	if(response.status_code() == status_codes::OK)
	{
		return true;
	}

	return false;
}

vector<str> Client::HttpClient::GetActiveUsers()
{
	vector<str> users;

	web::json::value postParameters;

	web::json::value arr = web::json::value::array();
	arr[0] = web::json::value(L"moshe");

	auto response = HttpPostRequest(L"/getActiveUser", postParameters);

	if(response.status_code() == status_codes::OK)
	{
		auto content = response.extract_json().get();
		auto bodyArr = content.as_array();
		
		for(auto iter = bodyArr.begin(); iter != bodyArr.end(); ++iter)
		{
			auto& user = *iter;
			users.push_back(user.as_string());
		}
	}

	return users;
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

http_response Client::HttpClient::HttpPostRequest(str path, web::json::value data)
{
	auto fullpath = m_baseAddress + path;

	web::http::http_request postRequest(web::http::methods::POST);
	postRequest.headers().add(L"Content-Type", L"application/json");
	postRequest.headers().add(L"X-Requested-With", L"XMLHttpRequest");

	postRequest.set_body(data);

	http_response retVal;

	web::http::client::http_client client(fullpath);
	client.request(postRequest).then([&](http_response response){
		retVal = response;
	}).wait();

	return retVal;
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
