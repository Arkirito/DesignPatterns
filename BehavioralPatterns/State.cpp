/*
The Idea:

We have an object that has a state. This state could be different, can do different tasks
and possible could be changed to other specific state. To handle this, we will make a class for every
state and keep a pointer to it in our object. Then we gonna just using it according to the base state
interface.
*/

#include <iostream>
#include <vector>

class AbstractState
{
public:

	virtual AbstractState* GetNextState() = 0;
	virtual void HandleState() = 0;
};

class StateInOS : public AbstractState
{
public:
	virtual AbstractState* GetNextState()
	{
		return nullptr;
	}
	virtual void HandleState()
	{
		std::cout << "OS Loaded and reaty to work" << std::endl;
	}
};

class StateLoadingOS : public AbstractState
{
public:
	virtual AbstractState* GetNextState()
	{
		return new StateInOS();
	}
	virtual void HandleState()
	{
		std::cout << "Loading OS" << std::endl;
	}
};

class StateTurnOn : public AbstractState
{
public:
	virtual AbstractState* GetNextState()
	{
		return new StateLoadingOS();
	}
	virtual void HandleState()
	{
		std::cout << "Turning tour PC on" << std::endl;
	}
};

class StateHandler
{
protected:
	AbstractState* _currentState;

public:

	StateHandler() : _currentState(nullptr)
	{
	}

	void SetState(AbstractState* state)
	{
		if (_currentState)
		{
			delete _currentState;
		}

		_currentState = state;
	}
};

class Computer : public StateHandler
{
public:

	void HandleStates()
	{
		if (!_currentState) return;

		while (_currentState)
		{
			_currentState->HandleState();

			AbstractState* next = _currentState->GetNextState();
			delete _currentState;
			_currentState = next;
		}
	}
};

int main()
{
	Computer myPC;

	myPC.SetState(new StateTurnOn());
	myPC.HandleStates();

	std::cin.get();
	return 0;
}
