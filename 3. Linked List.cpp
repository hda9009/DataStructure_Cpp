#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*actual = NULL;

void createNode(int dummy[], int n)
{
    struct Node *temp, *last;

    actual = new Node;
    actual->data = dummy[0];
    actual->next = NULL;

    last = actual;

    for (int i = 1; i< n ; i++)
    {
        temp = new Node;
        temp->data = dummy[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
        temp = NULL;
        delete [] temp;
    }
}

tuple <int,int> countLinked(struct Node *p)
{
    static int counts = 0;
    static int sum = 0;
    while (p != NULL)
    {
        counts++;
        sum += p->data;
        p = (p->next);
    }
    return make_tuple(sum, counts);
}

void display(struct Node *p)
{
    if (p!= NULL)
    {
        printf("%d ", p->data);
        display(p->next);
    }

    if (p==NULL)    cout << endl;
}

int maximumValue (struct Node *p)
{
    static int max = 0;
    max = p->data;
    while (p != NULL)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

Node* searchElement (Node *p, int keyElement)
{
    static int i = 0;
    
    if (p->next == NULL)
            return 0;
    
    if (keyElement == p->data)
        return p;
    
        return searchElement(p->next, keyElement);
}

Node* moveToHead(Node *p, int keyElement)
{
    Node *temp = new Node;
    Node *head = new Node;
    head = p;
    
    while (p!= NULL)
    {
        if (keyElement == p->data)
        {
            temp->next = p->next;
            p->next = head;
            head = p;
            return head;
        }
        else
        {
            temp = p;
            p = p->next;
            // moveToHead(p->next, keyElement);
        }
    }
    return p;
}

Node * elementInsertion(Node *p, int keyElement, int keyPosition)
{
    Node *addNode = new Node;
    Node *head = new Node;

    addNode->data = keyElement;
    addNode->next = 0;
    head = p;
     
    if (keyPosition == 0)
    {
        addNode->next = p;
        // p = addNode;
        return head;
    }

    if (p == NULL)
    {
        p->next = addNode;
        return p;
    }
    while ( (keyPosition > 1) && (p != NULL) )
    {
        p = p->next;
        keyPosition--;
    }


    addNode->next = p->next;
    p->next = addNode;
    // do not return p -> it will not send starting value
    return head;
}

Node* appendElement(Node *p, int keyElement)
{
    Node *addNode = new Node;
    Node *head = new Node;
    head = p;

    addNode->data = keyElement;
    addNode->next = NULL;

    // if

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = addNode;
    p = head;
    head = 0;
    addNode = 0;
    delete [] head;
    delete [] addNode;
    
    return p;
}

Node* deleteElement(Node *p, int deleteElement)
{
    Node *temp = new Node;
    Node *head = new Node;
    head = p;

    if (p == NULL)
    {
        if (p->data == deleteElement)
        {
            // p->data = NULL;
            p->next = NULL;
        }
    }

    if (p->data != deleteElement)
    {
        while ( (p->data != deleteElement) )
        {
            temp = p;
            p = p->next;
        }
        temp->next = p->next;
        
    }
    else if (p->data == deleteElement)
    {
        head = p->next;
    }
    p = head;
    return p;
}

void popElement(Node *p)
{
    Node *temp = new Node;

    if (p->next == NULL)
    {
        // p->data = NULL;
    }

    while(p->next != NULL)
    {
        temp = p;
        p = p->next;
    }
    temp->next = NULL;
}

void sortingElement(Node *p)
{
    Node *temp = new Node;
    Node * head = new Node;
    head = p;
    temp = p;

    int operation = 0;
    cout << "1. Sorting List in Ascending Order\n" <<
            "2. Sorting List in Descending Order\n" <<
            "Enter your choice: ";
    cin >> operation;

    switch(operation)
    {
        case 1:
        {
            int dummy = 0;
            while(p != NULL)
            {
                temp = p->next;

                while (temp != NULL)
                {

                    if(p->data < temp->data)
                    {
                        dummy = p->data;
                        p->data = temp->data;
                        temp->data = dummy;
                    }
                    temp = temp->next;
                }
                p = p->next;
            }
            break;
        }

        case 2:
        {
            int dummy = 0;
            while(p != NULL)
            {
                temp = p->next;

                while (temp != NULL)
                {

                    if(p->data > temp->data)
                    {
                        dummy = p->data;
                        p->data = temp->data;
                        temp->data = dummy;
                    }
                    temp = temp->next;
                }
                p = p->next;
            }
        }
    }
}

void duplicateElement(Node *p)
{
    Node *tempPresent = new Node;
    Node *tempPrevious = new Node;

    while (p->next != NULL)
    {
        tempPresent = p->next;
        tempPrevious = p;

        while (tempPresent != NULL)
        {
            if (tempPresent->data == p->data)
            {
                if (tempPresent->next == NULL)
                {
                    tempPrevious->next = 0;
                    break;
                }
                
                else if (tempPresent->next != NULL)
                {  
                    tempPrevious->next = tempPresent->next;
                    tempPresent = tempPresent->next;
                }
                
            }
            else
            {
                tempPrevious = tempPresent;
                tempPresent = tempPresent->next;
            }
        }
        if(p->next != NULL)
            p = p->next;
        else    break;
    }
}

void reverseElement(Node *p)
{
    Node *dummy = new Node;

    int choice = 0;

    cout << "1. Reverse via Elements \n" <<
            "2. Reverse via Links \n " >>
            "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            while (p != NULL)
            {
                dummy = p->next;

                while (dummy != NULL)
                {
                    
                }
            }
            break;
        }
    }
}

