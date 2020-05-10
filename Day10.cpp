/* Find the Town Judge

In a town, there are N people labelled from 1 to N.  
There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing 
that the person labelled a trusts the person labelled b.
If the town judge exists and can be identified, return the label of the town judge.  
Otherwise, return -1.*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0) return N;
        vector<int> vec (N+1,0);
        for(int i = 0; i<trust.size(); i++){
            vec[trust[i][1]]++;
        }
        int judge = distance(vec.begin(),max_element(vec.begin(),vec.end()));
        
        vec.clear();
        vector<bool> check(N+1,false);
        for(int i = 0 ; i<trust.size(); i++){
            if(trust[i][0]==judge) return -1;
            if(trust[i][1]==judge) check[trust[i][0]] = true;
        }
        for(int i=1; i<=N; i++){
            if(i == judge)continue;
            if(check[i]==false) return -1;
        }
        return judge;
    }
};
