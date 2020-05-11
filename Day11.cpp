/*Flood Fill*/
/* An image is represented by a 2-D array of integers, 
each integer representing the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, 
and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, 
plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), 
and so on. Replace the color of all of the aforementioned pixels with the newColor.
At the end, return the modified image.*/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int newColor){
        if(image[row][col] == color){
            image[row][col] = newColor;
            if(row+1 < image.size()) dfs(image, row+1, col, color, newColor);
            if(col+1 < image[0].size()) dfs(image, row, col+1, color, newColor);
            if(row > 0) dfs(image, row-1, col, color, newColor);
            if(col > 0) dfs(image, row, col-1, color, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color != newColor)
            dfs(image, sr, sc, color, newColor);
        return image;
    }
};