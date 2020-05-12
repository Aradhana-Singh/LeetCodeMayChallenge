/*Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. 
Find this single element that appears only once.*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low = 0, high = nums.size()-1,mid;
        while(low+2 < high){
            mid = low + (high-low)/2;
            if((high-low)%4 ==0){
                if(nums[mid] == nums[mid+1]) low = mid;
                else if(nums[mid] == nums[mid-1]) high = mid;
                else return nums[mid];
            }
            else{
                if(nums[mid] == nums[mid+1]) high = mid-1;
                else if(nums[mid] == nums[mid-1]) low = mid+1;
                else return nums[mid];
            }
        }
        if(nums[low] == nums[low+1]) return nums[high];
        else return nums[low];
    }
};