#include "Timer.h"

#include <memory>
#include <array>

int main()
{
	int value = 0;
	
	//Timing example 1
	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
		{
			value += 2;
		}
	}
	
	std::cout << value << std::endl;


	//Timing example 2
	struct vector2
	{
		int x;
		int y;
	};

	std::cout << "Make Shared: " << std::endl;
	{
		std::array<std::shared_ptr<vector2>, 1000> sharedPtr;
		Timer time;
		for (int i = 0; i < sharedPtr.size(); i++)
		{
			sharedPtr[i] = std::make_shared<vector2>();
		}
	}
	
	std::cout << "New Shared: " << std::endl;
	{
		std::array<std::shared_ptr<vector2>, 1000> sharedPtr;
		Timer time;
		for (int i = 0; i < sharedPtr.size(); i++)
		{
			sharedPtr[i] = std::shared_ptr<vector2>(new vector2());
		}
	}
	
	std::cout << "Make Unique: " << std::endl;
	{
		std::array<std::unique_ptr<vector2>, 1000> sharedPtr;
		Timer time;
		for (int i = 0; i < sharedPtr.size(); i++)
		{
			sharedPtr[i] = std::make_unique<vector2>();
		}
	}
}