#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int n;
struct T1 {
	int mx[(1 << 20) + 1];
	inline void upd(int x, int val) {
		x += n;
		mx[x] = val;
		for (; x /= 2; mx[x] = max(mx[x * 2], mx[x * 2 + 1]));
	}
	inline int fnd(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = max(ans, mx[l]);
			if (~r & 1) ans = max(ans, mx[r]);
		}
		return ans;
	}
};

struct T2{ 
	int mx[(1 << 20) + 1];
	inline void upd(int l, int r, int val) {
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) mx[l] = val;
			if (~r & 1) mx[r] = val;
		}
	}
	inline int fnd(int x) {
		int ans = 0;
		for (x += n, x *= 2; x /= 2; ans = max(ans, mx[x]));
		return ans;
	}
};
int a,b,c,d,m,k;
VI sm[500002];
int en[500002], ex[500002];

T1 q1;
T2 q2;
void dfs(int v, int pr = -1) {
	en[v] = k++;
	rept(i, L(sm[v])) {
		int w = sm[v][i];
		if (w == pr) continue;
		dfs(w, v);
	}
	ex[v] = k;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d", &n);
	rept(i, n - 1) {
		scanf("%d%d", &a, &b); --a; --b;
		sm[a].pb(b);
		sm[b].pb(a);
	}
	dfs(0);
	scanf("%d", &m);
	rep(i, m) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &a); --a;
			q2.upd(en[a], ex[a] - 1, i);
		} else
		if (a == 2) {
			scanf("%d", &a); --a;
			q1.upd(en[a], i);
		} else {
			scanf("%d", &a); --a;
			int v1 = q1.fnd(en[a], ex[a] - 1);
			int v2 = q2.fnd(en[a]);

			if (v2 > v1) printf("1\n"); else
			printf("0\n");
		}
	}
}
