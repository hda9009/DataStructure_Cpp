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
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct xQueue
{
    treeNode *data;
    xQueue *next;
    xQueue(treeNode *x) : data(x), next(NULL) {}
    xQueue() : data(NULL), next(NULL) {}
    int size;
    xQueue *head;
    xQueue *tail;
    bool is_queue_empty(void)
    {
        return size == 0;
    }
    void push(treeNode *x)
    {
        xQueue *new_node = new xQueue(x);
        if (is_queue_empty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void pop(void)
    {
        if (is_queue_empty())
            return;
        xQueue *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    treeNode *front(void)
    {
        if (is_queue_empty())
            return NULL;
        return head->data;
    }
    void make_queue_empty(void)
    {
        while (!is_queue_empty())
        {
            pop();
        }
    }
};
xQueue qtreeNode;

struct xStack
{
    int data;
    xStack *next;
    xStack(int x) : data(x), next(NULL) {}
    int size;
    xStack *top;

    bool is_stack_empty(void)
    {
        return size == 0;
    }
    void push(int x)
    {
        xStack *new_node = new xStack(x);
        new_node->next = top;
        top = new_node;
        size++;
    }
    void pop(void)
    {
        if (is_stack_empty())
            return;
        xStack *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int peek(void)
    {
        if (is_stack_empty())
            return -1;
        return top->data;
    }
};

class binary_tree
{
public:
    treeNode *present_node;
    binary_tree() : present_node(NULL) {}
    void create_binary_tree(void);
    int countnodes(treeNode *root);
    int sum_of_nodes(treeNode *root);
    int height_of_tree(treeNode *root);
    int count_leaf_nodes(treeNode *root);
    int count_non_leaf_nodes(treeNode *root);
    int sum_of_range(treeNode *root, int low, int high);
    int add_node(treeNode *root, int val);
    int delete_node(treeNode *root, int val);
    void print_all_nodes(treeNode *root);
};

void binary_tree::create_binary_tree(void)
{
    present_node = new treeNode(0);
    cout << "Enter the Root Value: ";
    cin >> present_node->val;
    present_node->left = NULL;
    present_node->right = NULL;
    cout << "Root Node created with value: " << present_node->val << endl;
    qtreeNode.push(present_node);
    cout << "Enter the Left and Right Values of " << present_node->val << " (Enter 0 for NULL): " << endl;

    while (!qtreeNode.is_queue_empty())
    {
        treeNode *temp = qtreeNode.front();
        cout << "Processing Node: " << temp->val << endl;
        qtreeNode.pop();
        cout << "Enter the Left and Right Values of " << temp->val << " (Enter 0 for NULL): " << endl;
        int left_val, right_val;
        cout << "Enter the Left Value of " << temp->val << ": ";
        cin >> left_val;
        if (left_val != 0)
        {
            temp->left = new treeNode(left_val);
            qtreeNode.push(temp->left);
        }
        else
        {
            temp->left = NULL;
        }
        cout << "Enter the Right Value of " << temp->val << ": ";
        cin >> right_val;
        if (right_val != 0)
        {
            temp->right = new treeNode(right_val);
            qtreeNode.push(temp->right);
        }
        else
        {
            temp->right = NULL;
        }
    }
}

int binary_tree::add_node(treeNode *root, int val)
{
    if (root == NULL)
    {
        root = new treeNode(val);
        return 1;
    }
    if (val < root->val)
    {
        return add_node(root->left, val);
    }
    else if (val > root->val)
    {
        return add_node(root->right, val);
    }
    else
    {
        return 0;
    }
}

int binary_tree::delete_node(treeNode *root, int val)
{
    if (root == NULL)
    {
        qtreeNode.make_queue_empty();
        return 0; // Value not found in the tree
    }

    if (val < root->val)
    {
        qtreeNode.push(root);
        return delete_node(root->left, val);
    }
    else if (val > root->val)
    {
        qtreeNode.push(root);
        return delete_node(root->right, val);
    }
    else
    {
        treeNode *temp;
        if (!qtreeNode.is_queue_empty())
        {
            temp = qtreeNode.front();
        }
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL)
        {
            if (temp->left = root)
            {
                temp
            }
            else if (temp->right = root)
            {
            }
            delete root;
            root = NULL;
            return 1; // Node deleted successfully
        }
        else if (root->left == NULL)
        {
            treeNode *temp = root;
            root = root->right;
            delete temp;
            return 1; // Node deleted successfully
        }
        else if (root->right == NULL)
        {
            treeNode *temp = root;
            root = root->left;
            delete temp;
            return 1; // Node deleted successfully
        }
        else
        {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            treeNode *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            // Copy the inorder successor's content to this node
            root->val = temp->val;

            // Delete the inorder successor
            return delete_node(root->right, temp->val);
        }
    }
}

void binary_tree::print_all_nodes(treeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    print_all_nodes(root->left);
    print_all_nodes(root->right);
}

int binary_tree::countnodes(treeNode *root)
{
    if (root == NULL)
        return 0;
    return (1 + countnodes(root->left) + countnodes(root->right));

    // xQueue temp;
    // int count = 1;
    // if (root == NULL)
    //     return 0;

    // temp.push(root);
    // while (!temp.is_queue_empty())
    // {
    //     treeNode *current = temp.front();
    //     temp.pop();
    //     if (current->left != NULL)
    //     {
    //         temp.push(current->left);
    //         count++;
    //     }
    //     if (current->right != NULL)
    //     {
    //         temp.push(current->right);
    //         count++;
    //     }
    // }
    // return count;
}

int binary_tree::sum_of_nodes(treeNode *root)
{
    if (root == NULL)
        return 0;
    return (root->val + sum_of_nodes(root->left) + sum_of_nodes(root->right));
}

int binary_tree::sum_of_range(treeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;
    if (root->val < low)
        return sum_of_range(root->right, low, high);
    if (root->val > high)
        return sum_of_range(root->left, low, high);
    return (root->val + sum_of_range(root->left, low, high) + sum_of_range(root->right, low, high));
}

int binary_tree::height_of_tree(treeNode *root)
{
    if (root == NULL)
        return 0;
    return (1 + max(height_of_tree(root->left), height_of_tree(root->right)));
}

int binary_tree::count_leaf_nodes(treeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return (count_leaf_nodes(root->left) + count_leaf_nodes(root->right));
}

int binary_tree::count_non_leaf_nodes(treeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return (1 + count_non_leaf_nodes(root->left) + count_non_leaf_nodes(root->right));
}

int main()
{
    binary_tree btree;
    btree.create_binary_tree();
    int total_nodes = btree.countnodes(btree.present_node);
    cout << "Total nodes: " << total_nodes << endl;
    int sum_nodes = btree.sum_of_nodes(btree.present_node);
    cout << "Sum of nodes: " << sum_nodes << endl;
    int height_tree = btree.height_of_tree(btree.present_node);
    cout << "Height of tree: " << height_tree << endl;
    int leaf_nodes = btree.count_leaf_nodes(btree.present_node);
    cout << "Leaf nodes: " << leaf_nodes << endl;
    int non_leaf_nodes = btree.count_non_leaf_nodes(btree.present_node);
    cout << "Non-leaf nodes: " << non_leaf_nodes << endl;
    int sum_range = btree.sum_of_range(btree.present_node, 5, 15);
    cout << "Sum of nodes in range [5, 15]: " << sum_range << endl;
    // bool added = btree.add_node(btree.present_node, 10);
    // if (added)
    //     cout << "Node with value 10 added successfully." << endl;
    // else
    //     cout << "Node with value 10 already exists in the tree." << endl;
    btree.print_all_nodes(btree.present_node);
    // bool deleted = btree.delete_node(btree.present_node, 5);
    // if (deleted)
    //     cout << "Node with value 5 deleted successfully." << endl;
    // else
    //     cout << "Node with value 5 not found in the tree." << endl;

    // btree.print_all_nodes(btree.present_node);
    return 0;
}
