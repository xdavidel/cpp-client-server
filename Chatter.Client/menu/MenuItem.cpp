#include "MenuItem.h"

MenuItem::MenuItem()
{}

MenuItem::MenuItem(str header)
	: m_header(header)
{}

MenuItem::MenuItem(str header, std::function<void()> action)
	: m_header(header), m_action(action)
{}

MenuItem::~MenuItem()
{
}

void MenuItem::Display()
{
	std::wcout << " - " << m_header << std::endl;
}

void MenuItem::SetAction(std::function<void()> action)
{
	m_action = action;
}

void MenuItem::Run()
{
	if(m_action != nullptr)
	{
		m_action();
	}
}