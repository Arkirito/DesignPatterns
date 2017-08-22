#include <iostream>
#include <string>

class AbstractExpression
{
public:

	virtual bool interpret(std::string context) = 0;
	virtual ~AbstractExpression() {}
};

class TerminalExpression : public AbstractExpression
{
protected:

	std::string _data;

public:

	TerminalExpression(std::string data)
		: _data(data)
	{

	}

	virtual bool interpret(std::string context)
	{
		return context.find(_data) != std::string::npos;
	}
};

class AndExpression : public AbstractExpression
{
protected:

	AbstractExpression* _expr1;
	AbstractExpression* _expr2;

public:

	AndExpression(AbstractExpression* expr1, AbstractExpression* expr2)
		: _expr1(expr1)
		, _expr2(expr2)
	{

	}

	virtual bool interpret(std::string context)
	{
		return _expr1->interpret(context) && _expr2->interpret(context);
	}

	virtual ~AndExpression()
	{
		delete _expr1;
		delete _expr2;
	}
};

int main()
{
	AndExpression expr(new TerminalExpression("Alex"), new TerminalExpression("chair"));

	std::cout << std::to_string(expr.interpret("Alex")) << std::endl;
	std::cout << std::to_string(expr.interpret("chair")) << std::endl;
	std::cout << std::to_string(expr.interpret("Alex sits on the chair")) << std::endl;

	std::cin.get();
	return 0;
}
