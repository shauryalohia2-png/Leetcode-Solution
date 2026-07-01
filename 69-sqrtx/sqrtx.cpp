class Solution {
public:
    int mySqrt(int n) {

      if(n==0) return 0;
      
      int e=n;
      int s=1;
      int ans=0;
      long long sq;
      while(s<=e)
      {
        long long m = s+(e-s)/2;
        sq = m*m;
        if(sq==n) return m;
        else if(sq<n) 
        {
            ans = m;
            s=m+1;
        }
        else
        {
            e=m-1;
        }
      }
      return ans;
    }
};
    