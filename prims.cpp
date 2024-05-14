#include<iostream>
using namespace std;

class graph{
    int cost[10][10];
    int ch;
    int cities;

    public:
        graph();
       
        void create();
        int prims();
};

graph::graph()
 {
            cout<<"enter the total no: of cities:\n";
            cin>>cities;
            for(int i=0;i<cities;i++)
            {
                for(int j=0;j<cities;j++)
                {
                    {
                        cost[i][j]=999;
                    } 
                }
            }
        };

void graph::create()
{
    int c;
      for(int i=0;i<cities;i++)
            {
                for(int j=0;j<cities;j++)
                {
     cout<<"is there a edge between"<<i<<"and"<<j;
     cin>>ch;
     if(ch==1)
     {
        cout<<"enter the cost"<<endl;
        cin>>c; 
        cost[i][j]=c;
     }
        } 
                }
    for(int i=0;i<cities;i++)
    {
        for(int j=0;j<cities;j++)
        {
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }

} ;

int graph::prims()
{
    int t[cities-1][3];
    int nearest[10];
    int r,mincost,min;
    int startv;
    int j;
    cout<<"enter the starting vertex:";
    cin>>startv;
    
    nearest[startv]=-1;
    for(int i=0;i<cities;i++)
    {
        if(i!=startv)
        {
            nearest[i]=startv;
         }
         r=0;
    }
         for(int i=0;i<cities;i++)
         {
            min=999;
            for(int k=0;k<cities;k++)
            {
                if (nearest[k]!= -1 && cost[k][ nearest[k]]< min)
            { 
                 j=k ; 
            min= cost[k] [nearest[k]];
            }
}
       t[ r][0]=j;
       t[r][1]=nearest[j];
        r=r+1;
mincost = (mincost +cost[j][ nearest[j]]);
nearest[j]=-1;

for(int k=0;k<cities;k++)
{ if(nearest[k]!= -1 && (cost[k] [nearest[k]]) > cost[k][j])
nearest[k]=j;
}


 cout<<mincost;
         }
return mincost; 
}


int main()
{
    graph x;
    x.create();
    x.prims();
      return 0;

}

