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
vector<lli> arr,cost,dis,brr,h,pp,crr;

  multiset<lli> mt;
lli sz,f;
// #undef mid
map<lli,lli> mp;
lli dp[100100];
vvi g,rg;


vi v,in_deg,vis;
lli kahn(){
    queue<lli> q;
 for(int i=1;i<=n;i++){
    if(in_deg[i]==0){
       q.push(i);
       v.pb(i);
    }
 }
 while(!q.empty()){
    auto nn=q.front();
    q.pop();
    if(vis[nn])continue;
    vis[nn]=1;
    for(auto a:g[nn]){
        in_deg[a]--;
        if(in_deg[a]==0){
            q.push(a);
            v.pb(a);
        }
    }
 }
//  deb(v.size());
//   for(auto a:v){
//     cout<<a<<" ";
//   }
//   cout<<endl;
 if(v.size()==n)return 1;
 return 0;
}

void solve(){
// mem(dp,0);
cin>>n>>m;
arr.resize(n);
brr.resize(n);
g.resize(n+1);
rg.resize(n+1);
in_deg.assign(n+1,0);
vis.assign(n+1,0);
for(int i=0;i<m;i++){
  lli x,y;
  cin>>x>>y;
  rg[y].pb(x);
  g[x].pb(y);
  in_deg[y]++;
}

kahn();

lli max_=0;
for(auto a:v){
  dp[a]=0;
  for(auto b:rg[a]){
    dp[a]=max(dp[a],1+dp[b]);
    
  }
  max_=max(max_,dp[a]);
}

cout<<max_<<endl;
}


int main() {
   IOS
  
   
  
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();


}