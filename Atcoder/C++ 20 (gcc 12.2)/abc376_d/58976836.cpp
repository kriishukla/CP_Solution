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
lli nCr(lli n,lli r){if(n==0)return 0;if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d,t0,t1,t2;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}
#undef mid


vpii arr,pref;
vi brr;


vector<vector<pair<lli,lli>>> g;
vector<lli> dis,vis;

lli min_=1e17;

void dij(int st){
    dis[st]=0;
    priority_queue<pii> pq;
    pq.push((MP(-0,st)));
    while(!pq.empty()){
      auto node=pq.top();
      pq.pop();
      if(vis[node.S])continue;
      vis[node.S]=1;
      // deb(node.S);
        for(auto v:g[node.S]){
          lli f=v.F;
          // cout<<f<<" ";
          lli wt=v.S;
          if(dis[f]>dis[node.S]+wt){
            dis[f]=dis[node.S]+wt;
            pq.push(MP(-dis[f],f));
          }
          if(f==1){//cout<<"yy"<<endl;
          // deb(dis[node.S]+1);
            min_=min(min_,dis[node.S]+1);
          }
        }
        // cout<<endl;
    }
}





void solve(){
   cin>>n>>m;
   g.resize(n+1);
   vis.assign(n+1,0);
   dis.assign(n+1,1e17);
   for(int i=0;i<m;i++){
    lli u,v;
    cin>>u>>v;
    g[u].pb(MP(v,1));
   }
  dij(1);
  if(min_==1e17){
    cout<<-1<<endl;
  }
  else{
    cout<<min_<<endl;
  }
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


// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--){
  // cout<<"Case #"<<cnt<<": ";  
  solve();
  // cnt++;
  }
}