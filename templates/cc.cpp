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

// generate primes with seives
vector<ll> prime;
vector<ll> isprime;
void generate_primes(ll n)
{
	isprime.assign(n + 1, 1);
	for (ll i = 2; i < n + 1; i++)
	{
		if (isprime[i])
			prime.pb(i);

		for (ll j = 0; j < prime.size() && prime[j] * i < n + 1; j++)
		{
			isprime[prime[j] * i] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
}

// fac for use
vector<ll> fac;
void findfac(ll k)
{
	fac.assign(k + 1, 1);
	for (long long i = 1; i <= k; i++)
	{
		fac[i] = i * fac[i - 1];
	}
}

// get prime factors 
vector<ll> p_factors(ll x)
{
	vll p;
	ll k = x;
	for(ll i = 2; i<= k/2; i++)
	{
	if(x%i == 0)
	p.pb(i);

	while(x%i == 0)
	x /= i; 

	if(x == 1) break;
	}

	return p;
}

void obhai_op()
{
long long unsigned int n,k,s; cin>>n>>k>>s;
vii ans;
while(s){
    ll rem = s%k;
    if(rem == 1 || rem == 0)
    ans.pb(rem);
    else if(rem == k-1)
    {
    ans.pb(-1);
    s++;
    }else{
        cout<<"-2\n"; return;
    }
    s /= k;
}

if(ans.size() <= n)
{
    for(auto k: ans) cout<<k<<" ";
    ll j = 0;
    while(j<n-ans.size())
    cout<<"0 ";
    cout<<"\n";
}
else
cout<<"-2\n";

}

int main()
{
    fio 
	int tc;
    cin >> tc;
    // generate_primes(1e3);
	// findfac(6e5);
    while(tc--) {
    obhai_op();
    }
    return 0;
}