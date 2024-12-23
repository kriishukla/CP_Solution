#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 //find_by order()->iterator of indexed element,  order_of_key()-> number of elements strictly less than x
#define lli long long int
typedef tree < lli,  null_type ,  less_equal<lli> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
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
lli fact[1000100],inv_fact[1000100];
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,h,w,l,r,d;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi arr,brr,pref,vala,valb;
vvi g,vis,dis,div1;
vector<pair<lli,pii>> edges;

vector<lli> par,size1;
lli find(lli x){
  if(par[x]==x){
    return x;
  }

  return par[x]=find(par[x]);
}


lli num=0;
lli merge(lli y,lli x){
  
  lli m=find(x),n=find(y);
  if(m==n)return 0;
  if(size1[m]>size1[n]){
    vala[m]+=vala[n];
    valb[m]+=valb[n];
    lli min_=min(vala[m],valb[m]);
    num=min_;
    vala[m]-=min_;
    valb[m]-=min_;
    size1[m]+=size1[n];
    par[n]=m;
  //  max_[m]=max(max_[m],max_[n]);
  }
  else{
    vala[n]+=vala[m];
    valb[n]+=valb[m];
    lli min_=min(vala[n],valb[n]);
    num=min_;
    vala[n]-=min_;
    valb[n]-=min_;
    size1[n]+=size1[m];
    par[m]=n;
    // min_[n]=max(max_[m],max_[n]);
    
  }

  return 1;
}
 

lli solve(lli n1,lli m1){
  cin>>n>>m>>k;
  g.resize(n+1);
  vala.assign(n+1,0);
  valb.assign(n+1,0);
  size1.assign(n+1,1);
  par.resize(n+1);
  for(int i=0;i<=n;i++){
    par[i]=i;
  }

  priority_queue<pair<lli,pii>> pq;

  for(int i=0;i<m;i++){
    lli u,v,wt;
    cin>>u>>v>>wt; 
    pq.push(MP(-wt,MP(u,v)));
  }

  arr.resize(k);
  brr.resize(k);
  for(int i=0;i<k;i++){
    cin>>arr[i];
    vala[arr[i]]++;
  }
  for(int i=0;i<k;i++){
    cin>>brr[i];
    valb[brr[i]]++;
  }

  lli sum=0;
  while(!pq.empty()){
    auto [wt,u_v]=pq.top();
    auto [u,v]=u_v;
    pq.pop();
    wt*=(-1);
    num=0;
    if(merge(u,v)){
      sum+=(num*wt);
    }
  }
 
 cout<<sum<<endl;

 return 1;
}


int main(){
 IOS
 
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  //  fact[0]=1;
  //  for(lli i=1;i<=200200;i++){
  //    fact[i]=(i*fact[i-1])%M;
  //  }
  //  for(lli i=0;i<=200200;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }
//  deb(nCr(5,2));

//  div1.resize(1001000);
//  for(lli i=1;i<1001000;i++){
//   for(lli j=i;j<1001000;j+=i){
//     div1[j].pb(i);
//   }
//  }

//  pr(div1[10]);

 

// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--){
    solve(0,0);
  
  }
  
}