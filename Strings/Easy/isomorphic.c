/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
bool isIsomorphic(char* s, char* t) {
    int* arr=calloc(256,sizeof(int));
    bool* vis=calloc(256,sizeof(bool));
    if (arr == NULL || vis==NULL) {
        return NULL;
    }
    for (int i = 0; i < 256; i++) {
        arr[i] = -1;
        vis[i]=false;
    }
    int i=0;
    while (s[i]!='\0' && t[i]!='\0')
    {
        if(arr[(int)s[i]]==-1){
            if(!vis[(int)t[i]]){
            arr[(int)s[i]]=(int)t[i];
            vis[(int)t[i]]=true;
            }
            else{
                return false;
            }
        }
        else{
            if(arr[(int)s[i]]!=(int)t[i]){
                return false;
            }
        }
        i++;
    }
    
    return true;
}
int main(){
    char *s=malloc(sizeof(char)*10);
    char *t=malloc(sizeof(char)*10);
    scanf("%s",s);
    scanf("%s",t);
    if(isIsomorphic(s,t)) printf("Valid");
    else printf("InValid");
    return 0;
}