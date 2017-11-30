#pragma once
#include "../app/stdafx.h"

namespace Entities
{
	/**
	Contains message details
	*/
	class Message
	{
	public:
		Message(str from, str to, str content);
		~Message();

		str GetContent() const;
		str GetTimestamp() const;
		str GetFrom() const;
		str GetTo() const;

		web::json::value Serialize();
		static Message Deserialize(web::json::value user);
	private:
		Message(str from, str to, str content, time_t timestamp);
		str m_content;
		str m_from;
		str m_to;
		time_t m_timestamp;
	};
}
