#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

#include <bits/stdc++.h>     // takes alot of time in compilation
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <array>
#include <numeric>
#include <deque>
#include <iomanip>



using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*actual = NULL;

struct doublyNode
{
    struct doublyNode *previous;
    int data;
    struct doublyNode *next;
};

// *************************************************************** //
// ********************* Creating Node *************************** //
// *************************************************************** //

Node * createNode(Node* actual, int dummy[], int n)
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

    return actual;
}


Node * createCircularNode (Node * circularNode, int *a, int n)
{
    Node *last = new Node;

    last = circularNode;

    last->data = a[0];
    last->next = 0;

    for (int i = 1; i < n ; i++)
    {
        Node *temp = new Node;
        temp->data = a[i];
        temp->next = 0;
        last->next = temp;
        last = temp;
        temp = NULL;
        delete [] temp;
    }

    last->next = circularNode;
    last = NULL;
    delete [] last;

    return circularNode;
}


doublyNode * createDoublyNode (struct doublyNode * actual, int ar[], int n)
{
    doublyNode *last = new doublyNode;
    actual->previous = 0;
    actual->data = ar[0];
    actual->next = 0;
    
    last = actual;

    for (int i = 1; i< n; i++)
    {
        doublyNode *temp = new doublyNode;
        temp->previous = last;
        temp->data = ar[i];
        temp->next = last->next;  // last->next = 0;
        last->next = temp;
        last = temp;
    }

    return actual;
}

// *************************************************************** //
// ********************* display Node *************************** //
// ************************************************************** //

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

void displaySingleList(struct Node *p)
{
    if (p!= NULL)
    {
        printf("%d ", p->data);
        displaySingleList(p->next);
    }

    if (p==NULL)    cout << endl;
}

