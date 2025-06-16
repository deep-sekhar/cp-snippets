#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define modu 1000000007
#define fio                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define yes cout << "yes\n";
#define Yes cout << "Yes\n";
#define YES cout << "YES\n";
#define no cout << "no\n";
#define No cout << "No\n";
#define NO cout << "NO\n";
#define NL cout << "\n";
#define ckk cout << " = ";
#define MN cout << "-1\n";
#define all(k) k.begin(), k.end()
#define c(i, v) for (auto &i : v)
#define f(x, a, b) for (int x = a; x < b; x++)
#define ff(x, a, b) for (long long int x = a; x < b; x++)
#define pb push_back
#define RT return;


void l_bound(vii a, int x)
{
    int n = a.size();
    int l = 0, h = n-1;
    while(l<=h)
    {
        int mid = l + (h-l)/2;
        if(a[mid] < x )
         l = mid+1;
        else if(a[mid] > x )
         h = mid-1;
        else h = mid-1;
    }

    if(l == n ) cout<<"not found";
    else cout<<"l bound is "<<a[l]<<"\n";
}

void u_bound(vii a, int x)
{
    int n = a.size();
    int l = 0, h = n-1;
    while(l<=h)
    {
        int mid = l + (h-l)/2;
        if(a[mid] < x )
         l = mid+1;
        else if(a[mid] > x )
         h = mid-1;
        else l = mid+1;
    }

    if(l == n ) cout<<"not found";
    else cout<<"upper bound is "<<a[l]<<"\n";
}

ll p( ll a, ll b )
{
  ll res = 1;
  a %= modu;
  while(b){
    if(b & 1) res = (res * a) % modu;
    b = b << 1;
    a = (a * a) % modu;
  }
  return res;
}

void obhai_op()
{
    ll n; cin>>n;
    ll maxsum = (n*(n+1))/2;
    vvll dp ( 1+n, vll( maxsum+1 ) );
    ff(i,0,n+1)
    dp[i][0] = 1;

    ff(i,1,n+1)
    {
      ff(j,1, maxsum+1)
      {
        if(j-i>=0) dp[i][j] = (dp[i-1][j]%modu + dp[i-1][j-i]%modu)%modu;
        else dp[i][j] = dp[i-1][j];
      }
    }

    if(maxsum%2 == 0) { cout<<dp[n-1][maxsum/2]; return; }
    else { cout<<0; return; }
}

int main()
{
    fio 
	int tc = 1;   
    while(tc--) {
    obhai_op();
    }
    return 0;
}