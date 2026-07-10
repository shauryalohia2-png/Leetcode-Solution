class Solution {
public:
    long long myAtoi(string s) {
        long long ans = 0;
        int i=0;
        int sign = 1;
        int n=s.length();

        while(i<n && s[i] == ' ')
        {
            i++;
        }

        if(i<n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i<n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // important edge case:-
            if(ans > INT_MAX/10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            } 

            ans = ans*10 + digit;
            i++;
        }

        return ans*sign;
    }
};