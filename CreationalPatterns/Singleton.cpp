/*
The Idea:

Singleton is a class that has only one instance and cannot be copied. Usually is used 
as some manager that exists during the entire execution.

P.S. You can separate instance creation from GetInstance if you want to.

*pseudocode*

Singleton::GetInstace()->DoSomething(); // During the execution
...
...
...
Singleton::DestroyInstance(); // In the end of the programm
*/

#include <iostream>
#include <string>


class Singleton
{
	Singleton(Singleton const&) = delete;
	Singleton& operator= (Singleton const&) = delete;

	Singleton()
	{

	}

protected:
	static Singleton* _instance;

public:

	static Singleton* GetInstance()
	{
		if (!_instance)
		{
			_instance = new Singleton();
		}

		return _instance;
	}

	static void DestroyInstance()
	{
		delete _instance;
	}

	void Print()
	{
		std::cout << "Text from the instance";
	}
};

Singleton* Singleton::_instance = nullptr;

int main()
{
	Singleton::GetInstance()->Print();
	std::cin.get();
	Singleton::DestroyInstance();
	return 0;
}