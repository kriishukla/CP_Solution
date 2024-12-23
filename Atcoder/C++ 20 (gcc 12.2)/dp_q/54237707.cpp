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
lli dp[200200];
vvi g,rg;


vector<lli> t;
void build(lli ix,lli l,lli r){
  if(l==r){
    t[ix]=arr[l];

  return;
  }
 build(2*ix,l,mid);
 build(2*ix+1,mid+1,r);
 auto a=t[2*ix],b=t[2*ix+1];
t[ix]=max(a,b);
}

void update(lli ix,lli l,lli r,lli pos,lli val){ 
 if(pos<l || pos>r){
   return; 
  }
  
 if(l==r){
      t[ix]=val;
   return;
  }
 update(2*ix,l,mid,pos,val);
 update(2*ix+1,mid+1,r,pos,val);
 lli a=t[2*ix],b=t[2*ix+1];
 t[ix]=max(a,b);
}

lli query(lli ix,lli l,lli r,lli x,lli y){
  if(y<l || r<x){
    return 0;
  }


  if(x<=l && r<=y){
    return t[ix];
  }
   
 lli a=query(2*ix,l,mid,x,y);
 lli b=query(2*ix+1,mid+1,r,x,y);
  lli c=max(a,b);
  
  
 return c;
}




void solve(){
cin>>n;
arr.assign(n,0);
h.assign(n,0);
t.resize(4*n+4,0);

for(int i=0;i<n;i++){
 cin>>h[i];
}

for(int i=0;i<n;i++){
 cin>>arr[i];
}

vi pref;
pref.assign(n+1,0);

lli max_=0;
for(int i=n;i>=0;i--){
  if(i==n){
    dp[i]=0;
    continue;
  }
  
  dp[i]=arr[i]+query(1,0,n,h[i],n);
   update(1,0,n,h[i],dp[i]);  
  max_=max(max_,dp[i]);
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