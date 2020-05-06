/*Majority Element

Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto itr = mp.begin(); itr!=mp.end(); itr++){
            if(itr->second > nums.size()/2) return itr->first; 
        }
        return 1;
    }
};