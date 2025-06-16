#include<bits/stdc++.h>
#define ar array
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<int,int>>
#define vpl vector<pair<long,long>>
#define vt vector<tuple<ll,ll,ll>>
#define modu 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pp(i,n) for(i = 0; i< n; i++);
#define mm(i,n) for(i = n-1; i >= 0; i--);
#define yes cout<<"yes";
#define no cout<<"no";
#define No cout<<"No";
#define NO cout<<"NO";
#define nl cout<<"\n";
#define ck cout<<" = ";

using namespace std;

void solve(int tc) {
cout<<"Case #"<<tc<<": ";
int n; cin>>n;
vi a(n);
for(int i = 0; i<n; i++)
cin>>a[i];

ll ans = 0;
for(int i = 0; i<n; i++){
    int j = i;
    ll k = 0, pans = 0;
    if(a[i] >= 0){
    while(j<n && k>=0){
        k+=a[j];
        if(k>=0)
        pans += k;
        j++;
    }
    ans+=pans;
    // cout<<ans<<" = ";
    }
}
cout<<ans;
nl
}

int main()
{
fio
int tc;
cin >> tc;
for(int i = 1; i<= tc;i++)
{
solve(i);
}
return 0;
}