const ll mod = 1e9 + 7;
const ll MAXN = 1e5;

ll fact[MAXN];

void help()
{
   fact[0]=1;
   for(int i=1;i<=100000;i++)
   {
      fact[i]=(fact[i-1]*i)%mod;
   }
}
