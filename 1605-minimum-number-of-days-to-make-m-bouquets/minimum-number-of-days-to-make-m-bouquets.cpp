class Solution {
public:
    int posible(vector<int>& arr , int k , int m , int n , int mid)
    {
        int count=0;
        int bouquets = 0;
        if(n < (long long)k*m) return -1;
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i]<=mid) count++;

            else if(arr[i]>mid)
            {
                bouquets  += (count/k);
                count = 0;
            }

        }
        bouquets += count/k;
        return bouquets ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int e = *max_element(bloomDay.begin() , bloomDay.end());
        int s = *min_element(bloomDay.begin() , bloomDay.end());;
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            int bouquets = posible(bloomDay , k , m , n , mid);
            if(bouquets >= m)
            {
                ans = mid; 
                e=mid-1;
            } 

            else if(bouquets < m)
            {
                s=mid+1;
            }
            
        }
        return ans;
    }
};