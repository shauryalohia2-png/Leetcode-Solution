class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int e=n-1;
        int s=0;
        int maxel = INT_MIN;
        
        //We will use pivot over here.
        while(s<e)
        {
            int m = s+(e-s)/2;
            if(nums[m] < nums[m+1])
            {
                s=m+1;
            }
            else
            {
                e=m;
            }
        }
        return e;
    }
};