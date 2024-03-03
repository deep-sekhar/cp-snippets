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
#define f(x, a, b) for (int x = a; x < b; x++)
#define ff(x, a, b) for (long long int x = a; x < b; x++)
#define F first
#define S second
#define pb push_back
#define RT return;
const ll mod = 1e9 + 7;

// helper functions
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

// dsu by size 
class dsu{
    vll sz;
    vll par;

    public:
    dsu(ll n){
        sz.resize(n,1);
        par.resize(n);
        iota(all(par),0);
    }

    ll find(ll x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }

    void unite(ll x,ll y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        par[y] = x;
        sz[x] += sz[y];
    }

    ll size(ll x){
        return sz[find(x)];
    }
};

void dfs(	vvll& adj, vll& vis, ll s, ll& e,ll& nd		){
    for(auto &i: adj[s]){
        e++;
        if(vis[i] == 0){
            nd++;
            vis[i] = 1;
            dfs(adj,vis,i,e,nd);
        }
    }
}

void BINDAS()
{
    ll n,m;
    cin>>n>>m;
    dsu d(n);
    ll b = m;
				  vvll adj(n);
    
    while(b--){
        ll u,v;
        cin>>u>>v;
        u--,v--;
    				  adj[u].pb(v);
    				  adj[v].pb(u);
    }

    ll x;
    cin>>x;
    unordered_map<int,int> m;   
    c(i,a) cin>>i, i--, m[i]++;

    vpll dc, cc;
				  ll ed,sz;
				  vll vis(n,0);
				  ll mx = 0;
				  ll ans = 0;
    for(auto & i : m){
    				ed = 0; sz = 1;
    				vis[i.first] = 1;
    				dfs(adj, vis, i.first, ed, sz);
    				dc.pb({ed, sz});
    				sz = (sz*(sz-1))/2;
    				ans += sz - ed;
    				mx = max(mx, sz);
    }
				
				  ff(i,0,n){
				  				if(vis[i] || m[i]) continue;
				  				ed = 0; sz =0;
				  				vis[i] = 1;
				  				dfs(adj,vis,i,ed,sz);
				  				cc.pb({ed,sz});
				  				ans += sz*mx;
				  				sz = (sz*(sz-1))/2;
				  				ans += sz- ed;
				  }

				  cout<<ans<<"\n";
}

int main()
{
    fio int tc;
    tc = 1;
    // cin >> tc;
    // generate_primes(1e3);
    // findfac(6e5);
    while (tc--)
    {
        BINDAS();
    }
    return 0;
}