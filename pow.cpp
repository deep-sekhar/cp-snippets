const ll mod = 1e9 + 7;

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