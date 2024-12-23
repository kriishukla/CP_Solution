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
vi cost,dd,cntk,brr,w,crr,arr,hh;
vvi g;



vector<lli> t;
void build(lli ix,lli l,lli r){
  if(l==r){
    t[ix]=0;

  return;
  }
 build(2*ix,l,mid);
 build(2*ix+1,mid+1,r);
 auto a=t[2*ix],b=t[2*ix+1];
t[ix]=a+b;
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


#undef mid

void solve1(){
 cin>>n;
 hh.resize(n);
 brr.resize(n);
 for(int i=0;i<n;i++){
  cin>>hh[i];
 }
 
 for(int i=0;i<n;i++){
  cin>>brr[i];
 }

 vi dp;
 dp.resize(n);
 t.assign(4*n+4,0);
lli max_=0;
 for(int i=n-1;i>=0;i--){
  dp[i]=brr[i]+query(1,0,n,hh[i]+1,n);
   max_=max(max_,dp[i]);
   update(1,0,n,hh[i],dp[i]);
 }
cout<<max_<<endl;
}

int main() {
   IOS

    // cin>>tt; 
    tt=1;
    while(tt--)
     solve1();


}