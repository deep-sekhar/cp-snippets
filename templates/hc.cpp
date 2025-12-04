#pragma comment(linker, "/STACK:1073741824")
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
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
vll pri(1e7 + 101, 1);
vll primes;

// Function to generate all peak numbers directly by iterating over odd lengths

// const int MAX_LEN = 19; // Maximum length (18 digits)
// ll dp[MAX_LEN][2][10]; // DP state: dp[length][isDecreasing][lastDigit]

// void generate_peaks(){
//     // for only odd lengths
//     for(int len = 1; len < MAX_LEN; i++)
// }
// vector<ll> peaks;

void BINDAS(int tc)
{
    int n; cin >> n;
    cout<<"Case #"<<tc<<": ";
    // cout << count << "\n";
}

void main_()
{
    // memset(dp, -1, sizeof(dp));
    // Generate all peaks before processing the test cases
    // generate_peaks();
    // sort(peaks.begin(), peaks.end()); // Sort to allow efficient range querying
    int tc;
    // freopen("input5.txt", "r", stdin);
    freopen("test_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    // pri[0] = 0;
    // pri[1] = 0;
    // for(ll i = 2; i <= 1e7+100; i++)
    // {
    //     if(pri[i])
    //     {
    //         primes.push_back(i);
    //         for(ll j = i * i; j <= 1e7+100; j += i)
    //         {
    //             pri[j] = 0;
    //         }
    //     }
    // }
    for (int i = 1; i <= tc; i++)
    {
        BINDAS(i);
    }
}

static void run_with_stack_size(void (*func)(void), size_t stsize)
{
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%esp\n" : : "r"(send));
    free(stack);
}

int main()
{
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}