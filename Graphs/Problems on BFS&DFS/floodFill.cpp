#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/

/*Approach- 
1. The original color is the colour of the cell sr and sc and if it matches with the color we are assigned to pixelate and flood with then we return the image as it is.
2. Now push into queue the {sr,sc,originalColor} and mark it's color in image[sr][sc] as color now and then run BFS like queue implementation of this and check if nrow and ncol are valid and color matches then simply change it's colour and push in the queue with previous original colour
*/
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m=image.size();
    int n=image[0].size();
    int originalColor = image[sr][sc];
    if (originalColor == color) return image; 

    queue<pair<pair<int,int>,int>> q;
    q.push({{sr,sc},originalColor});
    image[sr][sc]=color;

    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};

    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;

        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==originalColor){
                image[nrow][ncol]=color; //changed the color
                q.push({{nrow,ncol},originalColor});//pushed with previous original colour
            }
        }
    }
    return image;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> image(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>image[i][j];
        }
    }
    vector<vector<int>> ans=floodFill(image,1,1,2);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}