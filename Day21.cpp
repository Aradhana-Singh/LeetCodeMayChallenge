//Count Square Submatrices with All Ones
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int  n = matrix.size();
        int m = matrix[0].size();
        int ans=0,minimum=0;
        for(int i = 0 ; i<n ; i++) ans += matrix[i][0];
        for(int i = 1 ; i<m ; i++) ans += matrix[0][i];
        for(int i =1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==1){
                    minimum = min(matrix[i-1][j],matrix[i][j-1]);
                    minimum = min(minimum , matrix[i-1][j-1]);
                    matrix[i][j] += minimum;
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};