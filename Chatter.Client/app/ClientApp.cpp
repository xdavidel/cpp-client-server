#include "stdafx.h"
#include "../client/Client.h"

inline void WaitForExit()
{
	std::cout << "Press ENTER to exit..." << std::endl;
	std::string line;
	getline(std::cin, line);
}

int wmain(int argc, wchar_t * argv[])
{
	Client client;


	WaitForExit();
	return 0;
}