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

struct treeNode
{
    treeNode *left;
    int data;
    treeNode *right;
}*Root;


struct Queue
{
    int data;
    Queue *next;
    treeNode ** Q;
    int size;
    int counts = 0;

    bool isEmpty(void);
    void enqueue(treeNode *node);
    treeNode * dequeue(void);
    
}*headQueue, *tempQueue, *tempDequeue;

void createTree();


void createTree()
{   
    treeNode *presentNode = new treeNode {NULL};


    cout << "Enter the Root Value: ";
    cin >> Root->data;
    Root->left = 0;
    Root->right = 0;

    headQueue->enqueue(Root);      // Insert the address in the queue

    while (headQueue->isEmpty())
    {
        presentNode = headQueue->dequeue();  // presentNode = Root;

        char leftNodePresent = 0;
        char rightNodePresent = 0;
        cout << "Left Node present?: Y/N): ";
        cin >> leftNodePresent;

        
        
        switch (leftNodePresent)
        {
            case 'Y':
            {
                treeNode *checkDummy = new treeNode;  // Requires to reinitialize again
                cout << "Enter the value of Left Child Node: ";
                cin >> checkDummy->data;
                checkDummy->left = 0;
                checkDummy->right = 0;

                presentNode->left = checkDummy;
                headQueue->enqueue(checkDummy);

                checkDummy = NULL;
                delete [] checkDummy;
                break;
            }

            case 'N':
            {
                presentNode->left = 0;
                break;
            }
        }

        cout << "Right Node present?: Y/N): ";
        cin >> rightNodePresent;

        switch (rightNodePresent)
        {
            case 'Y':
            {
                treeNode *checkDummy = new treeNode;  // Requires to reinitialize again

                cout << "Enter the value of Right Child Node: ";
                cin >> checkDummy->data;
                checkDummy->left = 0;
                checkDummy->right = 0;

                presentNode->right = checkDummy;
                headQueue->enqueue(checkDummy);

                checkDummy = NULL;
                delete [] checkDummy;
                break;
            }

            case 'N':
            {
                presentNode->right = 0;
                break;
            }
        }
    }  

}

void Queue::enqueue(treeNode *node)
{
    if (headQueue->size > headQueue->counts)
    {
        if (!headQueue->counts)
        {
            headQueue->data = (int)node;
            headQueue->next = 0;
        }
        else
        {
            Queue *dummy = new Queue;
            dummy->data = (int) node;
            dummy->next = 0;

            tempQueue->next = dummy;
            tempQueue = dummy;

            dummy = NULL;
            delete [] dummy;

        }

        headQueue->counts++;
    }
    else
    {
        cout << "\nTree/ Queue is full \n" << endl;
    }
}

treeNode * Queue::dequeue(void)
{
    treeNode *dummyNode = new treeNode;
    if (tempDequeue->next != NULL)
    {
        tempDequeue = tempDequeue->next;
    }    
    dummyNode = (treeNode*)tempDequeue->data;

    return (dummyNode);
}


bool Queue::isEmpty(void)
{
    if (headQueue->size != headQueue->counts)   return 1;
    else                                        return 0;
}

void preOrder(treeNode *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        preOrder(head->left);
        preOrder(head->right);
    }
}

int main()
{
    Root = new treeNode;
    headQueue = new Queue;
    tempQueue = headQueue;
    tempDequeue = headQueue;

    cout << "Enter the total Number of node (Queue Size): ";
    cin >> headQueue->size;

    createTree();
    preOrder(Root);

}
