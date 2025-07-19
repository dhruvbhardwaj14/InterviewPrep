 indx is what we always take in our helper function to keep track of current element
 we use the approach of take or not take in the recursion to recursively run the program and get all subsequences
 to print all subsequences-> then just run normally until idx reaches arr.size() and print
 to print just one subsequence-> return true whenever the condition is met (for sum cases) and in main function print only if true is returned else print nothing
 to count number of subsequence-> return 1 for condition matched and return 0 for not matched and add all 1s and 0s in that function only

 different patterns to solve array problems
 1. Take or not take (indx=index,arr=given arr,ds=data structure to store a vector,ans=final ans to store multiple ds)
 -> f(idx,arr,ds,ans,target)
 base case if indx>=n and if target=0(for subsequence sum problems)
 ->>>>>ds.add(arr[idx]);
 ->>>>>f(idx+1,arr,ds,ans);
 ->>>>>ds.remove(arr[idx]);
 ->>>>>f(idx+1,arr,ds,ans);

2.Take subsequence or not(indx=index,arr=given arr,ds=data structure to store a vector,ans=final ans to store multiple ds)
->f(idx,arr,ds,ans,target)
base case if target=0(for unique subsequence sum with each element only once)
->>> for loop i from idx to arr.size()
->>>>>>>>>ds.add(arr[i])
->>>>>>>>>f(i+1,arr,ds,ans,target-arr[i])
->>>>>>>>>ds.remove(arr[i])
