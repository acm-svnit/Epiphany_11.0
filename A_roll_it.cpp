#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
 	int n, k;
 	cin>>n>>k;
 	string s;
 	cin>>s;
 	for( int i = 0 ; i < n ; i ++ ){
 		int temp = ((s[i]-'a') + k);
 		temp = temp%26;
 		s[i] = (char)('a' + temp);
 	}
 	cout<<s;
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
