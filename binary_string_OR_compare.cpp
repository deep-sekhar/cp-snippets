
string normalize(const string& v)
{
    int cnt = 0;
    while(cnt < v.size() && v[cnt] == '0') cnt++;
    if(cnt == v.size()) return "0";
    return v.substr(cnt, int(v.size()) - cnt);
}
string operator |(const string& a, const string& b)
{
    int sz = max(a.size(), b.size());
    string ans(sz, '0');
    for(int i = 0; i < a.size(); i++)
        if(a[i] == '1') ans[i + sz - int(a.size())] = '1';
    for(int i = 0; i < b.size(); i++)
        if(b[i] == '1') ans[i + sz - int(b.size())] = '1';    
    return normalize(ans);
}
bool better(const string& a, const string& b)
{
    if(a.size() != b.size()) return a.size() > b.size();
    return a > b;
}
