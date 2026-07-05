class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int e = n-1;
        int s = 0;
        int ans = -1;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            int missing = arr[m] - (m + 1);
            if(missing < k)
            {
                ans = m;
                s=m+1;
            }

            else if(missing >= k)
            {
                e=m-1;
            }
        }
        if(ans == -1) return k;

        return (ans + 1) + k;
    }
};