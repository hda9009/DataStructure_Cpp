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


struct Stack
{
    Stack *previous;
    int data;
    Stack *next;

    int counts = 0;
    bool isEmpty(void);
}*headStack, *tempStack;



void createTree();
void preOrderIterative(treeNode *head);
treeNode* popStack(Stack *head);
void levelTraversal(treeNode *head);



void createTree()
{   
    treeNode *presentNode = new treeNode {NULL};


    cout << "Enter the Root Value: ";
    cin >> Root->data;
    Root->left = 0;
    Root->right = 0;

    headQueue->enqueue(Root);      // Insert the address in the queue

    while (!headQueue->isEmpty())
    {
        presentNode = headQueue->dequeue();  // presentNode = Root;

        cout << "\nEnter Child Value for Node: " << presentNode->data << endl;
        int leftNodePresent = 0;
        int rightNodePresent = 0;
        cout << "Left Node present?: 1/0): ";
        cin >> leftNodePresent;

        
        
        switch (leftNodePresent)
        {
            case 1:
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

            case 0:
            {
                presentNode->left = 0;
                break;
            }
        }

        cout << "Right Node present?: 1/0: ";
        cin >> rightNodePresent;

        switch (rightNodePresent)
        {
            case 1:
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

            case 0:
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
    if (headQueue->size != (headQueue->counts ))   return 0;
    else                                        return 1;
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

void inOrder(treeNode *head)
{

    if (head != NULL)
    {
        inOrder(head->left);
        cout << head->data << " ";
        inOrder(head->right);
    }
}

void postOrder(treeNode *head)
{

    if (head != NULL)
    {
        inOrder(head->left);
        inOrder(head->right);
        cout << head->data << " ";
    }
}

void pushStack(treeNode *headtree)
{
    if (!headStack->counts)
    {
        headStack->previous = 0;
        headStack->data = (int)headtree;
        headStack->next = 0;
        tempStack = headStack;
        headStack->counts++;
    }
    else
    {
        Stack *dummy = new Stack;
        dummy->previous = tempStack;
        dummy->data = (int)headtree;
        dummy->next = 0;
        tempStack->next = dummy;
        tempStack = dummy;

        headStack->counts++;

        dummy = NULL;
        delete [] dummy;
    }
}

treeNode* popStack(Stack *head)
{
    if (headStack->counts == 0)
    {
        return NULL;
    }

    headStack->counts--;

    if (head->next != NULL)
    {
        head = head->next;

        while (head->next != NULL)
        {
            head = head->next;
            headStack = headStack->next;
        }
        int value = head->data;

        headStack->next = 0;        // remove the next node;

        head = NULL;
        
        return (treeNode*)(value);
    }
    
    return (treeNode*)(headStack->data);
}

bool Stack::isEmpty(void)
{
    if (headStack->counts == 0) return 1;
    else                return 0;
}

void preOrderIterative(treeNode *head)
{
    while ( (head != NULL) || ( !headStack->isEmpty() )  )
    {
        cout << head->data << " ";
        if (head->left != NULL)
        {
            pushStack(head);
            head = head->left;
        }
        else if (head->right != NULL)
        {
            pushStack(head);
            head = head->right;
        }   
        else
        {
            head = popStack(headStack);

            if (head == NULL){
                break;
            }

            if (head->right != NULL)
            {
                head = head->right;   
            }      
        }
    }
}

void inOrderIterative(treeNode *head)
{
    while ( (head != NULL) || ( !headStack->isEmpty() )  )
    {
        if (head->left != NULL)
        {
            pushStack(head);
            head = head->left;
        }
        else if (head->right != NULL)
        {
            pushStack(head);
            head = head->right;
        }   
        else
        {
            cout << head->data << " ";
            head = popStack(headStack);
            if (head == NULL){
                break;
            }

            if (head->right != NULL)
            {
                cout << head->data << " ";
                head = head->right;   
            }      
        }
    }
}

void levelTraversal(treeNode *head)
{

}


int countNode(treeNode *head)
{
    int lChild=0, rChild= 0;

    if (head != NULL)
    {
        if (head->left != NULL)
            lChild = countNode(head->left);
        if (head->right != NULL)
            rChild = countNode(head->right);

        return (lChild + rChild + 1);
    }
    return 0;
}

int sumNode(treeNode *head)
{
    int lChild = 0, rChild = 0, sum = 0;
    
    if (head != NULL)
    {
        if (head->left != NULL)
            lChild = sumNode(head->left);
        if (head->right != NULL)
            rChild = sumNode(head->right);

        return (lChild + rChild + head->data);
    }
    return 0;
} 

int countLeafNodes(treeNode *head)
{
    int lChild = 0, rChild = 0;
    if (head != NULL)
    {
        if (head->left != NULL)
        {
            lChild = sumNode(head->left);
        }    

        if (head->right != NULL)
        {    
            rChild = sumNode(head->right);
        }    

        if (head->left == NULL && head->right == NULL)
        {
            return (lChild + rChild + 1);
        }

        return 0;
    }
} 

int countNonLeafNodes(treeNode *head)
{
    int lChild = 0, rChild = 0;
    if (head != NULL)
    {
        if (head->left != NULL)
        {
            lChild = sumNode(head->left);
        }    

        if (head->right != NULL)
        {    
            rChild = sumNode(head->right);
        }    

        if ( (head->left == NULL && head->right != NULL) || (head->left != NULL || head->right == NULL)  )
        {
            return (lChild + rChild + 1);
        }

    }
    return 0;
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
    // cout << "PreOrder: ";
    // preOrder(Root);
    // cout << "\nInOrder: ";
    // inOrder(Root);
    // cout << "\nPostOrder: ";
    // postOrder(Root);

    headStack = new Stack;

    cout << "\nPreOrder: ";
    preOrderIterative(Root);

    cout << "\nPreOrder: ";
    inOrderIterative(Root);

    cout << "\nTotal Number of Nodes in the Tree are: " << countNode(Root);
    cout << "\nTotal Sum of Nodes in the Tree are: " << sumNode(Root);
    cout << "\nLeaf nodes in the Tree are: " << countLeafNodes(Root);
    cout << "\nNon-Leaf nodes with degree 1 in the Tree are: " << countNonLeafNodes(Root);
}
