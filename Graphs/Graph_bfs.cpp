#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int level[1000];
int start[1000];
int finish[1000];
void BFS(int source ,int n)
{
    queue<int> q;
    memset(level,-1,sizeof(level));
    q.push(source);
    level[source]=0;
    printf("BFS : ");
    while(!q.empty())
    {
        int u=q.front();
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
    BFS(root,n);
    return 0;
}

/*
7 8
5 1
1 2
2 3
3 5
5 4
4 6
1 6
6 7


*/
