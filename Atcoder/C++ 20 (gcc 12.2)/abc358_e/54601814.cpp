#include<bits/stdc++.h>

using namespace std;
#define lli long long int
#define endl '\n'
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
#define ld double
#define S second
#define all(o) o.begin(),o.end()
lli M=998244353;
using mll = map<lli,lli>;
using vi = vector<lli>;
using vvi = vector<vector<lli>>;
using vpii = vector<pii>;
// lli INF=K;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mid (l+r)/2
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T bin_pow(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli fact[200200],inv_fact[200200];
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli n,m,x,k,tt,q,p,l,d,r,y,z,h,c,a;

vector<pair<lli,pii>> arr1;
vi cost,dd,cntk,brr,w,arr,crr,hh;
vvi g;
lli dp[26][1001];
lli ori;
lli rec(lli lvl,lli len){
  if(lvl==26){
    if(len==0)return 0;
      return fact[len];
  }
  if(dp[lvl][len]!=-1){
    return dp[lvl][len];
  }
  lli ans=0;
  for(int i=0;i<=crr[lvl];i++){
    if(len+i>k)break;
    lli x=inv_fact[i]*rec(lvl+1,len+i);
    x%=M;
  // if(lvl<=2){
  //   deb(i);
  //   deb2(inv_fact[i],rec(lvl+1,len-i));
  // }
    ans+=x;
    ans%=M;
  }
//   if(lvl<=2){
//  deb2(lvl,len);
//  deb(ans);
//   }
  return dp[lvl][len]=ans;
}


void solve1(){
 cin>>k;
 mem(dp,-1);
 crr.resize(26);
 for(int i=0;i<26;i++){
  cin>>crr[i];
 }
 lli ans=0;

// deb(rec(0,1));
//  ori=2;
 ans=rec(0,0);
  
 cout<<ans<<endl;

}

int main() {
   IOS

   fact[0]=1;
    for(int i=1;i<=2000;i++){
      fact[i]=(i*fact[i-1])%M;
    }

    inv_fact[2000]=bin_pow<lli>(2000,M-2,M);
    for(int i=1999;i>=0;i--){
      inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
    }
 
    // // cin>>tt; 
    tt=1;
    while(tt--)
     solve1();


}