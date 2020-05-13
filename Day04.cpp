/* Number Complement*/

/* Given a positive integer, output its complement number. 
The complement strategy is to flip the bits of its binary representation. */

class Solution {
public:
    int findComplement(int num) {
        int n = log2(num);
        long int x = 1<<(n+1);
        return num^(x-1);
    }
};