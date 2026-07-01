class Solution {
public:
    long long calh(vector<int>& arr , int h){
        long long totalh = 0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            totalh += ceil((double)arr[i] / h);
        }
        return totalh;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int e = *max_element(piles.begin() , piles.end());
        int s=1;
        int ans = 0;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            long long totalh = calh(piles , m);
            
            if(totalh <= h)
            {
                ans=m;
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