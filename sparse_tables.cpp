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



// Function to compute GCD
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to build the Sparse Table
void buildSparseTable(vll &dif, vector<vll> &sparseTable) {
    ll n = dif.size();
    ll maxLog = log2(n) + 1;
    sparseTable.assign(n, vll(maxLog));

    // Initialize the first column of the sparse table
    rep(i, 0, n) sparseTable[i][0] = dif[i];

    // Build the sparse table
    for (ll j = 1; (1 << j) <= n; j++) {
        for (ll i = 0; (i + (1 << j) - 1) < n; i++) {
            sparseTable[i][j] = gcd(sparseTable[i][j-1], sparseTable[i + (1 << (j-1))][j-1]);
        }
    }
}

// Function to query the GCD in range [L, R] using the Sparse Table
ll queryGCD(vector<vll> &sparseTable, ll L, ll R) {
    ll j = log2(R - L + 1);
    return gcd(sparseTable[L][j], sparseTable[R - (1 << j) + 1][j]);
}

void BINDAS() {
    ll n, q; cin >> n >> q;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    vll dif(n-1);
    rep(i, 0, n-1) dif[i] = abs(a[i+1] - a[i]);

    ll l, r;
    if (n == 1) {
        while (q--) {
            cin >> l >> r;
            cout << 0 << " ";
        }
		cout << "\n";
        return;
    }

    // Build sparse table
    vector<vll> sparseTable;
    buildSparseTable(dif, sparseTable);

    while (q--) {
        cin >> l >> r;
        if (l == r) {
            cout << 0 << " ";
            continue;
        }
        l--; r--;
        // Answer the query using the sparse table
        cout << queryGCD(sparseTable, l, r-1) << " ";
    }
	cout << "\n";
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