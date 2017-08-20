/*
The Idea:

The Observable is someone who do some job and at some moment it can notify all
Observers subscribed to it. Very simple ;-)

In this example we are implementing the Update logic that is commonly used everywere.
*/

#include <iostream>
#include <vector>

class IObserver
{
public:

	void Update()
	{
		std::cout << "IObserver updating..." << std::endl;
	}
};

class IObservable
{
protected:
	std::vector<IObserver*> _observers;

public:

	IObservable()
	{
		_observers.reserve(10);
	}

	void Update()
	{
		std::cout << "IObservable update" << std::endl;

		for (auto i : _observers)
		{
			i->Update();
		}
	}

	void Subscribe(IObserver* observer)
	{
		_observers.push_back(observer);
	}

	void UnsubscribeAll()
	{
		_observers.clear();
	}

};

int main()
{
	IObserver* observer1 = new IObserver();
	IObserver* observer2 = new IObserver();

	IObservable root;

	root.Subscribe(observer1);
	root.Subscribe(observer2);

	root.Update();
	root.UnsubscribeAll();

	std::cin.get();
	return 0;
}