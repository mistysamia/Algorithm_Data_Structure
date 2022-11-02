///searching from array the last occurrence, return index if found, return -1 if not found
int lastOccurrence(int a[],int n,int key)
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
    return index;
}
