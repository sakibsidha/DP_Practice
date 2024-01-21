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
