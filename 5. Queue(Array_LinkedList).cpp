#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

#include <bits/stdc++.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <array>
#include <numeric>
#include <deque>
#include <iomanip>
#include <stack>
#include <tuple>

using namespace std;

class LinkedList
{
    private:
        int size = 0;
        int countValue = 0;

        struct singleLink
        {
            int data;
            singleLink *next;
        }*actual_Single = NULL, *temp_Single = NULL;

        struct doubleLink
        {
            doubleLink *back;
            int data;
            doubleLink *next;
        }*actual_Double = NULL, *temp_Double = NULL;
    
    public:
        LinkedList(int size);
        singleLink insertSingleList(int element);
        singleLink deleteSingleList(void);

        doubleLink insertFront_DouleList(int element);
        doubleLink insertBack_DouleList(int element);
        doubleLink deleteDouleList(void);

        void displaySingleList(void);
        void displayDouleList(void);

};


enum Physical_DS
{
    Array = 1,
    Circular_Aray,
    Linked_List,
    Circular_Linked_List,
    Insert_Element = 1,
    Delete_Element,
    Display_Elements
};


class Queue
{
    private:
        int size = 1;
        int positionCurrent = -1;
        int positionBack = -1;
        int *queue;
    
    public:
        Queue(int size = 0);
        void setQueueSize (int size = 1);
        int getQueueSize(void) {   return size;    }

        void insertElement(int element = 0);
        void deleteElement (void);
        void displayQueue(void);
};

class CircularQueue
{
    private:
        int size = 1;
        int positionCurrent = 0;
        int positionBack = 0;
        int *circularQueue;
    
    public:
        CircularQueue(int size = 0);
        void setQueueSize (int size = 1);
        int getQueueSize(void) {   return size;    }

        void insertElement(int element = 0);
        void deleteElement (void);
        void displayQueue(void);
};



Queue::Queue(int size)
{
    this->size = size;
    queue = new int [size];
}

void Queue::setQueueSize (int size)
{
    queue = new int [size];
}

void Queue::insertElement(int element)
{
    if (this->size == (this->positionCurrent + 1))
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        this->positionCurrent++;
        this->queue[this->positionCurrent] = element;
    }
}

void Queue::deleteElement (void)
{
    if (this->positionCurrent == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        this->positionBack++;
        this->queue[positionBack] = 0;
        if ( ( this->positionBack == (this->size - 1)) || ( this->positionBack == this->positionCurrent + 1) )
        {
            this->positionBack = -1;
            this->positionCurrent = -1;
        }
    }
}

void Queue::displayQueue(void)
{
    for (int i = (this->positionBack + 1); i<= this->positionCurrent; i++)
        cout << this->queue[i] << " ";
    cout << endl;
}


// ********************************************************* //
// **************** Circular Queue ************************ //
// ********************************************************* //


CircularQueue::CircularQueue(int size)
{
    this->size = size;
    circularQueue = new int [size];
}

void CircularQueue::setQueueSize (int size)
{
    circularQueue = new int [size];
}

void CircularQueue::insertElement(int element)
{
    // this->positionCurrent++;
    // if  ( ( this->positionCurrent == (this->size + 1) )
    //     &&  ( this->positionBack != 0 ) )
    // {
    //     this->positionCurrent = 0;
    // }

    // if ( ( this->positionCurrent < this->size )
    //     &&  ( this->positionCurrent != this->positionBack ) )
    // {
    //     this->circularQueue [this->positionCurrent] = element;
    // }
    // else
    // {
    //     cout << "Queue is full " << endl;
    // }

    if ( (this->positionBack + 1) % (this->size) == this->positionCurrent)
    {
        cout << "Queue is full " << endl;
    }
    else
    {
        this->positionBack = (this->positionBack + 1) % (this->size);
        this->circularQueue[this->positionBack] = element;
    }
}

void CircularQueue::deleteElement (void)
{
    this->positionBack++;
    if ( this->positionBack == this->size)
    {
        this->positionBack = 0;
    }
    this->circularQueue[ this->positionBack ] = 0;
}

