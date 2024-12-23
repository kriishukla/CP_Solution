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

lli fact[200200],inv_fact[200200];

lli nCr(lli n,lli r){
  if(r>n || n<0 ||r<0)return 0;
  lli d=(inv_fact[r]*inv_fact[n-r])%M;
  lli f=(fact[n]*d)%M;
  return f;
}
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

lli dp[200100];


void solve(){
 lli h,w,n;
 cin>>h>>w>>n;
 vector<pii> arr;
 for(int i=0;i<n;i++){
  lli r,c;
  cin>>r>>c;
  arr.pb(MP(r,c));
 }
 arr.pb(MP(h,w));
//dp[i] total path to reach that point
 sort(all(arr),[&](pii a,pii b){
   return a.F+a.S<b.F+b.S;
 });

 for(int i=0;i<arr.size();i++){
  lli sum=nCr(arr[i].F-1+arr[i].S-1,arr[i].F-1);
  for(int j=0;j<i;j++){
    if(arr[j].F<=arr[i].F && arr[j].S<=arr[i].S){
      sum-=(dp[j]*nCr(arr[i].F-arr[j].F+arr[i].S-arr[j].S,arr[i].S-arr[j].S))%M;
    }
    sum%=M;
  }
  dp[i]=(sum+M)%M;
 }
 cout<<dp[arr.size()-1]<<endl;
}


int main() {
   IOS
memset(dp,0,sizeof(dp));

  // cin>>t;
  fact[0]=1;
  for(int i=1;i<=200100;i++){
    fact[i]=(i*fact[i-1])%M;
  }
  inv_fact[200100]=bin_pow<lli>(fact[200100],M-2,M);
  for(int i=200099;i>=0;i--){
    inv_fact[i]=((i+1)*inv_fact[i+1])%M;
  }
   
   

    t=1;
    while(t--)
     solve();


}