class Solution {
public:
    int rabinKarp(string& text, string& pattern) {
        int t = text.size(), n = pattern.size();
        long long mod = 1e9 + 7, base = 26;
        
        long long power = 1;
        for (int i = 0; i < n - 1; i++) power = power * base % mod;
        
        long long hashP = 0, hashW = 0;
        for (int i = 0; i < n; i++) {
            hashP = (hashP * base + (pattern[i] - 'a')) % mod;
            hashW = (hashW * base + (text[i] - 'a')) % mod;
        }
        
        for (int i = 0; i <= t - n; i++) {
            if (hashW == hashP) {
                if (text.substr(i, n) == pattern) return i;
            }
            if (i + n < t) {
                hashW = (hashW - (text[i] - 'a') * power % mod + mod) % mod;
                hashW = (hashW * base + (text[i + n] - 'a')) % mod;
            }
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        
        string repeated = a;
        int cnt = 1;
        while ((int)repeated.size() < n) {
            repeated += a;
            cnt++;
        }
        repeated += a; cnt++;
        
        int idx = rabinKarp(repeated, b);
        if (idx == -1) return -1;
        return (idx + n + m - 1) / m;
    }
};