class Solution {
public:
    bool possible(vector<int>& nums , int m , int n , int k)
    {
        int sum = 0;
        int count = 1;
        for(int i=0 ; i<n ; i++)
        {
            if(sum+nums[i]<=m)
            {
                sum+=nums[i];
            }
            else
            {
                count++;
                sum = nums[i];
                
                if(count>k || nums[i]>m)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int e = accumulate(nums.begin() , nums.end() , 0);
        int ans = -1;
        int s = 0;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(possible(nums , m , n , k))
            {
                ans = m;
                e=m-1;
            }
            else 
            {
                s=m+1;
            }
        }
        return ans;
    }
};