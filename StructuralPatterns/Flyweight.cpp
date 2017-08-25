#include <iostream>
#include <map>
#include <string>

class Flyweight
{
protected:
	int _number;
public:
	Flyweight()
	{
		static int number = 0;
		_number = number++;
	}
	virtual ~Flyweight() {}
	virtual void Get()
	{
		std::cout << _number << std::endl;
	};
};

class FlyweightFactory
{
protected:
	std::map<int, Flyweight*> _flyweights;

public:

	Flyweight* GetFlyweight(int key)
	{
		auto fl = _flyweights.find(key);
		if (fl != _flyweights.end())
		{
			return fl->second;
		}
		else
		{
			_flyweights[key] = new Flyweight();
			return _flyweights[key];
		}
	}

};

int main()
{
	FlyweightFactory factory;
	Flyweight* fl1 = factory.GetFlyweight(15);
	Flyweight* fl2 = factory.GetFlyweight(25);
	Flyweight* fl3 = factory.GetFlyweight(15);
	fl1->Get();
	fl2->Get();
	fl3->Get();

	std::cin.get();
	delete fl1;
	delete fl2;
	delete fl3;
	return 0;
}