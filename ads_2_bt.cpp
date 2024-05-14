#include <iostream>

using namespace std;

int top;
class treenode
{
    int data;
    treenode *left, *right;
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree()
    {
        root = NULL;
    }
    void create_nr();
    void create_r(treenode *root);
    void create_r();
    void inorder_r(treenode *root);
    void inorder_r();
    void preorder_r(treenode *root);
    void preorder_r();
    void postorder_r(treenode *root);
    void postorder_r();
    void inorder_nr();
    void preorder_nr();
    void postorder_nr();
};

class stack
{
    treenode *data_stack[30];
    public:
        stack()
        {
            top = -1;
        };
        void push(treenode *temp);
        treenode *pop();
        int isempty();
        friend class tree;
};

void tree::create_nr()
{
    if (root == NULL)
    {
        root = new treenode;
        cout << "Enter data for root node: " << endl;
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
    }

    char choice1;
    char choice;

    do
    {
        treenode *temp, *curr;
        temp = root;
        int flag = 0;

        curr = new treenode;
        curr->left = NULL;
        curr->right = NULL;
        cout << "Enter data for node: " << endl;
        cin >> curr->data;

        while (flag == 0)
        {
            cout << "Do you want to enter the node to the left or to the right of " << temp->data << "? (l or r)" << endl;
            cin >> choice;

            if (choice == 'l')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        cout << "Do you want to enter new node? (y or n)" << endl;
        cin >> choice1;
    } while (choice1 == 'y');
}

void tree::create_r()
{
    if (root == NULL)
    {
        root = new treenode;
        cout << "Enter data for root node: " << endl;
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
    }
    create_r(root);
}
void tree::create_r(treenode *temp)
{
    char choice, choice1;

    {
        cout << "Do you want to enter data to the left of " << temp->data << "? (y or n)" << endl;
        cin >> choice;
        if (choice == 'y')
        {
            treenode *curr;
            curr = new treenode;
            curr->left = NULL;
            curr->right = NULL;

            cout << "Enter Data:" << endl;
            cin >> curr->data;

            temp->left = curr;
            create_r(curr);
        }

        cout << "Do you want to enter data to the right of " << temp->data << "? (y or n)" << endl;
        cin >> choice;
        if (choice == 'y')
        {
            treenode *curr;
            curr = new treenode;
            curr->left = NULL;
            curr->right = NULL;

            cout << "Enter Data:" << endl;
            cin >> curr->data;

            temp->right = curr;
            create_r(curr);
            
        }
    }
}

void tree::inorder_r()
{
    inorder_r(root);
}
void tree::inorder_r(treenode *root)
{
    if (root != NULL)
    {
        inorder_r(root->left);
        cout << root->data << " " << endl;
        inorder_r(root->right);
    }
}

void tree::preorder_r()
{
    preorder_r(root);
}
void tree::preorder_r(treenode *root)
{
    if (root != NULL)
    {
        cout << root->data << " " << endl;
        preorder_r(root->left);
        preorder_r(root->right);
    }
}

void tree::postorder_r()
{
    postorder_r(root);
}
void tree::postorder_r(treenode *root)
{
    if (root != NULL)
    {
        postorder_r(root->left);
        postorder_r(root->right);
        cout << root->data << " " << endl;
    }
}

int stack::isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
treenode *stack::pop()
{
    treenode *temp;
    temp = data_stack[top];
    top--;
    return temp;
}
void stack::push(treenode *temp)
{
    top++;
    data_stack[top] = temp;
}

void tree::inorder_nr()
{
    treenode *temp;
    temp = root;
    stack s;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
        if (s.isempty() == 1)
        {
            break;
        }
        temp = s.pop();
        std::cout << temp->data << " " << endl;
        temp = temp->right;
    }
}
void tree::preorder_nr()
{
    treenode *temp;
    temp = root;
    stack s;
    while (temp != NULL)
    {
        std::cout << temp->data << " " << endl;
        s.push(temp);
        temp = temp->left;
        if (s.isempty() == 1)
        {
            break;
        }
        temp = s.pop();
        temp = temp->right;
    }
}

void tree::postorder_nr()
{
    stack s;
    treenode *temp = root;
    while(1)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
            
        }
        cout << s.data_stack[top]->right;
        if (s.data_stack[top]->right == NULL)
        {
            temp = s.pop();
            cout << temp->data << " " << endl;
            
        }
        while ( s.isempty() == 0 && s.data_stack[top]->right == temp)
        {
            temp = s.pop();
            cout << temp->data << " " << endl;
        }
        
        if (s.isempty() == 1)
        {
            break;
        }


        temp = s.data_stack[top]->right;
    }
}

int main()
{
    tree bt;
    char choice;
    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Create a binary tree (Non-Recursive)" << endl;
        cout << "2. Display the tree in inorder" << endl;
        cout << "3. Display the tree in preorder" << endl;
        cout << "4. Display the tree in postorder" << endl;
        cout << "5. Create a binary tree (Recursive)" << endl;
        cout << "6. Display the tree in inorder recursive" << endl;
        cout << "7. Display the tree in preorder recursive" << endl;
        cout << "8. Display the tree in postorder recursive" << endl;
        cout << "9. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            bt.create_nr();
            break;
        case '2':
            bt.inorder_r();
            break;
        case '3':
            bt.preorder_r();
            break;
        case '4':
            bt.postorder_r();
            break;
        case '5':
            bt.create_r();
            break;
        case '6':
            bt.inorder_nr();
            break;
        case '7':
            bt.preorder_nr();
            break;
        case '8':
            bt.postorder_nr();
            break;
        case '9':
           exit;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != '9');
}