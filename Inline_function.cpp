#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
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
typedef unordered_map<ll, ll> uomap;
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
#define rep(x, a, b) for (int x = a; x < b; x++)
#define repl(x, a, b) for (long long int x = a; x < b; x++)
#define F first
#define S second
#define pb push_back
#define RT return;
const ll mod = 1e9 + 7;
// helper functions
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void BINDAS()
{
	ll n; cin>>n;
	vll d(n), s(n);
	rep(i,0,n) cin>>d[i];
	rep(i,0,n) cin>>s[i];
	vvll adj(n); ll u,v;
	rep (i,0,n-1){
		cin>>u>>v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll ans = 0;
	vll s_new(n,0), d_new(n,0);
	// function sol
	function<void(ll, ll)> sol = [&](ll u, ll p){
		s_new[u] = s[u], d_new[u] = d[u];
		for(auto &v: adj[u]){
			if (v == p) continue;
			sol(v,u);
			d_new[u] += d_new[v];
			s_new[u] += s_new[v];
		}
		ans += abs(d_new[u] - s_new[u]);
	};
	// if a function returns pair<ll,ll> then call it like this
	// function<pair<ll,ll>(ll, ll)> sol = [&](ll u, ll p){...; return {a,b};}; 
	sol(0,-1);
	cout<<ans<<"\n";
}

int main()
{
	fio int tc;
	// tc = 1;
	cin >> tc;
	while (tc--)
	{
		BINDAS();
	}
	return 0;
}