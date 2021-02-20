#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1005
#define BIG 10000005


ll adj[SIZE][SIZE];
ll path[SIZE][SIZE];
map<ll,ll>neg_cycle;
vector<ll>save_path;
ll check=0;

void FloydWarshall(ll n)
{
    for(ll k=1; k<=n; k++)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j] && adj[i][k]!=BIG && adj[k][j]!=BIG )
                {
                    adj[i][j] = adj[i][k]+adj[k][j] ;
                    path[i][j]=path[k][j] ;///for saving the path
                }
            }
        }
        //predecessor

        cout<<endl<<endl<<"For  "<<k<<endl<<"Cost"<<endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(adj[i][j]==BIG)

                    cout<<"Inf ";
                else if(i==j && path[i][j]==0)
                    cout<<"0 ";
                else
                    cout<<adj[i][j]<<" ";
            }

            cout<<endl;
        }
        cout<<endl<<" Path  "<<endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(path[i][j]==-1 || i==j || adj[i][j]==BIG)
                    cout<<"N ";
                else
                    cout<<path[i][j]<<" ";
            }

            cout<<endl;
        }

    }

}
void Print_Path(ll sour, ll des)
{
    if(neg_cycle.find(des)!=neg_cycle.end())
    {
        check =1;
        return ;
    }
    else if(sour==des)
    {
        save_path.push_back(sour);
        return;
    }
    else
    {
        Print_Path(sour,path[sour][des]) ;
        save_path.push_back(des);
    }
}
void clr()
{
    for(ll i=0; i<SIZE; i++)
    {
        for(ll j=0; j<SIZE; j++)
        {
            if(i==j)
            {
                adj[i][j] = 0;
                path[i][j] = i;
            }
            else
            {
                adj[i][j] =BIG;
                path[i][j] = -1;
            }
        }
    }
    neg_cycle.clear();
}
int main()
{
    clr();
    ll n,e,from,to,weight;
    cout<<"How many nodes and edges ? : ";
    cin>>n>>e;

    cout<<endl<<"Enter edge to edge relations and their weights : "<<endl;
    for(ll i=1 ; i<=e ; i++)
    {
        cin>>from>>to>>weight;
        adj[from][to]=weight;
        path[from][to]=from;
    }
    FloydWarshall(n);

    cout<<"Print matrix"<<endl;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(adj[i][j]==BIG)
                cout<<"Inf ";
            else if(adj[i][j]>=1000005 && i!=j)
            {
                adj[i][j]=BIG;
                path[i][j]=-1;
                cout<<"Inf ";
            }
            else
                cout<<adj[i][j]<<" ";
            if(adj[i][i]<0)
                neg_cycle[i]++;
        }
        cout<<endl;
    }

    cout<<endl<<endl<<"Path Matrix :"<<endl;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
            cout<<path[i][j]<<" ";

        cout<<endl;
    }

    cout<<endl<<endl<<"Path printing :  "<<endl;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            check=0;
            cout<<"Path from "<<i<<" "<<j<<" :"<<endl;
            if(path[i][j]==-1)
                cout<<"No path from "<<i<<" to "<<j<<endl ;
            else if(neg_cycle.find(i)==neg_cycle.end()  && neg_cycle.find(j)==neg_cycle.end())
            {
                Print_Path(i,j);
                if(check==1)
                    cout<<"There will be a negative cycle in the path"<<endl;
                else
                {
                    for(int i=0; i<save_path.size(); i++)
                        cout<<save_path[i]<<" ";

                    cout<<endl;

                }
                save_path.clear();
            }
            else
            {
                if(neg_cycle.find(j)==neg_cycle.end())
                    cout<<"Node "<<i<<" has a cycle"<<endl;
                else if(neg_cycle.find(i)==neg_cycle.end())
                    cout<<"Node "<<j<<" has a cycle"<<endl;
                else
                    cout<<"Node "<<i<<" & "<<j<<" both nodes have cycle"<<endl;
            }
        }
        cout<<endl<<endl;
    }


    return 0;
}

/*

8 8
1 2 2
2 4 5
4 5 5
2 3 7
3 6 7
6 7 -100
7 6 2
6 8 10

*/
