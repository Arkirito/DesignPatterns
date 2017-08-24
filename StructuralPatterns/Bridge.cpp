#include <iostream>

class AbstractMeaninOfLife
{
protected:
	class AbstractMeaninOfLifeImpl* _impl;

public:
	virtual void GetMeaningOfLife() = 0;
	virtual ~AbstractMeaninOfLife() {};
};

class AbstractMeaninOfLifeImpl
{
public:
	virtual void Get() = 0;
	virtual ~AbstractMeaninOfLifeImpl() {}
};

class BobMeaninOfLifeImpl : public AbstractMeaninOfLifeImpl
{
public:

	virtual void Get()
	{
		std::cout << "Sports" << std::endl;
	}
};

class AliceMeaninOfLifeImpl : public AbstractMeaninOfLifeImpl
{
public:

	virtual void Get()
	{
		std::cout << "Love" << std::endl;
	}
};


class Bob : public AbstractMeaninOfLife
{
public:

	Bob()
	{
		_impl = new BobMeaninOfLifeImpl();
	}

	virtual void GetMeaningOfLife()
	{
		_impl->Get();
	}

};

class Alice : AbstractMeaninOfLife
{
public:

	Alice()
	{
		_impl = new AliceMeaninOfLifeImpl();
	}

	virtual void GetMeaningOfLife()
	{
		_impl->Get();
	}
};

int main()
{
	Bob* bob = new Bob();
	Alice* alice = new Alice();

	bob->GetMeaningOfLife();
	alice->GetMeaningOfLife();

	std::cin.get();

	delete bob;
	delete alice;

	return 0;
}
