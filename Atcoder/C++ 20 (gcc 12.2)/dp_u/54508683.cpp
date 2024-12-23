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
lli n,m,x,k,tt,q,p,l,d,r,y,z,h,c;

vector<pair<lli,pii>> arr1;
vi cost,dd,cntk,brr,w,crr,hh;
vvi g,arr;
lli dp[1<<20];

lli rec(lli lvl){
  if(lvl==0)return 0;
  if(dp[lvl]!=-1){
    return dp[lvl];
  }
  lli max_=0;
  for(int sub=lvl;sub>=0;sub=((sub-1)&lvl)){
    if(sub==lvl)continue;
    vi v;
    for(int i=0;i<=15;i++){
      if(((sub>>i)&1LL)==0 && ((lvl>>i)&1LL)==1){
         v.pb(i);   
      }
    }
    lli sum=0;
    for(int i=0;i<v.size();i++){
    for(int j=0;j<v.size();j++){
      sum+=arr[v[i]][v[j]];
    }
    }
    sum/=2;
    max_=max(max_,sum+rec(sub));
    // deb2(max_,lvl);
    if(sub==0){
      break;
    }
  }
  return dp[lvl]=max_;
}

void solve1(){
cin>>n;
mem(dp,0);
arr.assign(n,vector<lli>(n,0));

for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
     cin>>arr[i][j];
  }
}
// for(int sub=7;sub>0;sub=(sub-1)&7){
//   cout<<sub<<endl;
// }
// cout<<rec((1<<n)-1)<<endl;

lli mask[(1LL<<n)];

for(int sub=(1LL<<n)-1;sub>0;sub=(sub-1)&((1LL<<n)-1)){
  vi v;
  for(int i=0;i<=15;i++){
    if((sub>>i)&1LL){
      v.pb(i);
    }
  }
  lli sum=0;
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v.size();j++){
       sum+=arr[v[i]][v[j]];
    }
  }
  sum/=2;
  mask[sub]=sum;
}




for(int lvl=0;lvl<(1LL<<n);lvl++){
  if(lvl==0){
    dp[lvl]=0;
    continue;
  }
  for(int sub=lvl;sub>0;sub=((sub-1)&lvl)){
     vi v;

    // for(int i=0;i<=15;i++){
    //   if(((sub>>i)&1LL)==0 && ((lvl>>i)&1LL)==1){
    //      v.pb(i);   
    //   }
    // }
    // lli sum=0;
    // for(int i=0;i<v.size();i++){
    // for(int j=0;j<v.size();j++){
    //   sum+=arr[v[i]][v[j]];
    // }
    // }
    // sum/=2;
   dp[lvl]=max(dp[lvl],mask[sub]+dp[lvl^sub]);
    // deb2(max_,lvl);
   
  }
}
cout<<dp[(1<<n)-1]<<endl;
}

int main() {
   IOS

  //  for(lli sub=10;sub>0;sub=(sub-1)&10){
  //   cout<<sub<<endl;
  //  }


    // cin>>tt; 
    tt=1;
    while(tt--)
     solve1();


}