int main()
{
    int choiceSelection = 0;
    int dummyArray[] = {20, 10, 200, 20, 10, 200, 4 , 6};
    createNode(dummyArray, sizeof(dummyArray)/sizeof(int));
    display(actual);
    cout << endl << endl;
    while (1)
    {
        cout << "\n\nEnter the operations you want to perform: \n" <<
                "1.  Number of Total elements present in the list and the Overall Sum \n" <<
                "2.  Maximum value present in the list \n" <<
                "3.  Searching of an Element in the  list \n" <<
                "4.  Adding Element anywhere in the List. \n" <<
                "5.  Appending Element in the List \n" << 
                "6.  Deleting an Element anywhere from the List \n" <<
                "7.  Poping Element from the List \n" <<
                "8.  Sorting of the List \n" <<
                "9.  Removing the Duplicate Elements in the list \n" <<
                "10. Reversing the List \n" <<
                "\nEnter your choice: ";

        cin >> choiceSelection ; 

        switch (choiceSelection)
        {
            case 1:
            {
                int sum = 0, counts = 0;

                tie(sum, counts) = countLinked(actual);
                cout << "The number of elements present in the list: " << counts << endl;
                cout << "The sum of elements are: " << sum << endl;
                break;
            }

            case 2:
            {
                cout << "The maximum value present in the list: " << maximumValue(actual) << endl;
                break;
            }

            case 3:
            {
                int searchKeyword = 0;
                Node *searchFound = new Node;

                cout << "Enter the number you want to search: " ;
                cin >> searchKeyword;

                searchFound = searchElement(actual, searchKeyword);

                if ( searchFound != NULL)
                    cout << "\nThe search element found at position: " << searchFound->next << " and value: " << searchFound->data << endl;
                else 
                    cout << "No element is found" << endl;  

                cout << "Moving the search element to the front: "  ;

                actual = moveToHead(actual, searchKeyword);
                cout << endl;
                display(actual);
                
                break;
            }

            case 4:
            {
                int insertElement = 0, insertPosition = 0;
                cout << "Enter the number you want to insert: " ;
                cin >> insertElement;
                cout << "Enter at what position you want to insert the Element: " ;
                cin >> insertPosition;

                actual = elementInsertion(actual, insertElement, insertPosition);
                display(actual);

                break;
            }

            case 5:
            {
                int insertElement = 0;
                cout << "Enter the number you want to insert: " ;
                cin >> insertElement;
                appendElement(actual, insertElement);
                display(actual);

                break;
            }

            case 6:
            {
                int element = 0;
                cout << "Enter the number you want to insert: " ;
                cin >> element;
                actual = deleteElement(actual, element);
                display(actual);

                break;
            }

            case 7:
            {
                popElement(actual);
                display(actual);
                break;
            }

            case 8:
            {
                sortingElement(actual);
                display(actual);
                break;
            }

            case 9:
            {
                duplicateElement(actual);
                display(actual);
                break;
            }

            case 10:
            {
                reverseElement(actual);
                display(actual);
                break;
            }
        }

        int select = 0;
        cout << "Do you want to continue? 0/1: ";
        cin >> select;

        if (!select)
            break;
    
    }

}
