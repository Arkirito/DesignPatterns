/*
The Idea:

The class have a method to clone itself using itself as a prototype

*pseudocode*

someCopy = specificObject.clone();
*/

#include <iostream>
#include <string>

class AbstractPhone
{
public:

	virtual AbstractPhone* clone() const = 0;
};

class Smartphone : AbstractPhone
{
public:
	Smartphone()
	{

	}

	Smartphone(const Smartphone &other)
	{

	}

	virtual AbstractPhone* clone() const
	{
		return new Smartphone(*this);
	}
};

int main()
{
	Smartphone someModel;
	AbstractPhone* copy = someModel.clone();

	delete copy;
	return 0;
}