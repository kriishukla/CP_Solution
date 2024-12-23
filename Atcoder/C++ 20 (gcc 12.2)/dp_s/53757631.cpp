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
// lli INF=1e17;
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
lli n,w,m,k,pb1,ps,p,b,d;
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
string s,t,str;
vector<vector<bool>> crr,vis;
// vector<lli> v;
map<char,pii> mp;
vector<lli> arr,brr;

lli dp[2][2][100][10010];

lli rec(lli lvl,lli lo,lli hi,lli sum){
  if(lvl==n){
   if(sum%d==0)return 1;
    return 0;
  }
  if(dp[lo][hi][sum][lvl]!=-1){
    return dp[lo][hi][sum][lvl];
  }
  lli l=0,h=9,ans=0;
  if(lo==1)l=arr[lvl];
  if(hi==1)h=brr[lvl];
  // deb(lvl);
  // deb2(l,h);
  // deb2(lo,hi);
  for(lli i=l;i<=h;i++){
    if(i==l){
      // if(lo==1){
        ans+=rec(lvl+1,lo,(l==h?hi:0),(sum+i)%d);
        ans%=M;
     continue;
    }
    // else{
    //   ans+=rec(lvl+1,0,(l==h?hi:0),(10*sum+i)%d);
    //  ans%=M;
    //  continue;
    // } 

    if(i==h){//cout<<"in"<<endl;
       ans+=rec(lvl+1,0,hi,(sum+i)%d);
        ans%=M;
     continue;
    } 
    
    ans+=rec(lvl+1,0,0,(sum+i)%d);
 ans%=M;
  }

// deb2(ans,lvl);


 return dp[lo][hi][sum][lvl]=ans;
}


void solve(){
   string str;
   cin>>str;
   cin>>d;
   n=str.size();
   for(int i=0;i<n;i++){
    brr.pb(str[i]-'0');
    arr.pb(0);
   }
   arr[arr.size()-1]=1;
   cout<<rec(0,1,1,0)<<endl;
 
}



int main() {
   IOS
memset(dp,-1,sizeof(dp));

  fact[0]=1;
  for(int i=1;i<=200100;i++){
    fact[i]=(i*fact[i-1])%M;
  }
  inv_fact[200100]=bin_pow<lli>(fact[200100],M-2,M);
  for(int i=200099;i>=0;i--){
    inv_fact[i]=((i+1)*inv_fact[i+1])%M;
  }
   
 lli t;

    // cin>>t;
    t=1;
    while(t--)
     solve();


}