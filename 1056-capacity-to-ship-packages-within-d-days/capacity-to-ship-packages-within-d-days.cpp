class Solution {
public:
    bool possible(vector<int>& weights , int n , int days , int mid) {
        int sum = 0;
        int count = 1;
        for(int i=0 ; i<n ; i++)
        {
            if(sum+weights[i] <= mid)
            {
                sum += weights[i];
            }
            else
            {
                count++;
                sum = weights[i];
                if(count > days || weights[i]>mid)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            sum += weights[i];
        }
        
        int e = sum;
        int s = 0;
        int ans = 0;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(possible(weights , n , days , mid))
            {
                ans = mid;
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