#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
template<class T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sz(y) (int) y.size()
#define endl "\n"
#define sim template < class c 
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {  
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {  
  *this << "[";  
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define db(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
// state: dp[i][j] = maximum score achieved at i'th step such that we took j'th activity at this step
// transition: dp[i][j] = max(dp[i-1][1/2 excpt j],dp[i-1][1/2 excpt j]) + dp[i][j];	
	ll n; cin >> n;
	vector<vector<ll>> v(n,vector<ll>(3)),dp(n,vector<ll>(3));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> v[i][j];
		}
	}
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			if(j==0) dp[i][j] = max(dp[i-1][1],dp[i-1][2]) + v[i][j];
			if(j==1) dp[i][j] = max(dp[i-1][0],dp[i-1][2]) + v[i][j];
			if(j==2) dp[i][j] = max(dp[i-1][0],dp[i-1][1]) + v[i][j];
		}
	}
	cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int tc; cin >> tc;
	//while(tc--)
		solve();

	return 0;
}
