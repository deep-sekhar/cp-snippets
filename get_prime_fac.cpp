
// get prime factors
vector<ll> p_factors(ll x)
{
    vll p;
    for (ll i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            p.pb(i);
        while (x % i == 0)
            x /= i;
        if (x == 1)
            break;
    }
    if(x != 1)
        p.pb(x);
    return p;
}
