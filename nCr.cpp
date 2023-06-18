
const ll mod = 1e9 + 7;
const ll MAXN = 1e5;
ll fact[MAXN];
ll p(ll b, ll pow){
    ll res = 1;
    b = b % mod;
    while (pow)
    {
        if (pow & 1) res = (res * b) % mod;
        pow = pow >> 1;
        b = (b * b) % mod;
    }
    return res;
}
void help()
{
   fact[0]=1;
   for(int i=1;i<=100000;i++)
   {
      fact[i]=(fact[i-1]*i)%mod;
   }
}
ll modInverse(ll n)
{
    return p(n, mod - 2);
}
ll nCr(ll n, ll r)
{
     return (fact[n]*modInverse(fact[r])%mod * modInverse(fact[n-r])%mod ) %mod;
}
