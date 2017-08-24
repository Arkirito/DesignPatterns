#include <iostream>
#include <string>

class IObject
{
public:
	virtual  ~IObject() {}
	virtual void DoSomething() = 0;
};

class Object : public IObject
{
public:
	virtual void DoSomething()
	{
		std::cout << "Car";
	}
};

class Decorator : public IObject
{
protected:
	IObject* _object; // We're decorating this 
public:

	Decorator(IObject* object)
		: _object(object)
	{

	}

	~Decorator()
	{
		delete _object;
	}

	virtual void DoSomething()
	{
		std::cout << " [";
		_object->DoSomething();
		std::cout << "] " << std::endl;
	}
};

int main()
{
	IObject* obj = new Decorator(new Object());
	obj->DoSomething();

	std::cin.get();

	delete obj;
	return 0;
}