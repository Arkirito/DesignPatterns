/*
The Idea:

We know that at certain place we may call some method, but at abstract level we do not need anything specific there so we just leave it empty.
So we can allow derived classes implement that method later.
*/

#include <iostream>
#include <vector>

class AbstractLogic
{
public:

	virtual void preUpdate() = 0; // template method

	void Update()
	{
		// do something

		preUpdate();
	}
};

class LogicOne : public AbstractLogic
{
public:
	void preUpdate()
	{
		std::cout << "Child one preUpdate" << std::endl;
	}
};

class LogicTwo : public AbstractLogic
{
public:
	void preUpdate()
	{
		std::cout << "Child two preUpdate" << std::endl;
	}
};

int main()
{
	AbstractLogic* logicOne = new LogicOne();
	AbstractLogic* logicTwo = new LogicTwo();

	logicOne->Update();
	logicTwo->Update();

	std::cin.get();

	delete logicOne;
	delete logicTwo;

	return 0;
}
