/* Jewels and Stones */
/* You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have.  
Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> check(60,false);
        int result = 0;
        for(int i = 0; i<J.size(); i++){
            check[J[i]-'A'] = true;
        }
        for(int i = 0; i<S.size(); i++) {
            if(check[S[i]-'A']) result++;
        }
        return result;
    }
};