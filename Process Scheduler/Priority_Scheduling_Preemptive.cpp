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
bool sortbyIndx(const pair<pair<ll, ll>, ll> &a, const pair<pair<ll, ll>, ll> &b)
{
    return a.ss < b.ss;
}
struct compare
{
    bool operator()(pii p1, pii p2)
    {
        if (p1.ff.ff.ff == p2.ff.ff.ff)
            return p1.ff.ss < p2.ff.ss;
        else
            return p1.ff.ss > p2.ff.ss;
    }
};

int main()
{
    fast_cin;
    ll cas = 1, indx = -1;
    deque<pii> process;
    deque<pair<pair<ll, ll>, ll>> save;
    priority_queue<pii, vector<pii>, compare> track;
    ll waitTime = 0, turnTime = 0, avgWait = 0, avgTurn = 0, curTime = 0, n;
    string ganttChart = "";
    cout << "Enter the number of process : " << endl;
    cin >> n;

    ll cpu[n + 5], arrival[n + 5], priority[n + 5], endTime[n + 5], waitingTime[n + 5];
    cout << "Enter the CPU times" << endl;
    for (int i = 0; i < n; i++)
        cin >> cpu[i];

    cout << "Enter the arrival times" << endl;
    for (int i = 0; i < n; i++)
        cin >> arrival[i];

    cout << "Enter the priority times" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> priority[i];
        endTime[i] = arrival[i];
        waitingTime[i] = 0;
        process.push_back({{{arrival[i], cpu[i]}, priority[i]}, i});
    }
    
    stable_sort(process.begin(), process.end(), sortbysec);
    while (!process.empty() || !track.empty())
    {
        while (!process.empty())
        {
            pii time = process.front();
            if (time.ff.ff.ff <= curTime)
            {
                track.push(time);
                process.pop_front();
            }
            else
                break;
        }

        if (!track.empty())
        {
            pii time = track.top();
            track.pop();
            time.ff.ff.ss--;
            if (indx != time.ss)
            {
                if (indx != -1)
                    ganttChart += to_string(endTime[indx]) + ") ";
                ganttChart += "| (" + to_string(curTime) + ")----P" + to_string(time.ss + 1) + "----(";
                waitingTime[time.ss] += curTime - endTime[time.ss];
                endTime[time.ss] = curTime + 1;
                indx = time.ss;
            }
            else
                endTime[time.ss] = curTime + 1;

            if (time.ff.ff.ss <= 0)
            {
                turnTime = waitingTime[time.ss] + cpu[time.ss];
                avgTurn += turnTime;
                avgWait += waitingTime[time.ss];
                save.push_front({{waitingTime[time.ss], turnTime}, time.ss});
            }
            else
                track.push(time);
        }
        curTime++;
    }
    if (indx != -1)
        ganttChart += to_string(endTime[indx]) + ") |";
   
    cout << endl
         << "Gantt Chart:" << endl
         << ganttChart << endl;

    sort(save.begin(), save.end(), sortbyIndx);
    for (int i = 0; i < save.size(); i++)
    {
        cout << "Process " << cas++ << ": Waiting Time: " << save[i].ff.ff;
        cout << " Turnaround Time :" << save[i].ff.ss << endl;
    }
    cout << fixed << setprecision(2) << "Average Waiting Time: " << double(avgWait) / n << endl;
    cout << fixed << setprecision(2) << "Average Turnaround Time: " << double(avgTurn) / n << endl;
}
