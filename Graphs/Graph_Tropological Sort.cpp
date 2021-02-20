#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define SIZE 1000005
#define white 0
#define gray -1
#define black 1

vector<ll>adj[SIZE];// main grid
bool visited[SIZE]= {false};// check the node is visited or not
ll startingTime[SIZE],finishingTime[SIZE];
stack<ll>save;// To store the node
ll color[SIZE];// check the node color
ll Time=1;
ll CycleExist=0;


void DFS(ll source,ll n)
{
    if(visited[source])
        return;
//cout<<"r"<<endl;
    visited[source]=true;
    color[source]=gray;
    startingTime[source]=Time++;

    for(int i=0; i<adj[source].size(); i++)
    {
        ll u=adj[source][i];
        if(visited[u]==true && color[u]==gray)
        {
            CycleExist=1;
            return;
        }
        else if(visited[u]==false)
            DFS(u,n);
    }

    finishingTime[source]=Time++;
    color[source]=black;
    save.push(source);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll temp1,temp2;
    for(int i=0; i<m; i++)
    {
        cin>>temp1>>temp2;
        adj[temp1].push_back(temp2);
        // adj[temp2].push_back(temp1);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            DFS(i,n);

    }

    if(CycleExist)
    {
        cout<<"There is a cycle in the graph"<<endl;
        return 0;
    }
    while(!save.empty())
    {
        cout<<save.top()<<" ";
        save.pop();
    }
    cout<<endl;
    return 0;
}
/*
9 9
1 2
1 4
5 4
2 4
2 3
6 3
3 8
6 7
7 8

Output
9 6 7 5 1 2 4 3 8
*/
