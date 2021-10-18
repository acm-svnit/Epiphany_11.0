#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll power( ll a, ll b, ll mod){
	ll res = 1;
	while(b){
		if(b&1){
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

void solve()
{
 	ll x, y, k;
 	cin>>x>>y>>k;
 	ll mod = x+y;
 	x = (x*power(2LL, k, mod))%mod;
 	y = mod - x;
 	cout<<min(x, y);
}

int main()
{
   	ios_base::sync_with_stdio(false) ;
    cin.tie(NULL); 
    cout.tie(NULL) ;  
#ifndef ONLINE_JUDGE    
    //for getting input from input.txt
    freopen("inputA.txt","r",stdin);
    //for getting output from output.txt
    freopen("outputA.txt","w",stdout);
#endif
   	
  
    
    int t = 1 ;
    cin>>t; 
    
    while( t-- )
    {
    	solve();
    	cout<<"\n";
    }

    
    return 0 ;
      
}
