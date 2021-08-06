#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define b(n) cout << "bug " << n << endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<pair<pair<ll, ll>, ll>, ll>
#define fast_cin                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000

ll mod = 1e9 + 7;

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006], tra1[100006];

bool sortbysec(const pair<pair<pair<ll, ll>, ll>, ll> &a, const pair<pair<pair<ll, ll>, ll>, ll> &b)
{
    if (a.ff.ff.ff == b.ff.ff.ff)
        return a.ff.ff.second < b.ff.ff.second;
    else
        return a.ff.ff.first < b.ff.ff.first;
}
bool sortbyIndx(const pair<pair<pair<ll, ll>, ll>, ll> &a, const pair<pair<pair<ll, ll>, ll>, ll> &b)
{
    return a.ss < b.ss;
}

int main()
{
    fast_cin;
    ll cas = 1;
    deque<pii> process, track, save;
    map<ll, ll> responseTime, response, startTime, waitingTime;
    ll waitTime = 0, turnTime = 0, avgWait = 0, avgTurn = 0, curTime = 0, quantum,n;
    string ganttLine = "", ganttNum = "";
    cout << "Enter the number of process & Quantum: " << endl;
    cin >> n >> quantum;

    ll cpu[n + 5], arrival[n + 5];
    cout << "Enter the CPU times" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> cpu[i];
        responseTime[i] = 0;
    }

    cout << "Enter the arrival times" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arrival[i];
        startTime[i] = arrival[i];
        waitingTime[i] = 0;
        process.push_back({{{arrival[i], cpu[i]}, cpu[i]}, i});
    }

    stable_sort(process.begin(), process.end(), sortbysec);
    while (!process.empty() || !track.empty())
    {
        if (!track.empty())
        {
            pii secTime = track.front();
            track.pop_front();
            waitingTime[secTime.ss] += curTime - startTime[secTime.ss];
            if (responseTime[secTime.ss] == 0)
            {
                responseTime[secTime.ss] = -1;
                response[secTime.ss] = (curTime - secTime.ff.ff.ff);
            }
            ganttLine += "| (" + to_string(curTime) + ")----P" + to_string(secTime.ss + 1) + "----(";
            curTime += min(quantum, secTime.ff.ss);
            ganttLine += to_string(curTime) + ") ";
            startTime[secTime.ss] = curTime;
            secTime.ff.ss -= min(quantum, secTime.ff.ss);
            while (!process.empty())
            {
                pii secTime = process.front();
                if (curTime < secTime.ff.ff.ff)
                    break;
                track.push_back(secTime);
                process.pop_front();
            }
            if (secTime.ff.ss > 0)
                track.push_back(secTime);
            else
                save.push_back({{{waitingTime[secTime.ss], (waitingTime[secTime.ss] + secTime.ff.ff.ss)}, response[secTime.ss]}, secTime.ss});
        }
        else
        {
            while (!process.empty())
            {
                pii secTime = process.front();
                if (curTime < secTime.ff.ff.ff)
                    break;
                track.push_back(secTime);
                process.pop_front();
            }
            if (track.empty())
                curTime++;
        }
    }
    ganttLine += "|";
    cout<<endl<<"Gantt Chart:"<<endl;
    cout << ganttLine << endl;

    sort(save.begin(), save.end(), sortbyIndx);
    for (int i = 0; i < save.size(); i++)
    {
        cout << "Process " << cas++ << ": Waiting Time: " << save[i].ff.ff.ff;
        cout << " Turnaround Time :" << save[i].ff.ff.ss;
        cout << " Response Time :" << save[i].ff.ff.ss << endl;
        avgWait += save[i].ff.ff.ff;
        avgTurn += save[i].ff.ff.ss;
    }
    cout << fixed << setprecision(2) << "Average Waiting Time: " << double(avgWait) / n << endl;
    cout << fixed << setprecision(2) << "Average Turnaround Time: " << double(avgTurn) / n << endl;
}
