/*
The Idea:


*/

#include <iostream>

class AbstractCar
{
public:

	virtual void Run() = 0;
	virtual void Stop() = 0;
	virtual void UseNitro() = 0;

	virtual ~AbstractCar() {}
};

class Car : public AbstractCar
{
public:

	virtual void Run()
	{
		std::cout << "Runnig" << std::endl;
	}

	virtual void Stop()
	{
		std::cout << "Stopping" << std::endl;
	}

	virtual void UseNitro()
	{
		std::cout << "Using nitro" << std::endl;
	}
};

class CarProxy
{
private:

	Car* _car;

public:

	CarProxy()
	{
		_car = new Car();
	}

	void Run()
	{
		std::cout << "Checking for safety driving..." << std::endl;
		_car->Run();
	}

	void Stop()
	{
		std::cout << "Applying new brake technologies..." << std::endl;
		_car->Stop();
	}

	void UseNitro()
	{
		std::cout << "Nitro usage is now forbidden" << std::endl;
	}
};

int main()
{
	CarProxy* car = new CarProxy();
	car->Run();
	car->Stop();
	car->UseNitro();

	std::cin.get();

	return 0;
}
