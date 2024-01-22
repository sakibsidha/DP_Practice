class Solution {
public:
    string s, t;
    int n, m;
    int dp[501][501];
    int f(int i, int j, int n, int m) {
        if (i == n || j == m) {
            if (i == n)
                return (m - j);
            else
                return (n - i);
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            int a = f(i + 1, j + 1, n, m); // no change
            int b = 1 + f(i + 1, j + 1, n, m); // add
            int c = 1 + f(i + 1, j, n, m); // remove
            int d = 1 + f(i, j + 1, n, m); // replace
            dp[i][j] = min(a, min(b, min(c, d)));
        } else {
            int b = 1 + f(i + 1, j + 1, n, m);
            int c = 1 + f(i + 1, j, n, m);
            int d = 1 + f(i, j + 1, n, m);
            dp[i][j] = min(b, min(c, d));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        s = word1;
        t = word2;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, n, m);
    }
};
