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
#define pii pair<ll, ll>
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

int main()
{
    fast_cin;
    string s, tempS;
    ll headsNo, headPos, fcfs = 0, sstf = 0, c_scan = 0, tempHeadPos = 0;
    deque<ll> cylinderReq;
    map<ll, ll> track;

    /****************************
     ********** Input  **********
    *****************************/

    cout << "Number of heads:" << endl;
    cin >> headsNo;
    headsNo--;
    cout << "Cylinder requests:" << endl;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            tempS += s[i];
        if (s[i] == ' ' || i == s.length() - 1)
        {
            stringstream geek(tempS);
            ll tempReq = 0;
            geek >> tempReq;
            cylinderReq.push_back(tempReq);
            track[tempReq]++;
            tempS.clear();
        }
    }
    cout << "Current head position:" << endl;
    cin >> headPos;

    /*******************************************
     * FCFS (First Come First Serve) Scheduling
    *******************************************/

    tempHeadPos = headPos;
    cout << endl<<"First Come First Serve Scheduling : "<<endl
         << "Cylinder Serving Order:" << endl;

    for (int i = 0; i < cylinderReq.size(); i++)
    {
        fcfs += abs(cylinderReq[i] - tempHeadPos);
        cout << tempHeadPos << " -> ";
        tempHeadPos = cylinderReq[i];
    }
    cout << tempHeadPos << endl;
    cout << "Total Cylinder movement: " << fcfs << endl;

    /**********************************************
     * SSTF (Shortest Seek time First) Scheduling
    **********************************************/

    tempHeadPos = headPos;
    cout << endl<<"Shortest Seek time First Scheduling : "<<endl
         << "Cylinder Serving Order:" << endl;
    while (1)
    {
        ll tempDiff = BIG, tempVal = -1;
        for (int i = 0; i < cylinderReq.size(); i++)
        {
            if (track[cylinderReq[i]] > 0 && abs(tempHeadPos - cylinderReq[i]) < tempDiff)
            {
                tempDiff = abs(tempHeadPos - cylinderReq[i]);
                tempVal = cylinderReq[i];
            }
        }
        if (tempVal == -1)
            break;
        else
        {
            sstf += abs(tempVal - tempHeadPos);
            cout << tempHeadPos << " -> ";
            track[tempVal]--;
            tempHeadPos = tempVal;
        }
    }
    cout << tempHeadPos << endl;
    cout << "Total Cylinder movement: " << sstf << endl;

    /*****************************************
     *********** C-SCAN Algorithm  ***********
    ******************************************/

    sort(cylinderReq.begin(), cylinderReq.end());
    tempHeadPos = headPos;
    cout << endl<<"C-Scan Algorithm : "<<endl
         << "Cylinder Serving Order:" << endl;

    for (int i = 0; i < cylinderReq.size(); i++)
    {
        if (cylinderReq[i] > tempHeadPos)
        {
            c_scan += abs(cylinderReq[i] - tempHeadPos);
            cout << tempHeadPos << " -> ";
            tempHeadPos = cylinderReq[i];
        }
        if (i == cylinderReq.size() - 1)
        {
            c_scan += abs(headsNo - tempHeadPos);
            cout << tempHeadPos << " -> "<< headsNo << " -> ";
            tempHeadPos = 0;
        }
    }
    for (int i = 0; i < cylinderReq.size(); i++)
    {
        if (cylinderReq[i] > headPos)
            break;
        if ((cylinderReq[i] > tempHeadPos) || i == 0)
        {
            c_scan += abs(cylinderReq[i] - tempHeadPos);
            cout << tempHeadPos << " -> ";
            tempHeadPos = cylinderReq[i];
        }
    }
    cout << tempHeadPos << endl;
    cout << "Total Cylinder movement: " << c_scan << endl
         << endl;
}


/**
 * 
 * 
 *200
98 183 37 122 14 124 65 67
53
 * 
 * 
 *
**/
  
 