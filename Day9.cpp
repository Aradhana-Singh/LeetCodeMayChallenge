/* Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt. */

class Solution {
public:
    bool isPerfectSquare(int num) {
        //using binary search
        long long int low = 0, high = num, mid;
        while(low <= high){
            mid = low + (high-low) /2;
            if(mid*mid == num) return true;
            else if(mid*mid < num ) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};