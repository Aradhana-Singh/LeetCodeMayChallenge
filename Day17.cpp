/* Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and 
the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m>n) return{};
        int start=0;
        int matched = 0;
        vector<int> res;
        unordered_map<char,int> map;
        for(auto x : p) map[x]++;
        
        for(int end =0 ; end<s.size(); end++){
            char right  = s[end];
            if(map.find(right)!=map.end()){
                map[right]--;
                if(map[right]==0){
                    matched++;
                }
            }
            if(matched==map.size())
            {
                res.push_back(start);
            }
            if(end>=p.size()-1){
                char left = s[start++];
                if(map.find(left)!=map.end()){
                    if(map[left]==0){
                        matched--;
                    }
                    map[left]++;
                }
            }
            
        }
        return res;
    }
};