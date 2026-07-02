class Solution {
public:
    int div(vector<int>& nums , int n , int mid)
    {
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            sum += ceil((double) nums[i]/mid);     
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int e = *max_element(nums.begin() , nums.end());
        int s = 1; //*min_element(nums.begin() , nums.end());
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            int divSum = div(nums , n , mid);
            if(divSum <= threshold)
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};