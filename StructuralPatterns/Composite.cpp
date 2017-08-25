#include <iostream>
#include <vector>
#include <string>

class Widget
{
public:
	virtual ~Widget() {};
	virtual void OnEvent() = 0;
};

class ButtonWidget : public Widget
{
public:

	virtual void OnEvent()
	{
		std::cout << "Button" << std::endl;
	}
};

class TextWidget : public Widget
{
public:

	virtual void OnEvent()
	{
		std::cout << "Text" << std::endl;
	}
};

class CompositeWidget : public Widget
{
protected:
	std::vector<Widget*> _widgets;

public:

	~CompositeWidget()
	{
		for (auto i : _widgets)
		{
			delete i;
		}
	}

	void Add(Widget* widget)
	{
		_widgets.push_back(widget);
	}

	void OnEvent()
	{
		for (auto i : _widgets)
		{
			i->OnEvent();
		}
	}
};

int main()
{
	CompositeWidget* compositeWidget = new CompositeWidget();
	compositeWidget->Add(new ButtonWidget());
	compositeWidget->Add(new TextWidget());
	compositeWidget->OnEvent();

	std::cin.get();
	delete compositeWidget;
	return 0;
}