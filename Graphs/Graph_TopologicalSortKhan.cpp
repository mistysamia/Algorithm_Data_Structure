/// WITHOUT USING MAP
/*
#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll nodes,edges;
vector<vector<ll> >adj;
vector<ll> indegree;

void topologicalSortKhan()
{
    queue<ll>q;
    for(int i=1; i<=nodes; i++)
        if(indegree[i]==0)
            q.push(i);

    ll cnt=0;
    vector<ll>order;

    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        cnt++;
     //   cout<<u<<endl;
        order.push_back(u);
        for(int i=0; i<adj[u].size(); i++)
        {
            ll v=adj[u][i];
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
     //cout<<cnt<<endl;
    if(cnt!=nodes)
        cout<<"CYCLE"<<endl;

    else
    {
        for(int i=0; i<order.size(); i++)
            cout<<order[i]<<endl;

    }
}
int main()
{
    while(scanf("%lld%lld",&nodes,&edges)==2)
    {

        if(nodes==0 && edges==0)
            break;
        adj.resize(nodes+edges);
        indegree.resize(nodes+edges);

        ll u,v;
        for(int i=1; i<=edges; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            ++indegree[v];
        }
topologicalSortKhan();
         for(int i=0; i<=edges; i++)
            adj[i].clear();
            indegree.clear();

    }
}
*/


///USING map

/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define BIG 100000000
#define N 10000
ll visited[1000];
map<string,ll>mp1;
map<ll,string>mp2;
queue<ll>q;
vector<vector<ll> >grid;
vector<string>order;
int main()
{
    ll n,m;
    cout<<"Enter the number of the nodes and the edges :"<<endl;
    cin>>n>>m;
    grid.resize(n+m);
    cout<<"The nodes ? "<<endl;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        mp1.insert(make_pair(s,i));
        mp2.insert(make_pair(i,s));
    }
    cout<<"The Edges? " <<endl;
    for(int i=1; i<=m; i++)
    {
        cin.clear();
        string s1,s2;
        cin>>s1;
        ll u=mp1[s1];
        cin.clear();
        cin>>s2;
        ll v=mp1[s2];
        grid[u].push_back(v);
        visited[v]++;
    }
    for(int i=1; i<=n; i++)
        if(visited[i]==0)
            q.push(i);

    while(!q.empty())
    {
        ll save=q.front();
        q.pop();
        string s;
        s=mp2[save];
        order.push_back(s);
        for(int i=0; i<grid[save].size(); i++)
        {
            ll index=grid[save][i];
            visited[index]--;
            if(visited[index]==0)
                q.push(index);
        }

    }
    cout<<endl;
    for(ll i=0; i<order.size(); i++)
    {
        string ss=order[i];
        ll index=mp1[ss];
        cout<<mp2[index]<<" ";
    }
    order.clear();
    for(int i=0; i<=m; i++)
        grid[i].clear();

    mp1.clear();
    mp2.clear();
}
*/
/*

Enter the number of the nodes and the edges :
7 9
The nodes?
a
b
c
d
e
f
g
The Edges?
b c
b d
c f
d g
a f
a g
f g
f e
g e

Enter the number of the nodes and the edges :
9 9

The nodes?

food
pants
belt
shirt
tie
jacket
socks
shoes
watch

The Edges?

socks shoes
food shoes
pants shoes
food pants
pants belt
shirt belt
belt jacket
shirt tie
tie jacket

Output

food shirt socks watch pants tie shoes belt jacket
*/
