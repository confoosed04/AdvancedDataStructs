
#include <stack>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class gnode
{
    int id;
    string name;
    gnode* next;
public:
    gnode() {
        id = 0;
        name = "";
        next = nullptr;
    }
    friend class graph;
};

class graph 
{
    int n;
    gnode* head[10];
public:
    graph() {
        n = 0;
        cout << "Enter the number of friends: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            head[i] = new gnode;
            head[i]->id = i;
            cout << "Enter the username for id " << i+1 << ": ";
            cin >> head[i]->name;
            head[i]->next=NULL;
        }
    }
    void create();
    void display();
    void dfs_r();
    void dfs_nr();
    void dfs_r(int v,int user[10]);
    void BFS();
};

void graph::create() 
{
    int v;
    char ans;
    gnode* temp;
    gnode* curr;
    for (int i = 0; i < n; i++) {
        temp = head[i];
        cout << "Do you want to add adjacent vertex to "<<i+1<<" (y/n): \n";
             cin >> ans;
        while (ans == 'y' || ans == 'Y'){
   
            cout << "Enter adjacent vertex for friend " << i+1 << ": ";
            cin >> v;
            v=v-1;
            if (v == i) {
                cout << "Self loops not allowed!" << endl;
            } 
            else {
                curr = new gnode;
                curr->id = v;
                curr->next = NULL; // Link the new node appropriately
                temp->next = curr;
                temp=temp->next;
            }
            cout << "Do you want to add another adjacent vertex to "<<i+1<<" (y/n): \n";
     cin >> ans;
        }
    }
};

void graph::display() 
{
    gnode* temp;
    for (int i = 0; i < n; i++) {
        temp = head[i];
        cout << "friend " << i+1 << ": " << temp->name << "\n";
        temp = temp->next; // Move to the first adjacent vertex
        while (temp != nullptr) {
            cout << "Adjacent vertex: " << temp->id+1 << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }
};

void graph::dfs_r()
{
int user[10];
for(int i=0;i<n;i++)
{
user[i]=0;
}
int uid;
cout<<"Enter the starting friend's id :"<<endl;
cin>>uid;
uid=uid-1;
dfs_r(uid,user);
cout<<endl;
};

void graph::dfs_r(int v,int user[10])
{
cout<<head[v]->name<<"\t";
user[v]=1;
gnode *temp = head[v]->next;

while(temp!=NULL)
{
if(!user[temp->id])
{
dfs_r(temp->id,user);
}
temp=temp->next;
}
};



void graph::dfs_nr()
{
    int visited[n],v;
    gnode *temp;
    cout<<"enter starting vertex\n";
    cin>>v;
    v=v-1;
    cout<<"DFS order";
    for(int i=0;i<n;i++)
    visited[i]=0;
    stack<int> s;
    s.push(v);
    visited[v]=1;
    cout<<head[v]->name<<"\t";
    while(!s.empty()){
        v=s.top();
        temp=head[v];
        
            while(temp!=NULL && visited[temp->id]==1)
            {temp=temp->next;}
        
        if(temp!=NULL){
            s.push(temp->id); 
             visited[temp->id]=1;
                 cout<<head[temp->id]->name<<"\t";
        }
        else{
            s.pop();
        }       
    
}
}

void graph::BFS() {
    int visited[n];
    int v,w;
    cout<<"enter 1st vertex\n";
    cin>>v;
    v=v-1;
for(int i=0;i<n;i++)
visited[i]=0;
queue<int> q;
q.push(v);
visited[v]=1;
cout<<head[v]->name<<"\t";
gnode *temp = NULL;
while(!q.empty())
    {
    v=q.front();
    q.pop();
    temp=head[v]->next;
        while(temp!=NULL){
            w=temp->id;
                if(!visited[w])
                {
                q.push(w);
                visited[w]=1;
                cout<<head[w]->name<<"\t";
                }
            temp=temp->next;
        }
}
}


int main() {
    graph g;
    g.create();
    g.display();
    bool visited[10] = {false};
    cout << "DFS traversal(recursive)\n";
    g.dfs_r();
    cout << "********************************************************\n";
    cout << "DFS traversal(non-recursive)\n";
    g.dfs_nr();
    cout << "********************************************************\n";
     cout << "BFS traversal\n";
    g.BFS();
    cout << "********************************************************\n";
    return 0;
    
};