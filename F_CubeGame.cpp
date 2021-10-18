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
const int N = 1e5 + 7;
int tc = 1;
pair<ll, int> seg[N * 4]; 
int lazy[4 * N], a[N], h[N];
int sz[N], par[N][30], t[N];
vector<int> euler, vtx[N];
inline pair<ll, int> max(pair<ll, int> a, pair<ll, int> b){
    if(a.ff == b.ff){
        if(a.ss < b.ss) return a;
        return b;
    }
    else if(a.ff > b.ff) return a;
    return b;
}
void dfs(int u, int p){
    euler.pb(u);
    sz[u] = 1;
    h[u] = h[p] + 1; 
    t[u] = euler.size() - 1;
    for(auto v : vtx[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void build(int l, int r, int node){
    if(l == r){
        seg[node].ff = a[euler[l]] - h[euler[l]];
        seg[node].ss = euler[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, node * 2);
    build(mid + 1, r, node * 2 + 1);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
inline void push(int l, int r, int node){
    if(lazy[node] == 0) return;
    seg[node].ff += lazy[node];
    if(l != r){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node]; 
    }
    lazy[node] = 0;
}
void update(int l, int r, int tl, int tr, int node, int val){
    push(tl, tr, node);
    if(l > r) return;
    if(tl == l && tr == r){
        lazy[node] = val;
        push(tl, tr, node);
        return;
    }
    int tm = (tl + tr) / 2;
    update(l, min(tm, r), tl, tm, node * 2, val);
    update(max(tm + 1, l), r, tm + 1, tr, node * 2 + 1, val);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
pair<ll, int> rangemax(int l, int r, int tl, int tr, int node){
    if(l > r) return {-mod, 0};
    if(l == tl && r == tr) return seg[node];
    int tm = (tl + tr) / 2;
    return max(rangemax(l, min(tm, r), tl, tm, node * 2), rangemax(max(tm + 1, l), r, tm + 1, tr, node * 2 + 1));
}
void dfs2(int u, int p, int n){
    if(u != 1){
        update(0, t[u] - 1, 0, n - 1, 1, -1);
        update(t[u], t[u] + sz[u] - 1, 0, n - 1, 1, 1);
        update(t[u] + sz[u], n - 1, 0, n - 1, 1, -1);
    }
    auto v = rangemax(0, t[u] - 1, 0, n - 1, 1);
    v = max(v, rangemax(t[u] + 1, n - 1, 0, n - 1, 1));
    par[u][0] = v.ss;
    for(auto k : vtx[u]){
        if(k != p) dfs2(k, u, n);
    }
    update(0, t[u] - 1, 0, n - 1, 1, 1);
    update(t[u], t[u] + sz[u] - 1, 0, n - 1, 1, -1);
    update(t[u] + sz[u], n - 1, 0, n - 1, 1, 1);
}
void solve(){
    int n, q;
    ll k;
    cin >> n;
    q = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        vtx[u].pb(v);
        vtx[v].pb(u);
    }
    dfs(1, 0);
    build(0, n - 1, 1);
    dfs2(1, 0, n);
    for(int i = 1; i < 30; i++){
        for(int j = 1; j <= n; j++){
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    cin >> q;
    while(q--){
        int x;
        cin >> x >> k;
        for(int i = 29; i >= 0; i--){
            if((1ll << i) & k){
                x = par[x][i];
            }
        }
        cout << x << "\n";
    }
    // cout << "Case #" << tc << ": " << ans + k << "\n";
    // tc++;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t = 1;
	// cin >> t;
	while (t--) 
	    solve();
	return 0; 
}
/*
*/