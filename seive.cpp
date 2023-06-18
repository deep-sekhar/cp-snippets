// generate primes with seives
vector<ll> prime;
vector<ll> isprime;
void generate_primes(ll n)
{
    isprime.assign(n + 1, 1);
    isprime[0] = isprime[1] = 0;
    for(ll i = 2; i <= n; i++)
    {
        if(isprime[i])
        {
            prime.pb(i);
            for(ll j = i*i; j <= n; j += i)
                isprime[j] = 0;
        }
    }
}