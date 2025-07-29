// STL - tuple snippets
using T = tuple<int, int, int, int>;
vector<T> segments(n);

// input
for(int i = 0; i < n; ++i) {
    int l, r, p, q;
    cin >> l >> r >> p >> q;
    segments[i] = make_tuple(l, r, p, q); // store as tuple
}

// accessing elements of tuple
for(const auto& seg : segments) {
    int l = get<0>(seg);
    int r = get<1>(seg);
    int p = get<2>(seg);
    int q = get<3>(seg);
    // alternative 
    auto [l, r, p, q] = seg; // C++17 structured binding
    // using tie - to unpack
    int l, r, p, q;
    tie(l, r, p, q) = seg; // unpack tuple
}