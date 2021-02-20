
/// stack

/*
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int level[1000];
int start[1000];
int finish[1000];
void DFS(int source ,int n)
{
    stack<int> q;
    memset(level,-1,sizeof(level));
    q.push(source);
    level[source]=0;
    printf("DFS : ");
    while(!q.empty())
    {
        int u=q.top();
        ///here u can visit all the nodes;
        printf("%d ",u);
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(level[adj[u][i]]==-1)
            {
                level[adj[u][i]]=0;
                q.push(adj[u][i]);
            }
        }
    }
}
int main()
{
    memset(start,-1,sizeof(start));
    memset(finish,-1,sizeof(finish));
    int n,m;
    cin>>n>>m;
    int temp1,temp2;
    for(int i=0;i<m;i++)
    {
        cin>>temp1>>temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    printf("Adjacency list : \n\n");
    for(int i=1;i<=n;i++)
    {
        printf("node %d : ",i);
        for(int j=0;j<adj[i].size();j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    int root;
    cin>>root;
    DFS(root,n);
    //printf("%d\n",ConnectedComponenetsCnt(n,root));
    //DFS(1);
    return 0;
}
*/


/// recursion

/*
#include <bits/stdc++.h>
using namespace std;
#define ll  long long

vector<ll>adj[1000];// main grid
ll visit[1000];// check if the node is visited or not
int matrix[1000][1000];//adjacency matrix


void DFS(ll source,ll n)
{
   visit[source]=-1;

   for(int i=1;i<=n;i++)
   {
       if(matrix[source][i]!=0)
       {
           if(visit[i]==0)
            DFS(i,n);
       }
   }
   visit[source]=1;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll temp1,temp2;
    for(int i=0; i<m; i++)
    {
        cin>>temp1>>temp2;
        matrix[temp1][temp2]=1;
        adj[temp1].push_back(temp2);
       // adj[temp2].push_back(temp1);
    }
    printf("Adjacency list : \n\n");
    for(int i=1; i<=n; i++)
    {
        printf("node %d : ",i);
        for(int j=0; j<adj[i].size(); j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++)
    {
        if(visit[i]==0)
            DFS(i,n);
    }
    return 0;
}
*/
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

*/
