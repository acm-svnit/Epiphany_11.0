#include <bits/stdc++.h>
#define int long long
using namespace std;
pair <int,int> a[10005];
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(x.second>=0&&y.second>=0) return x.first<y.first;
	if(x.second>=0&&y.second<0) return 1;
	if(x.second<0&&y.second>=0) return 0;
	int w1=max(x.first,y.first-x.second),w2=max(y.first,x.first-y.second);
	return w1<w2;
}
signed main(int argc, char** argv) {
	int n,r;
	cin >> n >> r;
	for(int i=1;i<=n;i++)
		cin >> a[i].first >> a[i].second;
	sort(a+1,a+n+1,cmp);
	int ans=0;
	//for(int i=1;i<=n;i++)
	//	cout << a[i].first << " " << a[i].second << "\n"; 
	for(int i=1;i<=n;i++) 
		if(r>=a[i].first&&r+a[i].second>=0) ++ans,r+=a[i].second;
	if(ans==n) cout << "Ha";
	else cout << "Na";
	return 0;
}
