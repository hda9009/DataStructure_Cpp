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

template <typename T>
class Stack
{
    private:
        T *ptr;
        int size;
        int topIndicator;

    public:
        Stack(int size = 0);
        void setStackSize (int size = 0);
        Stack setValue(T element, string type);
        void printStack(void);
        int getStackValue (int position = 0);
        void push(T element = 0);
        void pop (void);
        int peek (int index = 0);
        bool isStackEmpty (void);
        bool isStackFull (void);
        bool isParanthesisMatch(char *element);
};


template <typename T>
Stack<T>::Stack(int size)
{
    this->ptr = new T [size];
    this->topIndicator = -1;

    for (int i =0 ; i < size; i++)
    {
        this->ptr[i] = 0;
    }
}

template <typename T>
void Stack<T>::setStackSize (int size)
{
        this->size = size;
        this->ptr = new T[size];
}

template <typename T>
void Stack<T>::printStack(void)
{
    for (int i=0; i<= this->topIndicator; i++)
    {
        cout << this->ptr[i] << " ";
    }

    cout << endl;
}

template <typename T>
Stack<T> Stack<T>::setValue(T element, string type)
{
    if (type == "int")
    {    
        for (int i=0; i< (element); i++)
        {
            this->ptr[i] = i+1;
            this->topIndicator++;
        }
    }
    else if (type == "char")
    {
        char dum[] = "((a+b)*(c+d))";
        this->size = sizeof(dum);

        for (int i=0; i< (strlen(dum)); i++)
        {
            this->ptr[i] = dum[i];
            this->topIndicator++;
        }
    }
    return *this;
}

template <typename T>
int Stack<T>::getStackValue (int position)
{

}

template <typename T>
void Stack<T>::push(T element)
{
    if (this->topIndicator == (this->size - 1))
        cout << "Stack Overflow" << endl;
    
    else
    {
        this->ptr[++this->topIndicator] = element;
    }
}

template <typename T>
void Stack<T>::pop (void)
{
    if (this->topIndicator == -1)
        cout << "Stack Underflow" << endl;
    else
    {
        this->ptr[this->topIndicator--] = 0;
    }
}

template <typename T>
int Stack<T>::peek (int index)
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

template <typename T>
bool Stack<T>::isStackEmpty (void)
{
    if (this->topIndicator == -1)   return 1;
    return 0;
}

template <typename T>
bool Stack<T>::isStackFull (void)
{
    if (this->topIndicator == (this->size - 1))   return 1;
    return 0;
}

// ************************************************************//
// ************************************************************//
// ************************************************************//

template <typename T>
bool Stack<T>::isParanthesisMatch(char *element)
{
    cout<< this->topIndicator;  // else stack overflow will happen
    this->size += 1;
    for (int i = 0 ; i < this->topIndicator; i++)
    {
        if (this->ptr[i] == '(')
        {
            this->push('(');
        }
        else if (this->ptr[i] == ')')
        {
            this->pop();
        }
    }
}


int main()
{
    Stack<int> stk(10);
    stk.setStackSize(5);
    stk = stk.setValue(3, "int");

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


    cout << endl << endl << "----String Parenthesis Matching----\n" ;

    Stack<char> stkString;
    stkString.setStackSize(10);
    char dum[] = "((a+b)*(c+d))";
    stkString.setValue(dum[0], "char");
    stkString.printStack();
    cout << "String Filled: " << stkString.isStackFull();

    char search[] = "(";
    stkString.isParanthesisMatch(search);
}
