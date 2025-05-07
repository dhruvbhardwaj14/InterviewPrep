#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
You are also given an integer ‘k’.
You have to place 'k' new gas stations on the X-axis.
You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.
Find the minimum value of dist.*/

/*
Approach- 
can be done by using priority queue as well Watch video if wanna know 
optimal is space-o(1) using binary search

mid- denotes the minimu value of maximum dist
range- [0,max distance between any consecutive numbers]
step size- instead of ++ or +1 we use +1e-6   as answer is in long doubles
if at a value of mid we get lesser number of gas stations that's fine go on left hi=mid-1 and store ans
but if we get more number of gas stations then go on right that means lo=mid+1;

calcGas()- logic normal logic but if number exactly divides the distance then we have to place 1 less places
Like if distance =1 then if mid=0.5 and 0.5 exactly divides 1 in 2
so quotient is 2 but we can place 1 in between that is why --;
*/
int calcGas(vector<int> &arr, long double mid){
	int cnt=0;
	for(int i=0;i<arr.size()-1;i++){
		int numberInBetween=((arr[i+1]-arr[i])/mid);
		if((arr[i+1]-arr[i])/mid == numberInBetween*mid){
			numberInBetween--;
		}
		cnt+=numberInBetween;
	}
	return cnt;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long double lo=0,hi=0,ans=-1;
	for(int i=0;i<arr.size()-1;i++){
		hi=max(hi,(long double)arr[i+1]-arr[i]);
	}
	while(hi-lo>1e-6){
		long double mid =lo+((hi-lo)/(2.0));
		if(calcGas(arr,mid)>k){
			lo=mid;
		}
		else{
			ans=hi;
			hi=mid;
		}
	}
	cout<<ans<<endl;
    return 0;
}