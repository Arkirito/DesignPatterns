#include <iostream>
#include <map>
#include <string>

class Drone
{
public:
	void BuildDrone()
	{
		std::cout << "Drone ready" << std::endl;
	}
};

class EnergyShieldGenerator
{
public:
	void PowerOn()
	{
		std::cout << "Energy shield turned on" << std::endl;
	}
};

class Teleport
{
public:
	void Setup()
	{
		std::cout << "Teleport set" << std::endl;
	}
};

class DroneArmyFacade
{
protected:
	Teleport* _teleport;
	EnergyShieldGenerator* _energyShieldGenerator;
	Drone* _drone;

public:

	void DeployArmy()
	{
		_teleport = new Teleport();
		_teleport->Setup();
		_energyShieldGenerator = new EnergyShieldGenerator();
		_energyShieldGenerator->PowerOn();
		_drone = new Drone();
		_drone->BuildDrone();

		std::cout << "Army deployed" << std::endl;
	}

	~DroneArmyFacade()
	{
		delete _teleport;
		delete _energyShieldGenerator;
		delete _drone;
	}
};

int main()
{
	DroneArmyFacade facade;
	facade.DeployArmy();

	std::cin.get();
	return 0;
}