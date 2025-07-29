vector<int> spf(mx+1);
iota(begin(spf), end(spf), 0);
for(long long i = 2; i * i <= mx; ++i) {
    if (spf[i] == i) {
        for (long long j = i * i; j <= mx; j += i) {
            if(spf[j] == j)
            spf[j] = i;
        }
    }

auto isPrime = [&](int num){return num>=2 and spf[num]==num;};