#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1005
#define BIG 1000000000000005

ll fx[] = {1, -1, 0, 0};
ll fy[] = {0, 0, 1, -1};

ll adj[SIZE][SIZE]; /// main graph
ll path_cost[SIZE][SIZE];/// path cost save
ll cell[SIZE][SIZE];///if any cell is blocked
pair<ll, ll> path[SIZE][SIZE];///path save
ll row, col;


struct Node
{
    ll node_x, node_y, weight;
    Node() {}
    Node(ll node_x, ll node_y, ll weight)
    {
        this->node_x = node_x;
        this->node_y = node_y;
        this->weight = weight;
    }
    bool operator < (const Node &a)const
    {
        return weight > a.weight;
    }
};

void  dijkstra2D(ll sx, ll sy)
{
    priority_queue<Node>q;
    memset(path, 0, sizeof path);
    path_cost[sx][sy] = adj[sx][sy];
    Node s(sx, sy, path_cost[sx][sy]);
    q.push(s);

    while(!q.empty())
    {
        Node curr = q.top();
        q.pop();
        ll curr_x = curr.node_x;
        ll curr_y = curr.node_y;
        ll curr_weight = curr.weight;

        if(curr_weight != path_cost[curr_x][curr_y])
            continue;

        for(ll k=0; k<4; k++)
        {
            ll tx = curr_x + fx[k];
            ll ty = curr_y + fy[k];

            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1)
            {
                ll cost = adj[tx][ty];

                if(curr_weight + cost < path_cost[tx][ty])
                {
                    path_cost[tx][ty] = curr_weight + cost;
                    path[tx][ty].first=curr_x;
                    path[tx][ty].second=curr_y;
                    Node n(tx, ty, path_cost[tx][ty]);
                    q.push(n);
                }
            }
        }
    }
}

void clr()
{
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
         path_cost[i][j]=BIG;

    memset(cell, 0, sizeof(cell));
    memset(adj, -1, sizeof(adj));
}

int main ()
{
    clr();

    cin>>row>>col;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>adj[i][j];

    ///block cell thakle cell array te save korbo


    dijkstra2D(0, 0);

    ll desx,desy,sourcex,sourcey;
    desx=row-1;desy=col-1;sourcex=0,sourcey=0;


    if( path_cost[row-1][col-1]==BIG)
        cout<<"-1"<<endl;
    else
    {
        vector<pair<ll,ll>> v;
        ll tempx=desx,tempy=desy;
        while(1)
        {
            if(tempx==sourcex && tempy==sourcey)
            {
                v.push_back({sourcex,sourcex});
                break;
            }
            v.push_back({tempx,tempy});
            ll x,y;
            x=path[tempx][tempy].first;
            y=path[tempx][tempy].second;
            tempx=x;
            tempy=y;
        }
        cout<<"The cost "<<path_cost[desx][desy]<<endl;
        cout<<"Printing the path"<<endl;
        reverse(v.begin(),v.end());
        for(auto it : v)
        {
            cout<<it.first<<" "<<it.second<<"   ";
        }
        cout<<endl;
        clr();
    }

    return 0;
}
