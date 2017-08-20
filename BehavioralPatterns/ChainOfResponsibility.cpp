/*
The Idea:

We have something to handle and pass it to the handler. If it can handle it - it handles, if it cannot - he passes it to the "next" handler or
telling us that this could not be handled at all.
*/

#include <iostream>
#include <vector>


class Message
{
public:
	Message(int encryptionLevel) : EncryptionLevel(encryptionLevel)
	{}

	int EncryptionLevel;
};

class AbstractHandler
{
protected:
	AbstractHandler* _next;
	int _encryptionPower;
	virtual void HandleInternal(Message) = 0;

public:
	AbstractHandler(int encryptionPower)
		: _encryptionPower(encryptionPower)
		, _next(nullptr)
	{

	}

	AbstractHandler* SetNext(AbstractHandler* next)
	{
		_next = next;
		return _next;
	}

	void Handle(Message message)
	{
		if (message.EncryptionLevel <= _encryptionPower)
		{
			HandleInternal(message);
		}
		else
		{
			if (_next)
			{
				_next->Handle(message);
			}
			else
			{
				std::cout << "Unhandled message" << std::endl;
			}
		}
	}
};

class FirstHandler : public AbstractHandler
{
public:
	FirstHandler(int value) : AbstractHandler(value)
	{}

protected:

	virtual void HandleInternal(Message)
	{
		std::cout << "First handle" << std::endl;
	}
};

class SecondHandler : public AbstractHandler
{
public:
	SecondHandler(int value) : AbstractHandler(value)
	{}

protected:

	virtual void HandleInternal(Message)
	{
		std::cout << "Second handle" << std::endl;
	}
};

int main()
{
	FirstHandler* handler = new FirstHandler(10);
	SecondHandler* secondHandler = new SecondHandler(20);

	handler->SetNext(secondHandler);

	handler->Handle(Message(5));
	handler->Handle(Message(14));
	handler->Handle(Message(22));

	std::cin.get();

	return 0;
}
