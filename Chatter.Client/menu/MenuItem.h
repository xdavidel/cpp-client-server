#include "../app/stdafx.h"

class MenuItem
{
public:
	MenuItem();
	MenuItem(str header);
	MenuItem(str header, std::function<void()> action);
	~MenuItem();

	void Display();
	void SetAction(std::function<void()> action);
	void Run();

private:
	str m_header;
	std::function<void()> m_action;
};

