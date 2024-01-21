class Solution {
public:
    vector<int> dp;
    void init(int n){
        dp.resize(n, -1);
    }
    int findLongestChain(vector<vector<int>>& pairs) { 
        init(pairs.size());
        sort(pairs.begin(),pairs.end());
        // state: dp[i] = maximum chain possible starting from i
        // transition: dp[i] = 1 + dp[j] where i < j < n
        for(int i = pairs.size()-1; i >= 0; --i){
            int mx = 0;
            for(int j = i + 1; j < pairs.size(); ++j){
                if(pairs[i][1] < pairs[j][0]){
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = 1 + mx;
        }
        int ans = 0;
        for(int i = 0; i < pairs.size(); ++i){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
