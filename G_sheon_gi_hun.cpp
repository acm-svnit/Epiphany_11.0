#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;
bool com(pp x, pp y){
    if(x.ff == y.ff) return x.ss < y.ss;
    return x.ff < y.ff;
}
ll power(ll x, ll y){
    ll prod = 1;
    while(y){
        if(y & 1) prod = (prod * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return prod;
}
const int N = 5e3 + 7;
ll fact[N], dp[N][20];
inline ll ncr(ll n, ll r){
    if(r > n) return 0;
    ll ans = fact[n];
    ll x = (fact[r] * fact[n - r]) % mod;
    ans = (ans * power(x, mod - 2)) % mod;
    return ans;
}
ll calculate(int n, int m, int k, int b){
    if((1ll << b) > k) return m == 0;
    if(m < 0) return 0;
    ll ans = 0;
    if(dp[m][b] != -1) return dp[m][b];
    if((1ll << b) & k){
        ll x = 0;
        for(int j = 1; j <= n; j++){
            x += (1ll << b);
            if(m - x < 0) break;
            ans += (ncr(n, j) * 1LL * calculate(n, m - x, k, b + 1)) % mod;
            ans %= mod;
        }
    }
    else ans = calculate(n, m, k, b + 1);
    return dp[m][b] = ans;
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j < 15; j++) dp[i][j] = -1;
    }
    cout << calculate(n, m, k, 0) << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t = 1;
	// cin >> t;
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;
	while (t--) 
	    solve();
	return 0; 
}
/*
*/