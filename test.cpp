#include <iostream>
#include "rlutil.h"

int main()
{
	while(true)
	{
		if(kbhit())
		{
			std::cout << "." << std::endl;
			break;
		}
	}
}
