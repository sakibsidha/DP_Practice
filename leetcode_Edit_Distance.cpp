class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int,int)> f = [&](int i, int j){
            if(i < 0 && j < 0) return 0;
            if(i < 0) return j + 1;
            if(j < 0) return i + 1;
            if(dp[i][j] != -1) return dp[i][j];
            if(word1[i] == word2[j]) return dp[i][j] = f(i-1, j-1);
            else return dp[i][j] = std::min(1 + f(i-1, j), std::min(1 + f(i, j-1), 1 + f(i-1, j-1)));
        }; 
        return f(n-1, m-1);
    }
};
