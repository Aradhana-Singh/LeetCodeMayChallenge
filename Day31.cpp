//EDIT DISTANCE


class Solution {
public:
    vector<vector<int>> memo;
    int fun(string s1, string s2 , int i , int j){
        if(memo[i][j] != -1) return memo[i][j];
        if(i == 0)
            memo[i][j] = j;
        else if(j == 0)
            memo[i][j] = i;
        else if(s1[i-1] == s2[j-1])
            memo[i][j] = fun(s1, s2, i-1,j-1);
        else
            memo[i][j] = 1 + min(min(fun(s1, s2, i-1,j) , fun(s1, s2, i,j-1)) , fun(s1, s2, i-1,j-1));
        return memo[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memo.resize(n+1,vector<int>(m+1,-1));
        return fun(word1, word2 , n, m);
    }
};