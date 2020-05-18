/*Permutation in String

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int count =0;
        if(n>m) return false;
        unordered_map<char,int> map;
        for(int i =0; i<n ; i++) map[s1[i]]++;
        for(int i = 0; i<m; i++ ){
            if(map.find(s2[i])!=map.end()){
                if(map[s2[i]]>0){
                count++;}
                map[s2[i]]--;
            }
            if(count == n) return true;
            
            if(i>= n-1){
                int index = i-n+1;
                if(map.find(s2[index])!=map.end()){
                    map[s2[index]]++;
                    if(map[s2[index]]>0)
                    count--;
                }
            }
        }
        return false;
    }
};