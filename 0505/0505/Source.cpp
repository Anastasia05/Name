#include <iostream>
using namespace std;

template <typename myTip>
class Stack
{
	int size;
	struct ElementStack
	{
		myTip znach;
		ElementStack* pred;
	} *top;
public:
	void push(myTip x)  // Положить элемент в стек
	{
		if (top == NULL)
		{
			Stack(x);
			return;
		}
		ElementStack* p = new ElementStack;
		p->pred = top;
		p->znach = x;
		top = p;
	}

	myTip pull()  // Вытащить элемент из стека
	{
		if (size == 0)
		{
			cout << "Стек пуст!\n";
			return 0;
		}
		myTip x = top->znach;
		ElementStack* p = top;
		top = top->pred;
		delete p;
		size = size - 1;
		return x;
	}
	void del()  //Очистка стека
	{
		if (size != 0)
		{
			ElementStack* p;
			while (top != 0)
			{
				p = top;
				top = top->pred;
				delete p;
			}
			size = 0;
			top = NULL;
		}
	}
	int getSize()        // Какой размер?
	{
		return size;
	}
	Stack(myTip x)    // Конструктор
	{
		top = new ElementStack;
		top->znach = x;
		size = 1;
		top->pred = NULL;
	}
	~Stack()           // Деструктор
	{
		del();
	}
};

////////////////////

template <typename myTip>
class Queue
{
	int size;
	struct ElementQueue
	{
		myTip znach;
		ElementQueue* pred;
		ElementQueue* sled;
	} *nach, *kon;
public:
	void push(myTip x)  // Положить элемент в очередь
	{
		if (nach == NULL)
		{
			Queue(x);
			return;
		}
		ElementQueue* p = new ElementQueue;
		p->pred = nach;
		nach->sled = p;
		p->sled = NULL;
		p->znach = x;
		nach = p;
	}
	myTip pull()   // Вытащить элемент
	{
		if (!size)
		{
			cout << "Очередь пуста!\n";
			return NULL;
		}
		myTip x = kon->znach;
		ElementQueue* p = kon;
		if (kon->sled)
			(kon->sled)->pred = NULL;
		kon = kon->sled;
		if (size == 1)
		{
			delete p;
			nach = NULL;
		}
		else
			delete p;
		size--;
		return x;
	}
	void del()      // Очистка очереди
	{
		if (size)
		{
			ElementQueue* p;
			while (nach)
			{
				p = nach;
				nach = nach->pred;
				delete p;
			}
			size = 0;
			nach = NULL;
		}
	}
	bool pust()      // Пуст ли?
	{
		if (!size)
			return true;
		return false;
	}
	Queue(myTip x)
	{
		nach = new ElementQueue;
		nach->pred = NULL;
		nach->sled = NULL;
		nach->znach = x;
		kon = nach;
		size = 1;
	}
	~Queue()
	{
		del();
	};
};




int main()
{
	setlocale(0, "");
	return 0;

}