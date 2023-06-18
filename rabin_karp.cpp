
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

void rabinKarpAlgo(string & pattern, string & text) {
    ll m = pattern.size();
    ll n = text.size();
    ll mod = 1e9 + 7;
//   d is total pattern size 
    ll d = m + n;
    // hash of pattern 
    ll hash_p = 0;
    for(ll i  = 0; i < m; i ++)
    hash_p = ( hash_p*d + pattern[i] ) % mod;
    // we use h val to subtract last element 
    ll h = 1;
    for(ll i =0; i< m-1; i++)
    h = (h*d) % mod;
    // hash of 1st window
    ll hash_w = 0;
    for(ll i = 0; i < m; i ++)
    hash_w = (hash_w*d + text[i]) % mod;
    // start matching 
    for(ll i= 0;i <= n-m;i ++)
    {
        if(hash_p == hash_w)
        {
            bool flag = true;
            for(ll j = 0; j < m; j ++)
            {
                if(pattern[j] != text[i+j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            cout<<"pattern found at "<<i<<"\n";
        }
        // next window hash if possible 
        if(i+1 <= n-m){
            hash_w = ( (hash_w - text[i]*h) * d + text[i+m]) % mod;
            // if negetive 
            if(hash_w < 0)
            hash_w += mod;
        }
    }
}

int main() {
  string text = "GEEKS FOR GEEKS";
  string pattern = "GEEK";
  rabinKarpAlgo(pattern, text);
}
