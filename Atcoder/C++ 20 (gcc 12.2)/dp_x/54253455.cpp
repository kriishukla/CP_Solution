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
vector<lli> s,arr,cost,dd,val,dis,brr,hh,w,pp,crr,dep;

  multiset<lli> mt;
lli sz,f;
// #undef mid
map<lli,lli> mp;
lli dp[1001][10010];
vvi g,rg;





void solve(){
 cin>>n;
 s.resize(n);
 w.resize(n);
 val.resize(n);
vector<pair<lli,pii>> v;

 for(int i=0;i<n;i++){
  cin>>w[i]>>s[i]>>val[i];
 v.pb(MP(s[i],MP(w[i],val[i])));
 }
 
 sort(all(v),[](pair<lli,pii> a,pair<lli,pii> b){
   return a.F+a.S.F>b.F+b.S.F;
 });
  for(int i=0;i<n;i++){
  w[i]=v[i].S.F;
  s[i]=v[i].F;
  val[i]=v[i].S.S;
 
 }
 
//  for(auto a:s){
//   cout<<a<<" ";
//  }
//  cout<<endl;
 
 lli pref[10010]={0},curr[10010]={0};
lli max_=0;
 for(int i=n-1;i>=0;i--){
   for(int si=0;si<=s[i];si++){
    // cout<<"fdp"<<" ";
   
  dp[i][si]=0;
  if(pref[si]!=0 || (si==0)){
     dp[i][si]=val[i]+pref[si];
  }
     if(w[i]+si<=10000){
      curr[w[i]+si]=max(curr[w[i]+si],dp[i][si]);
     }
     max_=max(dp[i][si],max_);
    //  cout<<"i:"<<i<<" si:"<<si<<" :"<<dp[i][si]<<endl;
   }
    
    // cout<<"curr:"<<endl;
  //  for(int i=0;i<=6;i++){
  //   cout<<curr[i]<<" ";
  //  }
  //  cout<<endl;


   for(int i=0;i<10010;i++){
    curr[i]=max(curr[i],pref[i]);
   }
   
   swap(curr,pref);
   for(int i=0;i<10010;i++){
    curr[i]=0;
   }
  //  cout<<endl;
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