void CircularQueue::displayQueue(void)
{
    int i = this->positionBack + 1;

    while (1)
    {
        if (i == this->positionCurrent) break;
        else if (i == this->size)   i = 0;
        else
        {
            cout << this->circularQueue[i] << " ";
        }
        i++;
    }
    cout << endl;
}


// ********************************************************* //
// **************** Linked List ************************ //
// ********************************************************* //

LinkedList::LinkedList(int size)
{
    this->size = size;
}


LinkedList::singleLink LinkedList::insertSingleList(int element)
{
    if ((this->size) > 0)
    {
        if ( this->countValue < this->size)
        {
            if (!this->countValue)
            {
                this->actual_Single = new LinkedList::singleLink;
                this->actual_Single->data = element;
                this->actual_Single->next = 0;
                this->temp_Single = this->actual_Single;
                this->countValue++;
            }
            else
            {
                LinkedList::singleLink *dummy  = new LinkedList::singleLink;
                dummy->data = element;
                dummy->next = 0;
                this->temp_Single->next = dummy;
                this->temp_Single = dummy;

                dummy = NULL;
                delete [] dummy;
                this->countValue++;
            }

        }
        else
        {
            cout << "\nStack is full \n" << endl;
        }

    }
    else
    {
        cout << "\nsize is not allocated" << endl;
    }
}

LinkedList::singleLink LinkedList::deleteSingleList(void)
{
    LinkedList::singleLink *head = new LinkedList::singleLink;
    head = this->actual_Single;
    this->actual_Single = this->actual_Single->next;
    head->next = 0;
    head = NULL;
    delete [ ] head;
    this->countValue--;
}


void LinkedList::displaySingleList(void)
{
    LinkedList::singleLink *head = new LinkedList::singleLink;
    head = this->actual_Single;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next ;
    }

    head = NULL;
    delete [] head;

    cout << endl;
}


LinkedList::doubleLink LinkedList::insertBack_DouleList(int element)
{
    if ((this->size) > 0)
    {
        if ( this->countValue < this->size)
        {
            if (!this->countValue)
            {
                this->actual_Double = new LinkedList::doubleLink;
                this->actual_Double->back = 0;
                this->actual_Double->data = element;
                this->actual_Double->next = 0;
                this->temp_Double = this->actual_Double;
                this->countValue++;
            }
            else
            {
                LinkedList::doubleLink *dummy = new LinkedList::doubleLink;
                dummy->back = this->temp_Double;
                dummy->data = element;
                dummy->next = 0;

                this->temp_Double->next = dummy;
                this->temp_Double = dummy;
                dummy = NULL;

                delete [] dummy;
                this->countValue++;
            }
        }
        else
        {
            cout << "\nStack is full \n" << endl;
        }

    }
    else
    {
        cout << "\nsize is not allocated" << endl;
    }
}

LinkedList::doubleLink LinkedList::insertFront_DouleList(int element)
{

}


LinkedList::doubleLink LinkedList::deleteDouleList(void)
{

}

void LinkedList::displayDouleList(void)
{
    LinkedList::doubleLink *head = new LinkedList::doubleLink;
    head = this->actual_Double;

    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}



// ********************************************************* //
// ********************************************************* //

