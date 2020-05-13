/* First Unique Character in a String */

/* Given a string, 
find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1. */

class Solution {
public:
    int firstUniqChar(string s) {
        pair <int,int> count[26];
        for(int i=0; i<s.size(); i++){
            count[s[i]-'a'].first++;
            count[s[i]-'a'].second = i;
        }
        int min_index = INT_MAX;
        for(int i=0; i<26 ; i++){
            if(count[i].first == 1){
                min_index = min(min_index , count[i].second);
            }
        }
        if(min_index == INT_MAX) return -1;
        else return min_index;
    }
};
