#include <stdlib.h>
#include <iostream>
using namespace std;

#define STACKSIZE 20
#define SIZE_MULTIPLIER 2

class Stack
{
public:
	void push(int a);
	int pop();
	void clear();
	bool isEmpty();
	Stack();			//this is constructor delcaration
	~Stack();			//this is deconstructor declaration
private:
	int top;
	int* data;
	int size;
};

int main(int argc, char const *argv[])
{
	Stack s1;
	Stack s2;
	s1.push(1);
	s1.push(2);
	if(s1.isEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		cout<< "Stack is not empty" << endl;
	}
	s1.push(3);
	s2.push(5);
	s2.push(6);
	{
		Stack s3;
		if(s3.isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			cout<< "Stack is not empty" << endl;
		}
	}
	cout << s1.pop() << " " << s2.pop() << endl;
	cout << s1.pop() << endl;
	return 0;
}

Stack::Stack()
{
	cout << "Stack::Stack() called\n";
	this->top = 0;
	this->size = STACKSIZE;
	this->data = (int*)malloc(this->size*sizeof(int));
	if(this->data == NULL)
	{
		exit(1);
	}
}

void Stack::push(int element)
{
	if(this->top == this->size)
	{
		this->size *= SIZE_MULTIPLIER;
		this->data = (int*)realloc(this->data, (this->size)*sizeof(int));
		if(this->data == NULL)
		{
			free(this->data);
			exit(1);
		}
	}
	this->data[this->top++] = element;
}

int Stack::pop()
{
	if(this->top == 0)
	{
		return false;
	}
	else
	{
		return this->data[--this->top];
	}
}

void Stack::clear()
{
	this->top = 0;
}

Stack::~Stack()
{
	free(this->data);
	this->data = NULL;
	cout << "Stack::~Stack() called\n";	
}

bool Stack::isEmpty()
{
	if(this->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}