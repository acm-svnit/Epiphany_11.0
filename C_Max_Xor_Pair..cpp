#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
using namespace std ;
const ll mod = 1e9 + 7 ;
const ll inf = 1e18;
const int p = 1e5+7;

void solve()
{
	int n,a,b,c;
	cin >> n;

    if(n == 2){
        cout << 2 << " " << 1 << endl;
        return;
    }

	cout << 1 << " " << n-2 << " " << n-1 << endl;
    cin >> a;

    cout << 1 << " " << n-2 << " " << n << endl;
    cin >> b;

    cout << 1 << " " << n-1 << " " << n << endl;
    cin >> c;

    int max = a ^ b;
    int m1 = max ^ c;
    int m2 = m1 ^ a;

    ll p = 1;

    while(p <= max) p <<= 1;
    p >>= 1;

    if(!(m1 & p)){
        cout << 2 << " " << n-1 << endl;
        return;
    }

    if(!(m2 & p)){
        cout << 2 << " " << n-2 << endl;
        return;
    }

    if(n <= 4){
        cout << 2 << " " << 1 << endl;
    }

    int l = 1;
    int r = n-3;
    int mid;

    while(l<r){
        mid = (l + r) >> 1;
        
        cout << 1 << " " << mid << " " << n << endl;
        cin >> a;

        cout << 1 << " " << mid+1 << " " << n <<endl;
        cin >> b;

        if(!((a&p)^(b&p))){
            l = mid+1;
        }
        else r = mid;
    }
    cout << 1 << " " << l << " " << l+1 << endl;
    cin >> a;

    if(l>1){
        cout << 1 << " " << l-1 << " " << l << endl;
        cin >> b;
    }
    
    if(l>1 && b>a)cout<<2<<" "<<l-1<<endl;
    else cout<<2<<" "<<l<<endl;
}

int main()
{
   	ios_base::sync_with_stdio(false) ;
    cin.tie(NULL); 
    cout.tie(NULL) ;  
   	
  
    
    int t = 1 ; 
	cin >> t ;
    
    while( t-- )
    {
    	solve();
    	//cout<<"\n";
    }

    
    return 0 ;
      
}