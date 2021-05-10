#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>

#include <bits/stdc++.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <forward_list>
#include <map>
#include <array>
#include <numeric>
#include <deque>
#include <iomanip>

using namespace std;

class Stack
{
    private:
        int *ptr;
        int size;
        int topIndicator;

    public:
        Stack(int size = 0);
        void setStackSize (int size = 0);
        Stack setValue(int element=0);
        void printStack(void);
        int getStackValue (int position = 0);
        void push(int element = 0);
        void pop (void);
        int peek (int index = 0);
        bool isStackEmpty (void);
        bool isStackFull (void);
};

Stack::Stack(int size)
{
    this->ptr = new int [size];
    this->topIndicator = -1;

    for (int i =0 ; i < size; i++)
    {
        this->ptr[i] = 0;
    }
}

void Stack::setStackSize (int size)
{
    this->size = size;
    this->ptr = new int[size];
}

void Stack::printStack(void)
{
    for (int i=0; i<= this->topIndicator; i++)
    {
        cout << this->ptr[i] << " ";
    }

    cout << endl;
}

Stack Stack::setValue(int element)
{
    for (int i=0; i< (element); i++)
    {
        this->ptr[i] = i+1;
        this->topIndicator++;
    }
    return *this;
}

int Stack::getStackValue (int position)
{

}

void Stack::push(int element)
{
    if (this->topIndicator == (this->size - 1))
        cout << "Stack Overflow" << endl;
    
    else
    {
        this->ptr[++this->topIndicator] = element;
    }
}


void Stack::pop (void)
{
    if (this->topIndicator == -1)
        cout << "Stack Underflow" << endl;
    else
    {
        this->ptr[this->topIndicator--] = 0;
    }
}

int Stack::peek (int index)
{
    if ((this->topIndicator - index + 1) > -1)
    {
        return this->ptr[this->topIndicator - index + 1];
    }

    else if (this->size < index)
    {
        cout << "Invalid Stack Memory" << endl;
    }
    else
    {
        cout << "Invalid Stack Memory" << endl;
    }
}

bool Stack::isStackEmpty (void)
{
    if (this->topIndicator == -1)   return 1;
    return 0;
}

bool Stack::isStackFull (void)
{
    if (this->topIndicator == (this->size - 1))   return 1;
    return 0;
}

int main()
{
    Stack stk(10);
    stk.setStackSize(5);
    stk = stk.setValue(3);
    cout << "Initial Stack: ";
    stk.printStack();
    cout << "Push Operation: ";
    stk.push(10);
    stk.push(100);
    stk.printStack();
    cout << "Pop Operation: ";
    stk.pop();
    stk.printStack();

    cout << "Peek Operation: " << stk.peek(3) << endl;
    int x = stk.isStackEmpty();
    if(x)   cout << "Stack is Empty" << endl;
    else    cout << "Stack is not Empty" << endl;

    x = stk.isStackFull();
    if(x)   cout << "Stack is Filled" << endl;
    else    cout << "Stack is not Filled" << endl;
}
