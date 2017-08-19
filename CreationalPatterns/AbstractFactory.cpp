/*
The Idea:

We have some abstract vision of a factory that can potentially create something. But those objects could
be a lot different. For example a car factory can create a car, but for Lamborgini it gonna be Aventador
and for AvtoVAZ if would be Lada Kalina. The process of creation can be different so we need different
classes for bouth factories. And of course for different cars too. And then all what we do - is creating an
instance of a factory that we need, calling a method for creating a car and it does everything else.

*pseudo code*
abstractFactory = new SpecificFactory();
abstractObject =  abstractFactory->CreateSpecificObject();
*/

#include <iostream>

class AbstarctCar
{
public:
	virtual void DrawName() = 0;
};

class LamborginiCar : public AbstarctCar
{
public:
	virtual void DrawName()
	{
		std::cout << "Lamborgini Aventador\n";
	}
};

class LamborginiJeep : public AbstarctCar
{
public:
	virtual void DrawName()
	{
		std::cout << "Lamborgini Urus\n";
	}
};

class LadaKalina : public AbstarctCar
{
public:
	virtual void DrawName()
	{
		std::cout << "Lada Kalina\n";
	}
};

class LadaNiva : public AbstarctCar
{
public:
	virtual void DrawName()
	{
		std::cout << "Lada Niva\n";
	}
};

class AbstractCarFactory
{
public:

	virtual AbstarctCar* CreateCar() = 0;
	virtual AbstarctCar* CreateJeep() = 0;
};

class LamborginiFactory : public AbstractCarFactory
{
public:

	virtual AbstarctCar* CreateCar()
	{
		return new LamborginiCar();
	}

	virtual AbstarctCar* CreateJeep()
	{
		return new LamborginiJeep();
	}
};

class AvtoVAZFactory : public AbstractCarFactory
{
public:
	virtual AbstarctCar* CreateCar()
	{
		return new LadaKalina();
	}

	virtual AbstarctCar* CreateJeep()
	{
		return new LadaNiva();
	}
};

int main()
{
	AbstractCarFactory* lamborginiFactory = new LamborginiFactory();
	AbstractCarFactory* avtoVAZFactory = new AvtoVAZFactory();

	AbstarctCar* lamborginiCar = lamborginiFactory->CreateCar();
	AbstarctCar* lamborginiJeep = lamborginiFactory->CreateJeep();
	AbstarctCar* ladaCar = avtoVAZFactory->CreateCar();
	AbstarctCar* ladaJeep = avtoVAZFactory->CreateJeep();

	lamborginiCar->DrawName();
	lamborginiJeep->DrawName();
	ladaCar->DrawName();
	ladaJeep->DrawName();

	std::cin.get();

	delete lamborginiFactory;
	delete avtoVAZFactory;

	delete lamborginiCar;
	delete lamborginiJeep;
	delete ladaCar;
	delete ladaJeep;

	return 0;
}