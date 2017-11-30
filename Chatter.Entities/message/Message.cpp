#include "Message.h"

const str MESSAGE_CONTENT = L"content";
const str MESSAGE_FROM = L"from";
const str MESSAGE_TO = L"to";
const str MESSAGE_TIME = L"time";

namespace Entities
{
	Message::Message(str from, str to, str content)
		:m_from(from), m_to(to), m_content(content), m_timestamp(0)
	{
	}

	Message::Message(str from, str to, str content, time_t timestamp = 0)
		: m_from(from), m_to(to), m_content(content), m_timestamp(timestamp)
	{
	}	

	Message::~Message()
	{
	}

	str Message::GetContent() const
	{
		return this->m_content;
	}

	str Message::GetTimestamp() const
	{
		char buff[200];
		tm t_tm;
		localtime_s(&t_tm, &m_timestamp);
		asctime_s(buff, 200, &t_tm);
		std::string orgString(buff);
		return str(std::wstring(orgString.begin(), orgString.end()));
	}

	str Message::GetFrom() const
	{
		return m_from;
	}

	str Message::GetTo() const
	{
		return m_to;
	}

	web::json::value Message::Serialize()
	{
		web::json::value message;

		message[MESSAGE_CONTENT] = web::json::value(m_content);
		message[MESSAGE_FROM] = web::json::value(m_from);
		message[MESSAGE_TO] = web::json::value(m_to);
		message[MESSAGE_TIME] = web::json::value(m_timestamp);

		return message;
	}

	Message Message::Deserialize(web::json::value message)
	{
		return Message(message[MESSAGE_FROM].as_string(), message[MESSAGE_TO].as_string(),
					   message[MESSAGE_CONTENT].as_string(), message[MESSAGE_TIME].as_integer());
	}

}

