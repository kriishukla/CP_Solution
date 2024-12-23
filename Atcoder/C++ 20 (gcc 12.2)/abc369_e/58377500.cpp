#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 //find_by order()->iterator of indexed element,  order_of_key()-> number of elements
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
lli M=998244353; 
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
lli nCr(lli n,lli r){if(n==0)return 0;if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,h,c,w,l,r;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi arr,brr,crr;
vi pref;
vector<vpii> g;
vpii edges;
vi len;
lli dp[404][404][2];
lli dis[404][404];
lli dp1[6][404];

lli rec(lli lvl,lli prev){
  if(lvl==k)return dis[prev][n];
  if(dp1[lvl][prev]!=-1){
    return dp1[lvl][prev];
  }
  auto [u,v]=edges[brr[lvl]];
  lli t=len[brr[lvl]];
  lli ans=dis[prev][u]+t+rec(lvl+1,v);
  ans=min(ans,dis[prev][v]+t+rec(lvl+1,u));

 return dp1[lvl][prev]=ans;
}



void solve(){
   cin>>n>>m;
   g.resize(n+1);
   
   for(int i=0;i<404;i++){
    for(int j=0;j<404;j++){
      dp[i][j][0]=1e17;
      dp[i][j][1]=1e17;
      if(i==j){
        dp[i][j][0]=0;
        dp[i][j][1]=0;
      }
    }
   }
   edges.resize(m+1);
   len.resize(m+1);
   for(int i=1;i<=m;i++){
    lli u,v,t;
    cin>>u>>v>>t;
    edges[i]=MP(u,v);
    len[i]=t;
    g[u].pb(MP(v,t));
    g[v].pb(MP(u,t));
    dp[u][v][0]=min(dp[u][v][0],t);
    dp[v][u][0]=dp[u][v][0];
   }
   
   for(int kk=1;kk<=n;kk++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dp[i][j][kk&1LL]=min(dp[i][j][(kk+1)&1LL],dp[i][kk][(kk+1)&1LL]+dp[kk][j][(kk+1)&1LL]);
        dis[i][j]=dp[i][j][kk&1LL];
      }
    }
   }

   cin>>q;
   for(int i=0;i<q;i++){
    cin>>k;
    brr.resize(k);
    for(int j=0;j<k;j++){
      cin>>brr[j];
    }
    lli ans=1e17;
    do{
     for(int kk=0;kk<6;kk++){
        dp1[kk][1]=-1;
        for(auto a:brr){
          auto [u,v]=edges[a];
          dp1[kk][u]=-1;
          dp1[kk][v]=-1;
        }
        dp1[kk][n]=-1;
      }
      //  pr(brr);
    ans=min(ans,rec(0,1));
    }while(next_permutation(all(brr)));
    cout<<ans<<endl;
   }
}
 
 
 
int main() {
    IOS
  // std::ofstream ofs("input.txt", std::ios::trunc); // Opening file in trunc mode
 
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
    // ordered_set st;
    // st.insert(1);
    // st.insert(1);
    // cout<<st.order_of_key(1+1)<<endl;
    //  cin>>tt;
    tt=1;
     lli cnt=1;
    while(tt--){
    //  cout<<"Case #"<<cnt<<": ";
     solve();
     cnt++;
    }
    
 
}