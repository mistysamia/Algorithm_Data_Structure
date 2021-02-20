#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1000005
#define BIG 1000000000000005

ll total=0;
vector<ll> graph[SIZE];/// Graph
vector<ll>tranpose[SIZE];/// Transpose of the Graph
ll visited[SIZE];  /// visited array
stack<ll>store;       /// stack (stores vertices with increasing order of finishing time)


/// A recursive function to print DFS starting from v
void dfs(ll curr)
{
    visited[curr] = true;   /// Mark the current node as visited and print it
//    cout << curr << " ";

    for(int i=0; i<tranpose[curr].size(); i++)
    {
        ll next = tranpose[curr][i];
        if(!visited[next])  /// Recur for all the vertices adjacent to this vertex
            dfs(next);
    }
}

void getTranspose(ll n)             /// Generates the transpose of the Graph
{
    for(int i=0; i<SIZE; i++)
        tranpose[i].clear();           /// clear the transpose graph


    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            ll from = i;          /// from (in the original graph)
            ll to = graph[i][j];    /// to (in the original graph)

            tranpose[to].push_back(from);  /// to to from (reversed)
        }
    }
}

/// Fills Stack with vertices (in increasing order of finishing times)
/// The top element of stack has the maximum finishing time
void fillStack(ll curr)
{
    visited[curr] = true;       /// Mark the current node as visited
    for(int i=0; i<graph[curr].size(); i++)
    {
        ll next = graph[curr][i];  /// Recur for all the vertices adjacent to this vertex
        if(!visited[next])
        {
            fillStack(next);
        }
    }

    store.push(curr);               /// All vertices reachable from v are processed by now, push v
}

void GetSCCs(ll n)
{
    while(!store.empty())
        store.pop();          /// empty the stack

    memset(visited, 0, sizeof(visited));/// Mark all the vertices as not visited (For first DFS)

    for(int i=1; i<=n; i++)              /// 0 indexed
    {
        if(!visited[i])                 /// Fill vertices in stack according to their finishing times
            fillStack(i);
    }

    getTranspose(n);                     /// Generate the reversed graph T

    memset(visited, 0, sizeof(visited));/// Mark all the vertices as not visited (For second DFS)

    while(!store.empty())                   /// Now process all vertices in order defined by Stack
    {
        ll curr = store.top();
        store.pop();                        /// Pop a vertex from stack

        if(!visited[curr])
        {
            dfs(curr);
            total++;                 /// Print Strongly connected component of the popped vertex
         //   cout<<endl;
        }
    }
}

int main()
{

    ll n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        ll from, to;
        cin>>from>>to;
        graph[from].push_back(to);
    }
   // cout << "Following are strongly connected components in the given graph:\n";
    GetSCCs(n);

    cout<<total<<endl;
    return 0;
}


///

/*

7 8
5 6
6 7
7 5
5 4
4 1
1 2
2 3
3 1


*/