void displayCircularList(struct Node *head)
{
    Node *temp = new Node;
    temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

void displayDoublyList(struct doublyNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// *************************************************************** //
// **************** Operationg on Single Node ******************** //
// *************************************************************** //

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
    cout << "1. Sorting List in Decending Order\n" <<
            "2. Sorting List in Asscending Order\n" <<
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
            "2. Reverse via Links \n " <<
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


Node * concatenate(Node *actual, Node *list)
{
    Node *temp = new Node;
    temp = actual;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = list;
    return temp;
    /*  Here the problem will be: 
    *   It will return the address of last element 
    *   of actual and you got stuck there only.
    *   You cannot come to the starting point if you 
    *   donot have any reference point
    */
}


int isLoop(Node * actual)
{
    Node * p = new Node;
    Node * q = new Node;
    Node * temp = new Node;

    p = q = actual;
    

    while (actual->next != NULL)
    {
        static int i;
        i++;
        actual = actual->next;
        if ( i == 8 )
        {
            temp = actual;
        }
    }
    actual->next = temp;
    int loopExists = 0;

    while ( (q != NULL) )
    {
        q = q->next;
        q = q->next;

        if (p == q)
        {
            loopExists = 1;
            break;
        }    

        p = p->next;

        if (p == q)
        {
            loopExists = 1;
            break;
        }  
    }

    return loopExists;
}


Node * mergingLists(Node *actual, Node *list)
{
    Node *temp = new Node;
    temp = list;
    int movePoint = 2;

    while (movePoint > 0)
    {
        movePoint--;
        actual = actual->next;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = actual;

    return list;
}

int intersectionPoint(Node *actual, Node *list)
{
    int *stackAddrActual = new int[1];
    
    int j = 0;
    while ( (actual != NULL) )
    {
        int *stackTemp = new int[j+1];

        for (int i=0; i< (j); i++)
        {
            stackTemp[i] = stackAddrActual[i];

        }
        stackTemp[j] = (int)(actual);
        stackAddrActual = stackTemp;
        for (int i=0; i<= (j); i++)
        {
            cout << stackAddrActual[i] << ", " << stackTemp[i] << "\t";
        }
        stackTemp = NULL;
        delete [] stackTemp; 
        j++;
        cout << endl;
        actual = actual->next;
    }

}

// *************************************************************** //
// **************** Operationg on Circular Node ****************** //
// *************************************************************** //




// *************************************************************** //
// **************** Operationg on Doubly Node ****************** //
// *************************************************************** //

void insertElementDoublyList(struct doublyNode *head, int element, int position)
{
    struct doublyNode *temp = new doublyNode;
    temp->next = 0;
    temp->data = element;
    temp->previous = 0;
    
    struct doublyNode *follow = new doublyNode;
    struct doublyNode *lead = new doublyNode;  
    follow = head;
    lead = head;

    if (position == 0)
    {
        temp->next = lead;
        lead->previous = temp;
        lead = temp;
    }
    else if (position >= 1) 
    {
        position--;
        lead = lead->next;
    }  

    while ( (position > 0) && (lead != NULL) )
    {
        position--;
        lead = lead->next;
        follow = follow->next;
    }
    if ( (position == 0) || (lead == NULL) )
    {     // after 1st position or any other position
        follow->next = temp;
        temp->next = lead;
    }

    temp = NULL;
    follow = NULL;
    lead = NULL;

    delete [] temp;
    delete [] follow;
    delete [] lead;
}

struct doublyNode * deleteElementDoublyList(struct doublyNode *head, int element)
{
#if 0   // This is using three pointers
    struct doublyNode *follow = new doublyNode;
    struct doublyNode *lead = new doublyNode;  
    follow = head;
    lead = head;

    // follow - head - lead -> sequence follow
    int elementFound = 0;
    if (head->data == element)  // the first element
    {
        lead = lead->next;
        head->data = 0;
        head->next = 0;
        head = lead;
        elementFound = 1;
    }
    else
    {
        lead = lead->next;
        lead = lead->next;
        head = head->next;
    }
    while  ( (head->data != element) && (lead != NULL) && (!elementFound) )
    {           // checking starts with second element
        
        if (lead->next == NULL) 
        {       // checking the last element if matched
            lead->previous = 0;
            lead->data = 0;
            head->next = 0;
            elementFound = 1;
            break;
        }
        follow = follow->next;
        head = head->next;
        lead = lead->next;
    }

    if ( (head->data == element) && (!elementFound) )  // when head is found the element
    {
        
        follow->next = lead;
        lead->previous = follow;
        head->previous = 0;
        head->data = 0;
        head->next = 0;
    }

    follow = NULL;
    lead = NULL;

    delete [] follow;
    delete [] lead;
    return head;
#endif

    // With a single pointer we can do it

    struct doublyNode *lead = new doublyNode;  
    lead = head;

    while ( (lead->data != element) && (lead->next != NULL) )
    {
        lead = lead->next;
    }

    if (lead->data == element)
    {
        if (lead->previous == NULL)
        {   // This is for first node
            
            lead = lead->next;
            lead->previous = 0;
            head = lead;
        }
        else if (lead->next == NULL)
        {   // This is for last node
            lead->previous->next = 0;
        }
        else
        {
            lead->previous->next = lead->next;
            lead->next->previous = lead->previous;
        }
    }

    return head;

}

struct doublyNode * reverseDoublyList(struct doublyNode *head)
{
    
    struct doublyNode *temp = new doublyNode;
    temp = head->next;

    while ( ( head != NULL) && (temp->next != NULL) )
    {
        
        if (head->previous == NULL)
        {
            head->next = 0;
            head->previous = temp;
            head = head->previous;
            temp = temp->next;
        }
        else
        {
            head->next = head->previous;
            head->previous = temp;
            head = head->previous;
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
    {
        head->next = head->previous;
        head->previous = temp;

        temp->next = head;
        temp->previous = 0;
    }
    
    head = temp;

        temp = NULL;
        delete [] temp;

    return head;
}

// *************************************************************** //
// ********************** main *********************************** //
// *************************************************************** //

int main()
{
    
    int choiceSelection = 0;
    int dummyArray[] = {20, 10, 200, 20, 10, 200, 4 , 6};
    actual = createNode(actual, dummyArray, sizeof(dummyArray)/sizeof(int));
    displaySingleList(actual);
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
                "11. Concatenate the List \n" <<
                "12. Check if the Linked List in the Loop or not \n" <<
                "13. Intersection of two Linked List and finding the intersection point \n" <<
                "\n" <<
                "14. Circular Linked List? \n" <<
                "15. Doubly Linked List? \n" <<
                "16. Doubly Circular Linked List? \n" <<
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
                displaySingleList(actual);
                
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
                displaySingleList(actual);

                break;
            }

            case 5:
            {
                int insertElement = 0;
                cout << "Enter the number you want to insert: " ;
                cin >> insertElement;
                appendElement(actual, insertElement);
                displaySingleList(actual);

                break;
            }

            case 6:
            {
                int element = 0;
                cout << "Enter the number you want to insert: " ;
                cin >> element;
                actual = deleteElement(actual, element);
                displaySingleList(actual);

                break;
            }

            case 7:
            {
                popElement(actual);
                displaySingleList(actual);
                break;
            }

            case 8:
            {
                sortingElement(actual);
                displaySingleList(actual);
                break;
            }

            case 9:
            {
                duplicateElement(actual);
                displaySingleList(actual);
                break;
            }

            case 10:
            {
                reverseElement(actual);
                displaySingleList(actual);
                break;
            }
            
            case 11:
            {
                int arr[] = {901, 902, 903,905, 906, 908, 998};
                Node * list2 = new Node;
                list2 = createNode(list2, arr, sizeof(arr)/ sizeof(int));
                concatenate(actual, list2);
                displaySingleList(actual);
                break;
            }

            case 12:
            {
                cout << "Manually merging two list and Looping them " << endl;
                
                int arr[] = {901, 902, 903,905, 906, 908, 998};
                Node * list2 = new Node;
                list2 = createNode(list2, arr, sizeof(arr)/ sizeof(int));
                concatenate(actual, list2);

                displaySingleList(actual);

                int condition = isLoop(actual);
                cout << endl;
                if (condition)
                    cout << "Looping Exists" << endl;
                else
                    cout << "Looping does not Exists" << endl;

                break;
            }

            case 13:
            {
                cout << "Manually merging the list in actual list " << endl;
                
                int arr[] = {901, 902, 903,905, 906, 908, 998};
                Node * list2 = new Node;
                list2 = createNode(list2, arr, sizeof(arr)/ sizeof(int));
                
                list2 = mergingLists(actual, list2);

                displaySingleList(list2);

                intersectionPoint(actual, list2);
                break;
            }
            case 14:
            {
                static int repeat;

                static Node *circularNode = new Node;
                if (!repeat)
                {
                    int arr[] = {1,2,3,4, 5, 6, 7, 8};
                    circularNode = createCircularNode (circularNode, arr, sizeof(arr)/ sizeof(int));
                    displayCircularList(circularNode);
                    repeat++;
                }

                int choiceSelection = 0;
                cout << "\n\nEnter the operations you want to perform on Circular Linked List: \n" <<
                        "1.  Inserting an Element in the list \n" <<
                        "2.  Deleting an Element from the list \n" <<
                        "\nEnter your choice: ";
                cin >> choiceSelection ; 

                switch (choiceSelection)
                {
                    case 1:
                    {
                        int insertPosition = 0;
                        int insertElement = 0;
                        cout << "Enter the Element you want to insert: ";
                        cin >> insertElement;
                        cout << "Enter the position you want to insert the element: ";
                        cin >> insertPosition;

                        // insertElementCircularList(circularNode, insertElement, insertPosition);

                        displayCircularList(circularNode);

                        break;
                    }
                }

                break;
            }

            case 15:
            {
                static int repeat;
                
                static doublyNode *doubleNode = new doublyNode;
                if (!repeat)
                {
                    int arr[] = {1,2,3,4,5,6,7,8};
                    doubleNode = createDoublyNode (doubleNode, arr, sizeof(arr)/ sizeof(int));
                    repeat++;
                }

                displayDoublyList(doubleNode);

                int choiceSelection = 0;
                cout << "\n\nEnter the operations you want to perform on Circular Linked List: \n" <<
                        "1.  Inserting an Element in the list \n" <<
                        "2.  Deleting an Element from the list \n" <<
                        "3.  Reversing the Element in the list \n" <<
                        "\nEnter your choice: ";
                cin >> choiceSelection ; 

                switch (choiceSelection)
                {
                    case 1:
                    {
                        int insertPosition = 0;
                        int insertElement = 0;
                        cout << "Enter the Element you want to insert: ";
                        cin >> insertElement;
                        cout << "Enter the position you want to insert the element: ";
                        cin >> insertPosition;

                        insertElementDoublyList(doubleNode, insertElement, insertPosition);

                        displayDoublyList(doubleNode);

                        break;
                    }

                    case 2:
                    {
                        int insertElement = 0;
                        cout << "Enter the Element you want to delete: ";
                        cin >> insertElement;
                        doubleNode = deleteElementDoublyList(doubleNode, insertElement);
                        displayDoublyList(doubleNode);
                        break;
                    }

                    case 3:
                    {
                        doubleNode = reverseDoublyList(doubleNode);
                        displayDoublyList(doubleNode);
                        break;
                    }
                }

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
