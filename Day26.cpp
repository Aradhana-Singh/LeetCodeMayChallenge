//Contiguous Array
/*Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int maxLen = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            count = count + (num == 1 ? 1 : -1);
            if (m.count(count) > 0) {
                maxLen = max(maxLen, i - m[count]);
            } else {
                m[count] = i;
            }
        }
        return maxLen;
    }
};