#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1000


ll element[SIZE];
vector<ll>save_element,save_index;
ll total_sum,n, cou_index,cou_elements;


void print_index()
{
    cout<<"SubSet number "<<++cou_index<<" : ";
    ll in=0,lock=0;

    for(ll i=0; i<n; i++)
    {
         if(i!=save_element[in] || lock==1)
            cout<<"0 ";
        else
        {
            cout<<"1 ";
            in++;
            if(in>=save_element.size())
            {
                lock=1;
            }
        }
    }
    cout<<endl;
}

void print_element(ll n)
{
    cout<<"SubSet number "<<++cou_elements<<" : ";
    for(ll i=0; i<n; i++)
        cout<<save_element[i]<<" ";

    cout<<endl;
}

///If I'm not allowed to sort the array or want to print the indexes of the subsets
//But there's a drawback
void sumofsub_index(ll index,ll sum)
{
    if(sum==total_sum)
    {
        print_index();
        return ;
    }

    if(index>=n)
        return;

    if(sum+element[index]<=total_sum)
    {
        save_element.push_back(index);
        sumofsub_index(index+1,sum+element[index]);

        save_element.pop_back();
    }
    sumofsub_index(index+1,sum);
}


///If I'm allowed to sort the array or want to print the elements of the subsets
void sumofsub_element(ll index,ll sum)
{
    if(sum==total_sum)
    {
        print_element(save_element.size());
        return ;
    }

    if(index>=n)
        return;

    if(element[index]>total_sum)
        return;


    if(sum+element[index]<=total_sum)
    {
        save_element.push_back(element[index]);//
        sumofsub_element(index+1,sum+element[index]); // 5 10

        save_element.pop_back();
        sumofsub_element(index+1,sum);//
    }
    else
        return;

}

void clr()
{
    memset(element,0,sizeof element);
    save_element.clear();
   cou_index=0;
   cou_elements=0;
}

int main()
{
    clr();
    cout<<"Number of element ?  : ";
    cin>>n;
    cout<<"Enter the elements of the set : ";
    for(ll i=0; i<n; i++)
        cin>>element[i];

    cout<<"Enter the sum : ";
    cin>>total_sum;

    cout<<endl<<"Printing the indexes of subsets :"<<endl<<endl;
    sumofsub_index(0,0);

    save_element.clear();
    cout<<endl<<"Printing the elements of subsets :"<<endl<<endl;
    sort(element,element+n);
    sumofsub_element(0,0);
}



/*

4
11 13 7 24
31

6
13 18 5 10 12 15
30

8
-7 10 -3 -3 2 3 5 8
10

*/
