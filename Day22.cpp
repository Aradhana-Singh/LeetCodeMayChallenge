//Sort Characters By Frequency
class Solution {
public:
    
    static bool compare(pair<char,int> &p1, pair<char, int> &p2){ 
        return p1.second > p2.second; 
    } 
    string frequencySort(string s) {
        if(s=="") return s;
        map<char,int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        int n = mp.size();
        pair<char,int> pr[n];
        int j=0;
        for(auto itr : mp){
            pr[j++] = make_pair(itr.first, itr.second);
        }
        
        sort(pr , pr+n , compare);
        s="";
        for(int i = 0 ; i<n ; i++){
            while(pr[i].second--){
                s += pr[i].first;
            }
        }
        return s;
    }
};