typedef long long ll;
class FenwickTree {
    public:
    vector<ll> ft;
    FenwickTree(int n) : ft(n+2) {}
    void update(int i, ll x) {
        for(++i; i<ft.size(); i+= i&-i)
            ft[i] += x;
    }
    ll query(int i) {
        ll sum = 0;
        for(++i; i>0; i-= i & -i) {
            sum += ft[i];
        }
        return sum;
    }
    ll querylt(int i) {
        return query(i-1);
    }
};