int main()
{

    int choiceSelection = 0;
    cout << "1. Creating Queue using Array. \n" <<
            "2. Creating Circular Queue using Array \n" <<
            "3. Creating Queue using single Linked List. \n" <<
            "4. Creating Queue using circular Linked List. \n" <<
            "Enter your choice: ";
    cin >> choiceSelection;

    switch (choiceSelection)
    {
        case Array:
        {
            int queueSize = 0;
            cout << "Enter the size of the Queue: ";
            cin >> queueSize;
            
            Queue q(queueSize);
            cout << q.getQueueSize()<< endl;
            
            while (1)
            {
                int operationPerformed = 0;

                cout << "1. Inserting an Element in the queue. \n" <<
                        "2. Deleting an Element in the queue. \n" <<
                        "3. Display Queue Elements \n"<<
                        "Enter your choice: ";
                cin >> operationPerformed;

                switch (operationPerformed)
                {
                    case Insert_Element:
                    {
                        int element = 0;
                        cout << "Enter the element you want to insert: ";
                        cin >> element;
                        q.insertElement(element);
                        break;
                    }

                    case Delete_Element:
                    {
                        q.deleteElement();
                        break;
                    }

                    case Display_Elements:
                    {
                        q.displayQueue();
                        break;
                    }
                }
                int continueProgram = 0;
                cout << "Do you want to continue? 1/0: ";
                cin >> continueProgram;
                if (!continueProgram)
                    break;
            
            }

            break;
        }

        case Circular_Aray:
        {
            int queueSize = 0;
            cout << "Enter the size of the Queue: ";
            cin >> queueSize;
            
            CircularQueue q(queueSize);
            cout << q.getQueueSize()<< endl;
            
            while (1)
            {
                int operationPerformed = 0;

                cout << "1. Inserting an Element in the queue. \n" <<
                        "2. Deleting an Element in the queue. \n" <<
                        "3. Display Queue Elements \n"<<
                        "Enter your choice: ";
                cin >> operationPerformed;

                switch (operationPerformed)
                {
                    case Insert_Element:
                    {
                        int element = 0;
                        cout << "Enter the element you want to insert: ";
                        cin >> element;
                        q.insertElement(element);
                        break;
                    }

                    case Delete_Element:
                    {
                        q.deleteElement();
                        break;
                    }

                    case Display_Elements:
                    {
                        q.displayQueue();
                        break;
                    }
                }
                int continueProgram = 0;
                cout << "Do you want to continue? 1/0: ";
                cin >> continueProgram;
                if (!continueProgram)
                    break;
            
            }

            break;
        }

        case Linked_List:
        {
            int queueSize = 0;
            cout << "Enter the size of the Queue: ";
            cin >> queueSize;
            LinkedList q(queueSize);
            
            while (1)
            {
                int operationPerformed = 0;

                cout << "1. Inserting an Element in the queue. \n" <<
                        "2. Deleting an Element in the queue. \n" <<
                        "3. Display Queue Elements \n"<<
                        "Enter your choice: ";
                cin >> operationPerformed;

                switch (operationPerformed)
                {
                    case Insert_Element:
                    {
                        int element = 0;
                        cout << "Enter the element you want to insert: ";
                        cin >> element;
                        q.insertSingleList(element);
                        break;
                    }

                    case Delete_Element:
                    {
                        q.deleteSingleList();
                        break;
                    }

                    case Display_Elements:
                    {
                        q.displaySingleList();
                        break;
                    }
                }
                int continueProgram = 0;
                cout << "Do you want to continue? 1/0: ";
                cin >> continueProgram;
                if (!continueProgram)
                    break;
            
            }

            break;
        }   

        case Circular_Linked_List:
        {
            int queueSize = 0;
            cout << "Enter the size of the Queue: ";
            cin >> queueSize;
            LinkedList q(queueSize);
            
            while (1)
            {
                int operationPerformed = 0;

                cout << "1. Inserting an Element in the queue. \n" <<
                        "2. Deleting an Element in the queue. \n" <<
                        "3. Display Queue Elements \n"<<
                        "Enter your choice: ";
                cin >> operationPerformed;

                switch (operationPerformed)
                {
                    case Insert_Element:
                    {
                        int element = 0;
                        cout << "Enter the element you want to insert: ";
                        cin >> element;
                        q.insertFront_DouleList(element);
                        break;
                    }

                    case Delete_Element:
                    {
                        q.deleteDouleList();
                        break;
                    }

                    case Display_Elements:
                    {
                        q.displayDouleList();
                        break;
                    }
                }
                int continueProgram = 0;
                 cout << "Do you want to continue? 1/0: ";
                 cin >> continueProgram;
                 if (!continueProgram)
                     break;
            
            }

            break;
        }
    }
    
}
