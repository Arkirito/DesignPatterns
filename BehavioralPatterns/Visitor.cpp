/*
The Idea:

Visitor while been accepted by someone can operate on it in its specific way.
*/

#include <iostream>
#include <vector>

class AbstractRoom
{
public:

	virtual void accept(class AbstractVisitor* visitor) = 0;
};

class AbstractVisitor
{
public:

	virtual void visit(class RoomOne* room) = 0;
	virtual void visit(class RoomTwo* room) = 0;
};

class RoomOne : public AbstractRoom
{
public:
	virtual void accept(AbstractVisitor* visitor)
	{
		visitor->visit(this);
	}
};

class RoomTwo : public AbstractRoom
{
public:
	virtual void accept(AbstractVisitor* visitor)
	{
		visitor->visit(this);
	}
};

class FirstVisitor : public AbstractVisitor
{
public:

	virtual void visit(RoomOne* room)
	{
		std::cout << "First visitor operates on room one" << std::endl;
	}

	virtual void visit(RoomTwo* room)
	{
		std::cout << "First visitor operates on room two" << std::endl;
	}
};

class SecondVisitor : public AbstractVisitor
{
public:

	virtual void visit(RoomOne* room)
	{
		std::cout << "Second visitor operates on room one" << std::endl;
	}

	virtual void visit(RoomTwo* room)
	{
		std::cout << "Second visitor operates on room two" << std::endl;
	}
};

int main()
{
	FirstVisitor firstVisitor;
	SecondVisitor secondVisitor;

	RoomOne roomOne;
	RoomTwo roomTwo;

	roomOne.accept(&secondVisitor);
	roomTwo.accept(&firstVisitor);

	std::cin.get();
	return 0;
}
