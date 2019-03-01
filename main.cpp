#include <string>
#include <iostream>

template <class T>
class Stack
{
	class StackLevel
	{
	public:
		StackLevel * next;
		T element;
	};
	StackLevel * bottom_level;
public:
	Stack();
	void push(T);
	T pop(void);
};


template <class T>
Stack<T>::Stack()
{
	bottom_level = new StackLevel();
}

template <class T>
T Stack<T>::pop(void)
{
	T temp = bottom_level->element;
	auto new_bottom_level = bottom_level->next;
	delete(bottom_level);
	bottom_level = new_bottom_level;
	return temp;
}

template <class T>
void Stack<T>::push(T e)
{
	auto temp = bottom_level;
	bottom_level = new StackLevel;
	bottom_level->element = e;
	bottom_level->next = temp;
}


int main()
{
	Stack<std::string> stack;
	stack.push("test1\n");
	stack.push("test2\n");
	stack.push("test3\n");

	std::cout << stack.pop();
	std::cout << stack.pop();
	std::cout << stack.pop();
}
