class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        int isneg = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && s[i] == '-') {
            isneg = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (ans > (INT_MAX - digit) / 10) {
                return (isneg == -1) ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * isneg;
    }
};