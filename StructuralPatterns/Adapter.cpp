/*
The Idea:

We have some old interface and some new class with cool functional. We want to use that old
interface to operate the new functional. So we inheritate an interface publicly and cool functional
privately + making some middle interface for new class to correctly setup and use both of them.
*/

#include <iostream>
#include <vector>

class OldAbstractCar
{
public:

	virtual void SpeedUp() = 0;
	virtual void SpeedDown() = 0;
	virtual void PrintSpeed() = 0;
};

class NewCar
{
protected:
	float _speed;

public:

	NewCar(float speed) : _speed(speed)
	{

	}

	void SetSpeed(float speed)
	{
		_speed = speed;
	}
};

class CarAdapter : public OldAbstractCar, private NewCar
{
protected:
	float _speedStep;

public:

	CarAdapter(float startSpeed, float step)
		: NewCar(startSpeed)
		, _speedStep(step)
	{}

	virtual void SpeedUp()
	{
		SetSpeed(_speed + _speedStep);
	}

	virtual void SpeedDown()
	{
		SetSpeed(_speed - _speedStep);
	}

	virtual void PrintSpeed()
	{
		std::cout << _speed << std::endl;
	}
};

int main()
{
	OldAbstractCar* car = new CarAdapter(10, 100);

	car->SpeedUp();
	car->SpeedUp();

	car->PrintSpeed();

	car->SpeedDown();

	car->PrintSpeed();

	std::cin.get();
	return 0;
}
