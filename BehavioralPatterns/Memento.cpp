/*
The Idea:

Memento is an object that stores some data about another object, another words it represents its state
at some moment. Then it can set the object back to this state. This can be used for Undo/Redo or,
as in this example, if we gonna save memento every frame for last few seconds, we can then use them
to display car movement "replay".
*/

#include <iostream>
#include <vector>

class Car
{
	friend class Memento;

public:
	Car()
	{}

	Car(float forward, float side) : _forwardSpeed(forward), _sideSpeed(side)
	{}

	void SpeedUp(float value)
	{
		_forwardSpeed += value;
	}

	void Turn(float value)
	{
		_sideSpeed += value;
	}

	void PrintState()
	{
		std::cout << "Forward Speed: " << _forwardSpeed << std::endl << "Side Speed: " << _sideSpeed << std::endl;
	}

protected:
	float _forwardSpeed;
	float _sideSpeed;
};

class Memento
{
public:
	Memento(Car* car) : _forwardSpeed(car->_forwardSpeed), _sideSpeed(car->_sideSpeed)
	{}

	void SetState(Car* car)
	{
		car->_forwardSpeed = _forwardSpeed;
		car->_sideSpeed = _sideSpeed;
	}

protected:
	float _forwardSpeed;
	float _sideSpeed;
};

int main()
{
	Car myCar(10, -1);
	myCar.SpeedUp(20);
	Memento someMemento(&myCar); // keeping this state

	myCar.Turn(15);
	myCar.SpeedUp(-10);

	myCar.PrintState();
	someMemento.SetState(&myCar);
	myCar.PrintState();

	std::cin.get();

	return 0;
}