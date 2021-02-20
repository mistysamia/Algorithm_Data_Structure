#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005
#define BIG 1000000000000005
#define ff first
#define ss second
#define pii pair<ll,ll>


vector<pii>adj[SIZE];
ll parent[SIZE];
ll node_cost[SIZE];
bool visited[SIZE];
map<pii,ll>cost_print;
map<pii,ll>::iterator it;
ll total_cost=0;
map<ll,ll>mp1,mp2;
ll n,m;


struct Node
{
    ll node;
    ll weight;
    Node() {}

    Node(ll node, ll weight)
    {
        this->node = node;
        this->weight = weight;
    }
    bool operator < (const Node &a)const
    {
        return weight > a.weight;
    }
};
priority_queue<Node>q;

void prims(ll source)
{
    q.push({source,0});
    node_cost[source] = 0;
    while(!q.empty())
    {
        Node curr = q.top();
        q.pop();

        if(visited[curr.node])
            continue;

        visited[curr.node]=1;
        for(int i=0; i<adj[curr.node].size(); i++)
        {
            ll v = adj[curr.node][i].first;
            ll cost = adj[curr.node][i].second;

            if(cost<node_cost[v] && !visited[v])
            {
                q.push({v,cost});

                parent[v]=curr.node;
                node_cost[v]=cost;
            }
        }
    }
}


void printMST(ll source)
{
    ll in=0;
    for(ll i=0; i<=n; i++)
    {
        if(!adj[parent[i]].empty())
        {
            if(!in)
            {
                cout<<endl<<"The saved edge to make MST:"<<endl<<endl;
                cout<<"  Edge       Weight"<<endl<<endl;
            }
            in=1;
            it=cost_print.find({parent[i],i});
            cout<<"  {"<<mp2[parent[i]]<<","<<mp2[i]<<"}      "<<it->ss<<endl;
            total_cost+=it->ss;
        }
    }
    if(!in)
        cout<<"The source node doesn't have any edges."<<endl;
}

void clr()
{
    for(int i=0; i<SIZE; i++)
    {
        adj[i].clear();
        node_cost[i] =BIG;
        visited[i] = false;
        parent[i]=100000;
    }
    cost_print.clear();
    mp1.clear();
    mp2.clear();
}

int main ()
{
    clr();
    cin>>n>>m;
    ll source,cou=1;

    for(int i=0; i<m; i++)
    {
        ll from,to,weight;
        cin>>from>>to>>weight;
        if(mp1[from]==0)
        {
             mp1[from]=cou;
             mp2[cou]=from;
             cou++;
        }
        if(mp1[to]==0)
        {
             mp1[to]=cou;
             mp2[cou]=to;
             cou++;
        }
        adj[ mp1[from]].push_back(pii(mp1[to], weight));
        adj[mp1[to]].push_back(pii( mp1[from], weight));
        cost_print[ { mp1[from],mp1[to]}]=weight;
        cost_print[ {mp1[to], mp1[from]}]=weight;
    }
    n=cou-1;
    cout<<"Enter the source : ";

    cin>>source;

    prims(mp1[source]);
    printMST(mp1[source]);

    cout<<endl<<"Total cost of making MST is : "<<total_cost<<endl;
    return 0;
}

/*
8 11
1 5 2
1 4 10
1 2 4
2 4 8
5 4 5
2 3 18
4 3 11
4 7 11
4 8 9
7 6 1
8 6 2

*/
