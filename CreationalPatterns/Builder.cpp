/*
The Idea:

We have some object but have multiple ways to build it. For every single build we can declare another
builder class that will just build it in a specific way.

*pseudocode*
abstractBuilder = new specificBuilder();
specificObject = abstractBuilder->Build();
*/

#include <iostream>
#include <string>

class Sandwich
{
public:
	std::string ingredients;

	void PrintIngredients()
	{
		std::cout << ingredients << std::endl;
	}
};

class AbstractSnadwichBuilder
{
public:

	virtual Sandwich* BuildSandwich() = 0;
};

class MeatSandwichBuilder : public AbstractSnadwichBuilder
{
public:
	virtual Sandwich* BuildSandwich()
	{
		Sandwich* sandwich = new Sandwich();

		sandwich->ingredients = "Bread, Sausage, Tomatoes, Ketchup";

		return sandwich;
	}
};

class CheeseSandwichBuilder : public AbstractSnadwichBuilder
{
public:
	virtual Sandwich* BuildSandwich()
	{
		Sandwich* sandwich = new Sandwich();

		sandwich->ingredients = "Bread, Cheese, Mayonnaise";

		return sandwich;
	}
};

int main()
{
	AbstractSnadwichBuilder* meatBuilder = new MeatSandwichBuilder();
	AbstractSnadwichBuilder* cheeseBuilder = new CheeseSandwichBuilder();

	Sandwich* withMeat = meatBuilder->BuildSandwich();
	Sandwich* withCheese = cheeseBuilder->BuildSandwich();

	withMeat->PrintIngredients();
	withCheese->PrintIngredients();

	std::cin.get();

	delete meatBuilder;
	delete cheeseBuilder;

	delete withMeat;
	delete withCheese;

	return 0;
}