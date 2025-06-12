/*You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char* largestOddNumber(char* num) {
    int n=0;
    while (num[n]!='\0'){
        n++;
    }
    int idx=n-1;
    while(idx>=0 && !((num[idx]-'0')&1)){
        idx--;
    }
    char* ans=malloc(idx+2);
    ans[idx+1]='\0';
    for (int i = 0; i <=idx; i++)
    {
        ans[i]=num[i];    
    }
    return ans;
        
}
int main(){
    int a=('5'-'0');
    printf("%d",a);
    return 0;
}