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
vector<ld> arr,cost,dis,brr,h,pp,crr;

  multiset<lli> mt;
lli sz,f;
// #undef mid
map<lli,lli> mp;



 ld dp[303][303][303];



void solve(){
// mem(dp,0);
cin>>n;
arr.resize(n);
brr.resize(n);

lli cnt1=0,cnt2=0,cnt3=0;
for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==1)cnt1++;
    if(arr[i]==2)cnt2++;
    if(arr[i]==3)cnt3++;
}

for(int th=0;th<=300;th++){
  for(int tw=0;tw<=300;tw++){
    for(int on=0;on<=300;on++){
      if(on==0 && tw==0 && th==0){
        dp[on][tw][th]=0;
        continue;
      }
      ld ze=n-on-tw-th;
    ld a=((on>0?on*(dp[on-1][tw][th]):0));
    ld b=((tw>0?tw*(dp[on+1][tw-1][th]):0));
    ld c=((th>0?th*(dp[on][tw+1][th-1]):0));
    dp[on][tw][th]=1+a/n+b/n+c/n; 
    dp[on][tw][th]/=(1-ze/n);
    }
  }
}


cout<<fixed<<setprecision(12)<<dp[cnt1][cnt2][cnt3]<<endl;

}


int main() {
   IOS
  
   
  
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();


}