///searching from array the lower bound, return position of lower bound
///lower Bound : সহজ কথায় সবথেকে বামের যে ইনডেক্সে  key এর সমান বা বড় কোনো সংখ্যা আছে সেই position ই হলো লোয়ার বাউন্ড।
int lowerBound(int a[],int n,int key)
{
    int left=0,right=n-1,index=-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==key)
        {
            index=mid;
            right=mid-1;
        }
        else if(a[mid]>key)
            right=mid-1;
        else
            left = mid + 1;
    }
    return left;
}
