class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        int first = find(nums , x , true);
        int last = find(nums , x , false);
        
        return {first,last};
    }
    int find(vector<int> nums , int x , bool isfirst)
    {
        int n=nums.size();
        int e=n-1;
        int s=0;
        int boundary = -1;

        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(nums[m]==x)
            {
                boundary = m;
                if(isfirst) e=m-1;
                else if(!isfirst) s=m+1;
            }
            
            else if(nums[m]<x) s=m+1;
            else e=m-1;
        }
        return boundary;
    }
};