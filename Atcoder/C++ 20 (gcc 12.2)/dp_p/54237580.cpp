#include<bits/stdc++.h>

using namespace std;
#define lli long long int
#define endl '\n'
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
#define ld long double
#define S second
#define all(o) o.begin(),o.end()
lli M=1e9+7;
using mll = map<lli,lli>;
using vi = vector<lli>;
using vvi = vector<vector<lli>>;
using vpii = vector<pii>;
// lli INF=K;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mid (l+r)/2
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T bin_pow(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
lli fact[200200],inv_fact[200200];
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
ld n,m,x,k,tt,q,p,l,d,r;

vector<pair<lli,pii>> arr1;
vector<lli> arr,cost,dis,brr,h,pp,crr,par,dep;

  multiset<lli> mt;
lli sz,f;
// #undef mid
map<lli,lli> mp;
lli dp[100100][2];
vvi g,rg;

void dfs(lli nn,lli paren,lli depth){
  par[nn]=paren;
  dep[nn]=depth;
  for(auto a:g[nn]){
    if(a!=paren){
      dfs(a,nn,depth+1);
    }
  }
}


void solve(){
// mem(dp,0);
cin>>n;
arr.resize(n);
brr.resize(n);
g.resize(n+1);
par.assign(n+1,0);
dep.assign(n+1,0);
rg.resize(n+1);

for(int i=0;i<n-1;i++){
  lli x,y;
  cin>>x>>y;
  g[x].pb(y);
  g[y].pb(x);
}
if(n==1){
  cout<<2<<endl;
  return;
}
dfs(1,0,0);
vvi v;
v.resize(n+1);
lli max_=0;
for(int i=1;i<=n;i++){
  v[dep[i]].pb(i);
  max_=max(max_,dep[i]);
}

// for(int i=1;i<=n;i++){
//   cout<<dep[i]<<" ";
// }
// cout<<endl;
// for(auto a:v){
//   if(a.size()==0)continue;
//   for(auto b:a){
//     cout<<b<<" ";
//   }
//   cout<<endl;
// }

// cout<<max_<<endl;

for(int i=n;i>=0;i--){
 for(int j=0;j<=1;j++){
   if(v[i].size()==0){
     continue;
   }
   for(auto a:v[i]){
    dp[a][j]=0;
    if(g[a].size()==1 && g[a][0]==par[a]){
      // deb(a);
      if(j==1){
        dp[a][j]=1;
      }
      else{
        dp[a][j]=2;
      }
      continue;
    }

    vector<lli> arr;
    for(auto b:g[a]){
      if(b==par[a])continue;
      lli tmp=j;
      if(j==1)tmp=1-j;
      lli c=dp[b][tmp];
      c%=M;
      arr.pb(c);
    }
    lli prod=1;

    for(auto mm:arr){
      prod*=mm;
      prod%=M;
    }
    vector<lli> brr;
    if(j==0){
      for(auto b:g[a]){
      if(b==par[a])continue;
      lli c=dp[b][1-j];
      c%=M;
      brr.pb(c);
    }
    lli prod1=1;
      for(auto mm:brr){
        // cout<<mm<<" ";
      prod1*=mm;
      prod1%=M;
    }
    // cout<<endl;
    prod+=prod1;
    prod%=M;
    }

    dp[a][j]=prod;

    // deb(j);
    // deb2(a,dp[a][j]);
   }
 }

}

// deb2(dp[3][0],dp[3][1]);

// lli ans=0;
// for(auto a:g[1]){
//   ans+=dp[a][1];
//   ans+=dp[a][0];
//   ans%=M;
// }

cout<<dp[1][0]<<endl;
}


int main() {
   IOS
  
   
  
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();


}