///searching from array the upper bound, return position of upper bound
///upper Bound : সবথেকে বামের যে ইনডেক্সে key এর বড় কোনো সংখ্যা আছে সেই ইনডেক্সটাই হলো আপার বাউন্ড।
int upperBound(int a[],int n,int key)
{
    int left=0,right=n-1,index=-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==key)
        {
            index=mid;
            left=mid+1;
        }
        else if(a[mid]>key)
            right=mid-1;
        else
            left = mid + 1;
    }
    return right+1;
}
