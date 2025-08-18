binary search on answers is only applicable when in a range a least or minimum or maximum or max(mini) or min(max) is asked 
in normal binary search (lo<=hi) condition works for integers but when we have to do it on doubles ( we are always given a range in that case ) we do like while(hi-lo>range) consider gasStations here

template binary search 
determine range [lo,hi]
while(){
    check()
    if(condition with check return value of check ) ans/lo=Mid+1
    else ans/hi=mid-1
}
return ans;

ways to find mid
1. mid=(lo+hi)/2;
2. mid=lo+((hi-lo)/2);
3. mid=(lo+hi)>>1;