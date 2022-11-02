///searching from array, return index if found, return -1 if not found
int binarySearch(int a[],int n,int key)
{
    int left=0,right=n-1,index=-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==key)
        {
            index=mid;
            break;
        }
        else if(a[mid]>key)
            right = mid -1;
        else
            left = mid + 1;
    }
    return index;
}
