/*Remove K Digits*/

/*Given a non-negative integer num represented as a string, 
remove k digits from the number so that the new number is the smallest possible.
Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int j = 0, i = 0;
        
        //Remove all characters
        if( k == num.size()) return "0";
        
        
        while(j < k ){
            if(num[i] > num[i+1]) {
                num.erase(num.begin() + i);
                if(i>0) i--;
                j++;
            }
            else i++;
        }
        
        
        
        //Removing leading zeros
        for(i = 0 ; i<num.size()-1; ){
            if(num[i] == '0') num.erase(num.begin()+i);
            else break;
        }
        return num;
    }
};