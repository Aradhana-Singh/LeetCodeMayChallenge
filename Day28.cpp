/* Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate 
the number of 1's in their binary representation and return them as an array.*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int i = 0,j =0 ;
        while(num--){
            if(i == j){
                i = 0;
                j = res.size();
            }
            res.push_back(res[i++] + 1);
        }
        return res;
    }
};