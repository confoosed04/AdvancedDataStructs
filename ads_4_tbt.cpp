#include<iostream>
using namespace std;

class tbtnode
{
    string data;
    bool rbit;
    bool lbit;
    tbtnode *right;
    tbtnode *left;
    friend class tbt;
    public:
        tbtnode();
};

tbtnode :: tbtnode()
{
    lbit=0;
    rbit=0;
}

class tbt
{
    tbtnode *head;
    public:
        void create();
        void preorder();
        tbtnode *presuccr(tbtnode *temp);
        void inorder();
        tbtnode *inordersucc(tbtnode *temp);
        tbt();

};

tbt::tbt()
{ 
    head = new tbtnode;
    head->rbit=1;
    head->left=head;
    head->right=head;

}

void tbt:: create()
{
    char ch, ch2;
    tbtnode *root = new tbtnode;
    cout<<"Enter root node: "<<endl;
    cin>>root->data;
    head->lbit=1;
    root->left=head;
    root->right=head;
    head->left=root;
    do
    {
        int flag=0;
    
        tbtnode *temp=root;
        tbtnode *curr = new tbtnode;
        cout<<"Enter data for curr node: "<<endl;
        cin>>curr->data;
        while(flag==0)
        {
            cout<<"Enter your choice to insert the node(L/R) of "<<temp->data<<" ";
            cin>>ch;
            if(ch=='l')
            {
                if(temp->lbit==0)
                {
                    curr->right=temp;
                    curr->left=temp->left;
                    temp->left=curr;
                    temp->lbit=1;
                    flag=1;
                }
                else 
                {
                    temp=temp->left;
                }
            }
            if(ch=='r')
            {
                if(temp->rbit==0)
                {
                    curr->left=temp;
                    curr->right=temp->right;
                    temp->right=curr;
                    temp->rbit=1;
                    flag=1;
                }
                else
                {
                    temp=temp->right;
                }
            }

        }cout<<"do you want to add more nodes (Y/N)"<<endl;
         cin>>ch2;
    }while(ch2=='y');
}


void tbt :: inorder()
{
    tbtnode *temp=head;
    while(1)
    {
        temp=inordersucc(temp);
        if(temp==head)
            break;
        cout<<temp->data<<" ";
    }
}

tbtnode *tbt :: inordersucc(tbtnode *temp)
{
    tbtnode *x=temp->right;
    if(temp->rbit==1)
    {
        while(x->lbit==1)
        {
            x=x->left;
        }
    }
    return x;
}

void tbt :: preorder()
{
    tbtnode *temp=head->left;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        while(temp->lbit!=0)
        {
            temp=temp->left;
            cout<<temp->data<<" ";

        }
        while(temp->rbit==0)
        {
            temp=temp->right;
        }
        temp= temp->right;
    }


}



int main()
{
    int choice;
    tbt bt;
    bt.create();
    cout<<endl;
    while(1)
    {
        cout<<"Enter from menu "<<endl;
        cout<<"1)inorder\n2)preorder\n3)exit\n"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"inorder is :"<<endl;
            bt.inorder();
            cout<<endl;
            break;

            case 2:
            cout<<"preorder is :"<<endl;
            bt.preorder();
            cout<<endl;
            break;

            case 3:
            exit;

            default:
            cout<<"error";
            break;
        }

    }
    
}