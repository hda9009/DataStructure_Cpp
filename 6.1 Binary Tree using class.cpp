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

// ***************************************************************************************** //
// ****************************  Definitions ********************************************** //
// ***************************************************************************************** //


struct tree
{
    tree *leftValue;
    int data;
    tree *rightValue;
};

struct Stack
{
    int data;
    Stack *next;
};

struct Queue
{
    int data;
    Queue *next;
}*actualQueue , *pushQueue, *popQueue;

// ***************************************************************************************** //
// ************************* Creating Class ********************************************** //
// ***************************************************************************************** //

class binaryTree
{
    private:
        tree *Root = new tree;

        int queueSize = 0;
        int queueCounts = 0;

        Stack *actualStack = new Stack;

    public:
        binaryTree(int size = 0);

        binaryTree createNodeTree(void);
        void createQueue(tree *headTree);
        void queuePush(tree *headTree);
        int queuePop(void);
        bool isQueueEmpty();
        void displayTree(void);

        void stackPush(tree *headTree);
        int stackPop(void);

};

// ***************************************************************************************** //
// ************************* Tree Operations ********************************************** //
// ***************************************************************************************** //

binaryTree::binaryTree(int size)
{
    actualQueue = new Queue;
    this->queueSize = size;

    pushQueue = actualQueue;
    popQueue = actualQueue;
}

binaryTree binaryTree::createNodeTree()
{
    tree *tempRoot = new tree;

    cout << "Enter Root Value: ";
    cin >> this->Root->data;
    this->Root->leftValue = 0;
    this->Root->rightValue = 0;

    this->queuePush(this->Root);

    while ( this->isQueueEmpty())
    {
        tempRoot =  (tree*)this->queuePop();

        int leftChild = 0, rightChild = 0;

        cout << "Enter Child values for " << tempRoot->data << ": ";
        cout << "\nLeft Child: ";
        cin >> leftChild;
        cout << "Right Child: ";
        cin >> rightChild;

        if (leftChild <= 0)
        {
            tempRoot->leftValue = 0;
        }
        else
        {
            tree *dummyTree = new tree;
            dummyTree->data = leftChild;
            dummyTree->leftValue = 0;
            dummyTree->rightValue = 0;

            tempRoot->leftValue = dummyTree;
            this->queuePush(dummyTree);

            dummyTree = NULL;
            delete [] dummyTree;
        }

        if (rightChild <= 0)
        {
            tempRoot->rightValue = 0;
        }
        else
        {
            tree *dummyTree = new tree;
            dummyTree->data = rightChild;
            dummyTree->leftValue = 0;
            dummyTree->rightValue = 0;

            tempRoot->rightValue = dummyTree;
            this->queuePush(dummyTree);

            tempRoot = dummyTree;
            tempRoot = NULL;
            dummyTree = NULL;
            delete [] dummyTree;
            delete [] tempRoot;
        }
    }
}


// ***************************************************************************************** //
// ************************* Queue Operations ********************************************** //
// ***************************************************************************************** //

    void binaryTree::queuePush(tree *headTree)
    {
        if ( this->queueCounts <= (this->queueSize - 1) )
        {
            if (this->queueCounts == 0)
            {
                actualQueue->data = (int)headTree;
                actualQueue->next = 0;
            }
            else
            {
                Queue *dummyQueue = new Queue;
                dummyQueue->data = (int)headTree;
                dummyQueue->next = 0;
                pushQueue->next = dummyQueue;
                pushQueue = dummyQueue;

                dummyQueue = NULL;
                delete [] dummyQueue;
            }
            this->queueCounts++;
        }
        else
            cout << "\nQueue is full \n" << endl;
    }

    int binaryTree::queuePop(void)
    {
        static int popCounts;
        int value = 0;

        if( (!popCounts) || (popCounts == (this->queueSize - 1)) )
        {   
            value = actualQueue->data;
        }
        else
        {
            actualQueue = actualQueue->next;
            popQueue->next = NULL;
            popQueue->data = 0;
            popQueue = actualQueue;

            value = actualQueue->data;
        }
        popCounts++;
        return value;
    }

    bool binaryTree::isQueueEmpty()
    {
        if (this->queueCounts < this->queueSize)    return 1;
        return 0;
    }



// ***************************************************************************************** //
// ************************* Stack Operations ********************************************** //
// ***************************************************************************************** //

void binaryTree::stackPush(tree *headTree)
{
    static int pushCounts;

    if (pushCounts < this->queueSize)
    {
        static Stack *tempStack = new Stack;
        if (!pushCounts)
        {
            this->actualStack->data = (int)headTree;
            this->actualStack->next = 0;
            tempStack = this->actualStack;
        }
        else
        {
            Stack *dummyStack = new Stack;
            dummyStack->data = (int)headTree;
            dummyStack->next = 0;

            tempStack->next = dummyStack;
            tempStack = dummyStack;

            dummyStack = NULL;
            delete [] dummyStack;
        }

        pushCounts++;
    }
    else
        cout << "\nStack is Full\n" << endl;
}

int binaryTree::stackPop(void)
{
    Stack *headStack = new Stack;
    Stack *followStack = new Stack;
    headStack = this->actualStack;
    followStack = this->actualStack;

    if( headStack->next != NULL)
    {
        headStack = headStack->next;
    }

    while(headStack->next != NULL)
    {
        headStack = headStack->next;
    }
    int value = headStack->data;

    followStack->next = 0;

    headStack = NULL;
    followStack = NULL;
    delete [] headStack;
    delete [] followStack;

    return value;

}


// ***************************************************************************************** //
// ***************************  Operations ************************************************ //
// ***************************************************************************************** //

    void binaryTree::displayTree()
    {
        tree *presentNode = this->Root;
        static int Counts;

        cout << "\nTree Nodes Values are: \n" << presentNode->data << "  ";
        while ( (presentNode != NULL) && (Counts < ( this->queueSize - 1) ) )
        {
            if (presentNode->leftValue != NULL)
            {
                this->stackPush(presentNode->leftValue);
                cout << presentNode->leftValue->data << "  ";
                Counts++;
            }
            if (presentNode->rightValue != NULL)
            {
                this->stackPush(presentNode->rightValue);
                cout << presentNode->rightValue->data << "  ";
                Counts++;
            }
            presentNode = (tree*)this->stackPop();
        }
    }

int main(void)
{
    actualQueue = new Queue;

    binaryTree strictBinaryTree(7);
    strictBinaryTree.createNodeTree();
    strictBinaryTree.displayTree();
}
