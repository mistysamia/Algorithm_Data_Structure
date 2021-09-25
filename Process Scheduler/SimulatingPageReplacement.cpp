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
#define N 1000

map<ll, ll> track;
deque<ll> Reference, RefStore[N], Frame, lastIndx, firstIndx;

void clr()
{
    track.clear();
    Frame.clear();
}

int main()
{
    fast_cin;

    ll pageNo, RefNo, FrameNo, indx = 0;
    ll FIFOPageFault = 0, OptimalPageFault = 0, LeastPageFault = 0;
    double FIFOFaultRate, OptimalFaultRate, LeastPageRate;

    std::fill(firstIndx.begin(), firstIndx.end(), -1);


    /***********
       Input
    ***********/
    cout << "Number of Pages:" << endl;
    cin >> pageNo;
    cout << "Number of Page References:" << endl;
    cin >> RefNo;
    cout << "Reference String:" << endl;
    for (int i = 0; i < RefNo; i++)
    {
        cin >> Reference[i];
        RefStore[Reference[i]].push_back(i);
    }
    cout << "Number of Memory Page Frame:" << endl;
    cin >> FrameNo;


    /****************************************************
              FIFO Page Replacement Algorithm
    ****************************************************/
    clr();
    for (int i = 0; i < RefNo; i++)
    {
        if (track[Reference[i]] == 0)
        {
            FIFOPageFault++;
            track[Reference[i]]++;
            if (Frame.size() < FrameNo)
                Frame.push_back(Reference[i]);
            else
            {
                track[Frame[indx]] = 0;
                Frame[indx] = Reference[i];
            }
            indx++;
            if (indx == FrameNo)
                indx = 0;
        }
    }
    cout << "Number of page fault using FIFO Page replacement Algorithm:  " << FIFOPageFault << endl;
    FIFOFaultRate = ((double)FIFOPageFault / (double)RefNo) * 100;
    cout << "Page Fault Rate: " << round(FIFOFaultRate)<< "%" << endl;


    /****************************************************
              Optimal Page Replacement Algorithm
    ****************************************************/
    clr();
    for (int i = 0; i < RefNo; i++)
    {
        if (track[Reference[i]] == 0)
        {
            OptimalPageFault++;
            track[Reference[i]]++;
            if (Frame.size() < FrameNo)
                Frame.push_back(Reference[i]);
            else
            {
                indx = -BIG;
                ll tempIndx = -1;
                for (int j = 0; j < Frame.size(); j++)
                {
                    ll temp = -1;
                    for (int k = 0; k < RefStore[Frame[j]].size(); k++)
                    {
                        if (RefStore[Frame[j]][k] > i)
                        {
                            temp = RefStore[Frame[j]][k];
                            break;
                        }
                    }
                    if (temp == -1)
                    {
                        tempIndx = j;
                        break;
                    }
                    else if (temp > indx)
                    {
                        indx = temp;
                        tempIndx = j;
                    }
                }
                track[Frame[tempIndx]] = 0;
                Frame[tempIndx] = Reference[i];
            }
        }
    }
    cout << "Number of page fault using FIFO Page replacement Algorithm:  " << OptimalPageFault << endl;
    OptimalFaultRate = ((double)OptimalPageFault / (double)RefNo) * 100;
    cout << "Page Fault Rate: " <<round(OptimalFaultRate)<< "%" << endl;


    /****************************************************
              Least Recently Used Algorithm
    ****************************************************/
    clr();
    for (int i = 0; i < RefNo; i++)
    {
        if (track[Reference[i]] == 0)
        {
            LeastPageFault++;
            track[Reference[i]]++;
            if (Frame.size() < FrameNo)
                Frame.push_back(Reference[i]);
            else
            {
                indx = BIG;
                ll tempIndx = -1;
                for (int j = 0; j < Frame.size(); j++)
                {
                    ll temp = -1;
                    for (int k = 0; k < RefStore[Frame[j]].size(); k++)
                    {
                        if (RefStore[Frame[j]][k] < i)
                        {
                            temp = RefStore[Frame[j]][k];
                        }
                        else
                            break;
                    }
                    if (temp == -1)
                    {
                        tempIndx = j;
                        break;
                    }
                    else if (temp < indx)
                    {
                        indx = temp;
                        tempIndx = j;
                    }
                }
                track[Frame[tempIndx]] = 0;
                Frame[tempIndx] = Reference[i];
            }
        }
    }
    cout << "Number of page fault using FIFO Page replacement Algorithm:  " << LeastPageFault << endl;
    LeastPageRate = ((double)LeastPageFault / RefNo) * 100;
    cout << "Page Fault Rate: " <<round(LeastPageRate)<< "%" << endl;
    
}


/*************
8
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3
*************/ 
