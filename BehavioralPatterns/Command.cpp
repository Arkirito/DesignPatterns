/*
The Idea:

Command its just a class that:

1. Can store some data that is usefull for some task.
2. Can do this task based on stored data.
3. Can revert what was done based on stored data and because it knows what was done and how.

Another words it just incapsulates action in and object.
*/

#include <iostream>
#include <vector>

int someValue = 0; // this is just global value for simplicity

class AbstractCommand
{
public:

	virtual void Execute() = 0;
	virtual void DeExecute() = 0;
};

class PlusCommand : public AbstractCommand
{
protected:
	int _other;

public:
	PlusCommand(int other) : _other(other)
	{
	}

	virtual void Execute()
	{
		someValue += _other;
	}

	virtual void DeExecute()
	{
		someValue -= _other;
	}
};

class MinusCommand : public AbstractCommand
{
protected:
	int _other;

public:
	MinusCommand(int other) : _other(other)
	{

	}

	virtual void Execute()
	{
		someValue -= _other;
	}

	virtual void DeExecute()
	{
		someValue += _other;
	}
};

class ComandPull
{
protected:
	std::vector<AbstractCommand*> _commands;

public:

	ComandPull()
	{
		_commands.reserve(10);
	}

	void DoCommand(AbstractCommand* command)
	{
		command->Execute();
		_commands.push_back(command);
	}

	void Undo()
	{
		_commands.back()->DeExecute();
		_commands.pop_back();
	}
};

int main()
{
	ComandPull pull;

	pull.DoCommand(new PlusCommand(10));
	pull.DoCommand(new MinusCommand(20));

	std::cout << someValue << std::endl;

	pull.Undo();

	std::cout << someValue << std::endl;

	pull.Undo();

	std::cout << someValue << std::endl;

	std::cin.get();

	return 0;
}