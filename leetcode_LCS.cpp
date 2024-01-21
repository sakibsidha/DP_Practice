class Solution {
public:
    string s, t;
    int n, m;
    int dp[1000][1000];
    void init(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                dp[i][j] = -1;
            }
        }
    }
    int f(int i, int j){
        if(i >= n || j >= m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i]==t[j]){
            ans = 1 + f(i+1,j+1);
        }
        else{
            int a = f(i+1,j);
            int b = f(i,j+1);
            ans += max(a,b);
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        s = text1; t = text2;
        n = s.size(); m = t.size();
        init();
        return f(0,0);
    }
};

// iterative:
// class Solution {
// public:
//     int dp[1001][1001];
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         for(int i = n-1; i >= 0; --i){
//             for(int j = m-1; j >= 0; --j){
//                 if(text1[i]==text2[j]) dp[i][j] = 1 + dp[i+1][j+1];
//                 else{
//                     dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };
