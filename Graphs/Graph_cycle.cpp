#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000005
#define ll long long


vector<ll>adj[SIZE];
ll n, m;               /// number of node, number of edges
ll visited[SIZE];      /// visited arrray
ll recStack[SIZE];     /// recursion stack (1 if it is in the recursion stack)


bool isCyclicDirUtil(ll curr)
{
    if(!visited[curr])
    {
        visited[curr] = 1;
        recStack[curr] = 1;

        for(int i=0; i<adj[curr].size(); i++)
        {
            ll next = adj[curr][i];

            if(!visited[next] && isCyclicDirUtil(next))/// found a back edge in the child's subtree
            {
                return true;
            }
            else if(recStack[next])/// if it is in the recursion stack, it found a back edge
            {
                return true;
            }
        }
    }
    recStack[curr] = 0;
    return false;
}

bool isCyclicDir()
{
    memset(visited, 0, sizeof(visited));
    memset(recStack, 0, sizeof(recStack));

    for(int i=0; i<n; i++)
    {
        if(isCyclicDirUtil(i))      /// check for all the nodes (handles for disconnected graph (DFS forest))
            return true;

    }
    return false;
}

void clr()
{
    for(int i=0; i<SIZE; i++)
        adj[i].clear();

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    clr();
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        ll from, to;
        cin>>from>>to;
        adj[from].push_back(to);
    }

    if(isCyclicDir())
       cout << "Graph contains cycle\n";
    else
       cout << "Graph doesn't contain cycle\n";

    return 0;
}
