/*
The Idea:

Some class can have a method to create something, and this method could be overritten in children.

*pseudocode*

something = specificObject->FactoryMethodThatCreatesSomething();
*/

#include <iostream>

class AbstractSword
{
public:
	virtual void GetName() = 0;
};

class BadSword : public AbstractSword
{
public:
	virtual void GetName()
	{
		std::cout << "Bad sword" << std::endl;
	}
};

class GoodSword : public AbstractSword
{
public:
	virtual void GetName()
	{
		std::cout << "Good sword" << std::endl;
	}
};

class AbstractArmourer
{
public:
	virtual AbstractSword* MakeSword() = 0;
};

class JuniorArmourer : public AbstractArmourer
{
public:
	void DoSomethingLikeDrinkingBeer()
	{

	}

	virtual AbstractSword* MakeSword()
	{
		return new BadSword();
	}
};

class MasterArmourer : public AbstractArmourer
{
public:
	void DoSomethingLikeTellingJokes()
	{

	}

	virtual AbstractSword* MakeSword()
	{
		return new GoodSword();
	}
};

int main()
{
	AbstractArmourer* junior = new JuniorArmourer();
	AbstractArmourer* master = new MasterArmourer();

	AbstractSword* badOne = junior->MakeSword();
	AbstractSword* goodOne = master->MakeSword();

	badOne->GetName();
	goodOne->GetName();

	std::cin.get();

	delete junior;
	delete master;
	delete badOne;
	delete goodOne;

	return 0;
}