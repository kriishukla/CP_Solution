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
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d,t0,t1,t2,i;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi arr,brr,pref;
vpii primes;
vi vis;
vvi g;

vi in_dp,out_dp;
vi par;

void dfs(lli nn,lli paren){
  par[nn]=paren;
  
  for(auto a:g[nn]){
    if(a!=paren){
      if(arr[a]==2){
        in_dp[nn]++;
      }
      dfs(a,nn);
      if(arr[a]==3){
        in_dp[nn]+=in_dp[a];
      }
    }
  }
  if(arr[nn]>=4 || arr[nn]<=1)in_dp[nn]=0;
}

void dfs1(lli nn){
  if(nn!=1){
    if(arr[par[nn]]==2)out_dp[nn]=1;
    else if(arr[par[nn]]==3){
     lli n1=in_dp[nn];
     if(arr[nn]==2){
      n1=1;
     } 
     out_dp[nn]=in_dp[par[nn]]-n1+out_dp[par[nn]];
    }
  }
  for(auto a:g[nn]){
    if(a!=par[nn]){
      dfs1(a);
    }
  }
}


lli solve(lli n1,lli m1){
  cin>>n;
  g.resize(n+1);
  arr.assign(n+1,0);
  in_dp.assign(n+1,0);
  out_dp.assign(n+1,0);
  par.assign(n+1,0);

  for(int i=0;i<n-1;i++){
    lli u,v;
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }
  
  for(int i=1;i<=n;i++){
    arr[i]=g[i].size();
  }
  
  dfs(1,0);
  dfs1(1);
  
  lli cnt=0;
  for(int i=1;i<=n;i++){
    for(auto a:g[i]){
      if(arr[i]==2 && arr[a]==2){
        cnt++;
      }
    }
  }
  // deb(cnt);
  lli sum=0;
  // pr(in_dp);
  // pr(out_dp);
  for(int i=1;i<=n;i++){
    if(arr[i]==2){
      // deb(i);
      sum+=(in_dp[i]+out_dp[i]);
    }
  }
  assert(sum%2==0);
  sum-=cnt;
  // deb(sum);
  sum/=2;
  cout<<sum<<endl;
 return 1;

}


int main(){
 IOS

  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
//  fact[0]=1;
//  inv_fact[0]=bin_pow<lli>(fact[0],M-2,M);
//  for(int i=1;i<1000100;i++){
//    fact[i]=i*fact[i-1];
//    fact[i]%=M;
//    inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
//  }
//  deb(nCr(5,2));

// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--){
    // deb(tt);
  solve(0,0);
  
  }
  
}