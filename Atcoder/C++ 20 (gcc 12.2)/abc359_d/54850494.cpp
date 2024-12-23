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
lli M=998244353;
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
#define lb lower_bound
#define ub upper_bound
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
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,l,d,r,y,z,h,c,w;
 lli lcm(lli a,lli b){
  return (a*b/__gcd(a,b));
 }

vi cost,dd,cntk,brr,crr,hh,arr;

#undef mid
 vi prime,primes;
 vector<map<lli,lli>> g;
 vi vis,par;
lli dp[1001][1LL<<12];
string str;

lli check(vi & num){
  if(num.size()==1)return 1;
  for(int i=0;i<num.size();i++){
    if(num[i]!=num[num.size()-1-i]){
      return 0;
    }
  }
  return 1;
}

lli rec(lli lvl,lli mask){
  if(lvl>=k){
     vi num;
      for(int i=0;i<k;i++){
        lli d=(mask>>i)&1LL;
        num.pb(d);
      }
      // deb(lvl);
      // debarr(num,num.size());
      if(check(num)){//cout<<"yy"<<endl;
        return 0; 
      }
      // cout<<"nn"<<endl;
  }
  if(lvl==n){
    return 1;
  }
  if(dp[lvl][mask]!=-1){
    return dp[lvl][mask];
  }
  lli ans=0;
  if(str[lvl]=='?'){
    if(lvl>=k-1){
      vi num;
      for(int i=k-2;i>=0;i--){
        lli d=(mask>>i)&1LL;
        num.pb(d);
      }
     num.pb(0);lli f1=0;
    //  debarr(num,num.size());
     if(!check(num)){
        lli nn=(mask<<1)&((1LL<<(k+1))-1);
          ans+=rec(lvl+1,nn);
          ans%=M;
      }
     
     
      num.pop_back();
      num.pb(1);
      // cout<<"O"<<endl;
      // debarr(num,num.size());

       if(!check(num)){
        lli nn=((mask<<1)|1)&((1LL<<(k+1))-1);
          ans+=rec(lvl+1,nn);
          ans%=M;
      }
     
    }
  else{
     lli nn=((mask<<1)|1)&((1LL<<(k+1))-1);
          ans+=rec(lvl+1,nn);
          ans%=M;
          nn=(mask<<1)&((1LL<<(k+1))-1);
          ans+=rec(lvl+1,nn);
          ans%=M;
  }
}
else{
  if(str[lvl]=='A'){
      lli nn=(mask<<1)&((1LL<<(k+1))-1);
          ans+=rec(lvl+1,nn);
          ans%=M;
  }
  else{
      lli nn=((mask<<1)|1)&((1LL<<(k+1))-1);
          ans+=rec(lvl+1,nn);
          ans%=M;
  }
}

// deb2(lvl,mask);
// deb(ans);

return dp[lvl][mask]=ans;

}



void solve(){
  cin>>n>>k;
  mem(dp,-1);
 cin>>str;
//  vi num;
//  num.resize(5);
//  for(int i=0;i<5;i++){
//   cin>>num[i];
//  }
//  cout<<check(num)<<endl;
 cout<<rec(0,0)<<endl;
}
 
int main() {
   IOS
    
    // fact[0]=1;
    // for(int i=1;i<200200;i++){
    //   fact[i]=(i*fact[i-1])%M;
    // }
    //  for(int i=0;i<200200;i++){
    //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
    // }
 
    // cin>>tt; 
    tt=1;
    while(tt--)
     solve();
}