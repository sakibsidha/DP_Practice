#include <bits/stdc++.h>
using ll = long long;

void solve(){
    std::string s; 
    std::cin >> s;
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
    std::function<int(int,int)> f = [&](int i, int j){
        if(i == j) return 1;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = 2 + f(i + 1, j - 1);
        else return dp[i][j] = std::max(f(i + 1, j), f(i, j - 1));
    };
    std::cout << f(0, n-1) << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    //int tc; std::cin >> tc;
    //while(tc--)
        solve();
        
    return 0;
}
