#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n; cin >> n;
	vector<long long> v(n), dp(n, 0);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	// state: dp[i] is the LIS starting from idx i
	// transition: dp[i] = 1 + max(dp[j]) where i < j < n
	vector<long long> next(n, -1);
	for(int i = n-1; i >= 0; --i){
		long long mx = 0;
		for(int j = i+1; j < n; ++j){
			if(v[j] > v[i]){
				if(dp[j] > mx){
					next[i] = j; // when we get a better ans, we keep track of the path
					mx = dp[j];
				}
			}
		}
		dp[i] = 1 + mx;
	}
	long long ans = 0, start = -1;
	for(int i = 0; i < n; ++i){
		if(dp[i] > ans){
			start = i;
			ans = dp[i];
		}
	}
	cout << "Length: " << ans << endl;
	vector<long long> lis;
	while(start != -1){
		lis.push_back(v[start]);
		start = next[start];
	}
	cout << "LIS: ";
	for(auto it: lis) cout << it << ' ';
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//int tc; cin >> tc;
	//while(tc--)
		solve();
	
	return 0;
}
