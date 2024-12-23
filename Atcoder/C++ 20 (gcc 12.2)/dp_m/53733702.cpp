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
// lli INF=1e17;
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
lli n,w,m,k,pb1,ps,t,p,b;
#define mid (l+r)/2

vector<vector<lli>> g,indi;
vector<lli> par,size1,distinct,val;
vector<pii> edges;
 



vector<lli> fin;
 lli found=0,r;
lli nb,ns,nc,hb,hc,hs,rb,rs,rc;
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T bin_pow(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}

// #undef mid
  // string str;

// vector<lli> arr;
// vector<lli> primes;
// bool is_prime[10001];



#undef mid
vector<lli> div1;
//  vector<vector<lli>> dp;
set<lli> st;
string s1,s2,str;
vector<vector<bool>> crr,vis;
// vector<lli> v;
map<char,pii> mp;
vector<lli> arr,brr;

lli dp[101][100100];




void solve(){
cin>>n>>k;
arr.resize(n);
for(int i=0;i<n;i++){
  cin>>arr[i];
}
memset(dp,0,sizeof(dp));
//dp[level and choco left]
vector<lli> curr,prev;
curr.assign(k+1,1);
prev.assign(k+1,0);
// deb2(n,k);
for(int i=n;i>=0;i--){
  // deb(i);
  for(int kk=0;kk<=k;kk++){
    if(i==n){
      if(kk==0){
        dp[i][kk]=1;
      }
      else{
        dp[i][kk]=0;
      }
      continue;
    }
    dp[i][kk]=prev[kk];
    dp[i][kk]%=M;
    if(kk-arr[i]-1>=0){
      dp[i][kk]-=prev[kk-arr[i]-1];
      dp[i][kk]=(M+dp[i][kk])%M;
    }
    curr[kk]=dp[i][kk];
    if(kk-1>=0){
      curr[kk]+=curr[kk-1];
      curr[kk]%=M;
    }
  }
  swap(curr,prev);
}

// for(int i=0;i<=n;i++){
//   // deb(i);
//   for(int kk=0;kk<=k;kk++){
//     cout<<dp[i][kk]<<" ";
 
//   }
//   cout<<endl;
// }

cout<<dp[0][k]<<endl;
}


int main() {
   IOS
// memset(dp,-1,sizeof(dp));

  // cin>>t;
    t=1;
    while(t--)
     solve();


}