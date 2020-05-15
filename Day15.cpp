/*Maximum Sum Circular Subarray

Given a circular array C of integers represented by A, 
find the maximum possible sum of a non-empty subarray of C.
Here, a circular array means the end of the array connects to the beginning of the array.  
(Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
Also, a subarray may only include each element of the fixed buffer A at most once.  
(Formally, for a subarray C[i], C[i+1], ..., C[j], 
there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)*/

class Solution {
public:
    int kadane(vector<int>&A){
        int maxSoFar = A[0];
        int curSum = A[0];
        for(int i =1; i<A.size(); i++){
            curSum = curSum+A[i];
            if(curSum < A[i]){
                curSum = A[i];
            }
            maxSoFar = max(curSum, maxSoFar);
        }
        return maxSoFar;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int ans1 = kadane(A);
        int sum = 0;
        for(int i = 0; i<A.size(); i++) {
            sum+=A[i];
            A[i] = -A[i];
        }
        int ans2 = kadane(A);
        ans2 += sum;
        if(ans2 == 0) return ans1;
        return max(ans1,ans2);
    }
};