/*
The Idea:

We have some object that can do something, but do not have concrete alghoritm. This alghoritm is
incapsulated inside some class we call Strategy, by assigning the concrete strategies to our object
we can perform different alghoritms without changing the program flow.

*pseudocode*

object->SetConcreteStrategy(PointerToConcreteStrategy);
object->UseConcreteStrategy();
*/

#include <iostream>
#include <vector>

class AbstractStrategy
{
public:

	virtual void Use() = 0;
};

class Strategy1 : public AbstractStrategy
{
public:
	virtual void Use()
	{
		std::cout << "Strategy1 working" << std::endl;
	}
};

class Strategy2 : public AbstractStrategy
{
	virtual void Use()
	{
		std::cout << "Strategy2 working" << std::endl;
	}
};

class AbstractWorker
{
protected:
	AbstractStrategy* _strategy;

public:

	AbstractWorker() : _strategy(nullptr)
	{}

	void SetStrategy(AbstractStrategy* strategy)
	{
		if (_strategy)
		{
			delete _strategy;
		}

		_strategy = strategy;
	}

	void UseStrategy()
	{
		_strategy->Use();
	}

	~AbstractWorker()
	{
		delete _strategy;
	}
};

class Worker : public AbstractWorker
{

};

int main()
{
	Worker someWorker;
	someWorker.SetStrategy(new Strategy1());
	someWorker.UseStrategy();
	someWorker.SetStrategy(new Strategy2());
	someWorker.UseStrategy();

	std::cin.get();
	return 0;
}
