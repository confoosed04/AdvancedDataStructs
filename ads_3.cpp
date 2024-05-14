#include <iostream>
#include <string.h>
using namespace std;
class treenode {
  char data[10];
  char meaning[10];
  treenode *left;
  treenode *right;
  friend class tree;
  friend class queue;
};
class queue{
	int front = 0;
	int rear = 0;
	treenode* queue[50];
	void push(treenode* x){
		queue[rear++] = x;
	}
	treenode* pop(){
		return queue[front++];
	}
	bool isEmpty(){
		if (front == rear)
			return true;
		return false;
	}
	friend class tree;
};
class tree {
  treenode *root;
  queue q;
public:
  tree() { root = NULL; }
  treenode* root_r(){
    return root;
  }
  void create_r() {
    root = new treenode();
    cout << "Enter Data In Root" << endl;
    cin >> root->data;
    cout << "Enter meaning" << endl;
    cin >> root->meaning;
    root->left = root->right = NULL;
	char ch;
	cout << "choice y or n";
	cin >> ch;
    while (ch == 'y') {
      treenode *var = new treenode();
      cout << "Give the new keyword" << endl;
      cin >> var->data;
      cout << "give meaning of that word " << endl;
      cin >> var->meaning;

      int flag = 0;

      treenode *temp = root;
      treenode *temp1 = root;
        while (temp != NULL) {
            if (strcmp(var->data, temp->data) == 0) {

                break;
            } else if (strcmp(var->data, temp->data) > 0) {
            temp1 = temp;
                temp = temp->right;
            } else {
            temp1 = temp;
                temp = temp->left;
            }
        }
        
            if (strcmp(var->data, temp1->data) > 0) {
            temp1->right = var;
        } else 
            temp1->left = var;
        
        cout << "choice y or n";
    cin >>ch;
    }
    
  	bfs();
  }
    

void bfs(){
    if (root == NULL)
        return;

    q.push(root);
    while (!q.isEmpty()) {
        treenode* current = q.pop();
        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

  void pre_order_r(treenode* root){
			if (root == NULL)
				return;
			cout << root->data << "\t";
			pre_order_r(root->left);
			pre_order_r(root->right);
			
}
void in_order_r(treenode* root){
			if (root == NULL)
				return;
			in_order_r(root->left);
			cout << root->data;
			in_order_r(root->right);
		}
void mirror_r()
{
mirror_r(root);
cout << "Mirror"<<endl;
bfs();

}

/*void mirror_nr(){
  mirror_nr(root);
  bfs();
}*/
void mirror_r(treenode* root) {
    if (root == NULL)
        return;

    treenode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror_r(root->left);
    mirror_r(root->right);

}
treenode* copy(treenode* root) {
    if (root == NULL)
        return NULL;

    treenode* temp = new treenode();

    strcpy(temp->data, root->data);
    strcpy(temp->meaning, root->meaning);

    temp->left = copy(root->left);
    temp->right = copy(root->right);

    return temp;
}
void copy()
{
  treenode* x = copy(root);
  pre_order_r(x);
}
/*void mirror_nr(treenode* root) {

  treenode* temp=root;
  q.push(temp);
  while(!q.isEmpty()){
    temp=q.pop();
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(temp->left!=NULL)
    q.push(temp->left);

    if(temp->right!=NULL)

    q.push(temp->right);

  }
  bfs();
}
*/

};

int main() {
  tree t;
  
  t.create_r();
  t.mirror_r();
  treenode* x = t.root_r();
  treenode* y = t.copy(x);
  t.pre_order_r(y);
  return 0;
}
