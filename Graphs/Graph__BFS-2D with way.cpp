#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 1000002
#define pie 3.14159265358979323
#define minuss 1e-6
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)


ll sourcex, sourcey, desx, desy;
pair<ll, ll> path[100][100];
ll vis[100][100];
ll visited[100][100];
#define pii pair<ll, ll>
ll fx[] = {1, -1, 0, 0};
ll fy[] = {0, 0, 1, -1};

ll BFS(pair<ll, ll> source)
{
    memset(vis, 0, sizeof vis);
    memset(path, 0, sizeof path);
    memset(visited, -1, sizeof visited);


    vis[source.first][source.second] = 0;
    visited[source.first][source.second]=1;
    queue<pii> q;
    q.push(source);
    while (!q.empty())
    {
        pii top = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            ll tx = top.first + fx[k];
            ll ty = top.second + fy[k];
            if (tx >= 0 && tx < 12 && ty >= 0 && ty < 12)
            {
                if (visited[tx][ty] == -1)
                {
                    visited[tx][ty]=1;
                    vis[tx][ty] = vis[top.first][top.second] + 1;
                    path[tx][ty].first=top.first;
                    path[tx][ty].second=top.second;
                    q.push({tx,ty});
                }
            }
            if (tx==desx && ty== desy)
                return vis[tx][ty];
        }
    }
    return -1;
}

int main()
{

    ll t;
    cin >> t;
    ll k=0;
    while (t--)
    {
        k++;
        cout<<"Case : "<<k<<endl;
        cin >> sourcex >> sourcey >> desx >> desy;

        ll ans = BFS({sourcex, sourcey});

        if(ans==-1)
            cout<<"PATH NOT FOUND"<<endl;
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
            reverse(v.begin(),v.end());
            for(auto it : v)
            {
                cout<<it.first<<" "<<it.second<<endl;
            }
        }


    }

    return 0;
}
