#include<iostream>
using namespace std;

class heap
{

int marks[20];
public:
void accept(int n);
void display(int n,int flag);
void heapsort(int n);
void adjust(int n,int i);
};

void heap::accept(int n)
{
for(int i=0;i<n;i++)
{
cout<<"Enter marks of student-"<<i+1<<" is:";
cin>>marks[i];
}
}
void heap::display(int n,int flag)
{
cout<<"\n Marks are: ";
for(int i=0;i<n;i++)
{
cout<<marks[i]<<"\t";
}

if(flag==0)
{
cout<<"\nMinimum marks are: "<<marks[0]<<endl;
cout<<"Maximum marks are: "<<marks[n-1]<<endl;
}
}
void heap::heapsort(int n)
{
int t;
for(int i=(n/2);i>=0;i--)
{
adjust(n-1,i);
}
cout<<"The max heap: ";
display(n,1);
cout<<"\nSorted output: ";
while(n>0)
{
t=marks[0];
marks[0]=marks[n-1];
marks[n-1]=t;
n--;
adjust(n-1,0);
}
}
void heap::adjust(int n,int i)
{
int j,temp;
while(2*i+1<=n)
{
j=(2*i+1);
if((j+1<=n) && (marks[j+1]>marks[j]))
{
j=j+1;
}
if(marks[i]>=marks[j])
{
break;
}
else
{
temp=marks[i];
marks[i]=marks[j];
marks[j]=temp;
       i=j;
}
}
}


int main()
{
heap h;
int n;

cout<<"Number of students: ";
cin>>n;
h.accept(n);
h.heapsort(n);

h.display(n,0);
return 0;
}