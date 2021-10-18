#include<bits/stdc++.h>
using namespace std;


int dp[101][30001];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first+a.second>b.first+b.second;
}

int rec(int i,vector<pair<int,int>> b,int rnow)
{
	if(i==b.size())
	return 0;
	
	if(rnow<0)
	{
		
		return -10000000;
	}
	
	
	if(dp[i][rnow]!=-1)
	return dp[i][rnow];
	int ans=0;
	
	ans=max(ans,rec(i+1,b,rnow));
	
	if(b[i].first<=rnow)
	ans=max(ans,1+rec(i+1,b,rnow+b[i].second));
	
	return dp[i][rnow]=ans;
}
int main()
{
	
	memset(dp,-1,sizeof(dp));
	int n,r;
	cin>>n>>r;
	
	vector<pair<int,int>> a,b;
	
	for(int i=0;i<n;++i)
	{
		int l,r;
		cin>>l>>r;
		
		if(r>=0)
		a.push_back({l,r});
		else
		{
			l=max(l,-r);
			b.push_back({l,r});
		}
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),cmp);
	
	int ans=0;
	
	for(int i=0;i<a.size();++i)
	{
		if(r<a[i].first)
		{
			break;
		}
		else
		{
			r+=a[i].second;
			++ans;
		}
	}
	

	
	int dpres=0;
	
	dpres=rec(0,b,r);
	
	cout<<dpres+ans<<"\n";
	
	
	
	
}
