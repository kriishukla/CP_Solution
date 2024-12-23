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

vi arr,brr;
// vector<vi> g;
vi mark;


vi bridges;
vector<map<lli,lli>> vv;
void IS_BRIDGE(lli v,lli to){
  bridges.pb(vv[v][to]);
} // some function to process the found bridge

vector<vector<lli>> gg; // adjacency list of graph

vector<bool> visited;
vector<lli> tin, low;
lli timer;
vi sz;


void dfs(lli v,lli p) {
    visited[v]=true;
    tin[v]=low[v]=timer++;
    bool parent_skipped=false;
    sz[v]=1;
    for(lli to:gg[v]){
        if(to==p&&!parent_skipped) {
            parent_skipped=true;
            continue;
        }
        if(visited[to]){
            low[v]=min(low[v],tin[to]);
        }else{
            dfs(to,v);
            sz[v]+=sz[to];
            low[v]=min(low[v],low[to]);
            if(low[to]>tin[v])
                IS_BRIDGE(v,to);
        }
    }
}

void find_bridges(){
    timer=0;
    sz.assign(n,0);
    visited.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for(lli i=0;i<n;i++){
        if(!visited[i])
            dfs(i,-1);
    }
}





vector<lli> dis,vis,disn;

void dij(int st,vector<vector<pair<lli,lli>>>& g){
    dis[st]=0;
    priority_queue<pii> pq;
    pq.push((MP(-0,st)));
    while(!pq.empty()){
      auto node=pq.top();
      pq.pop();
      if(vis[node.S])continue;
      vis[node.S]=1;
        for(auto v:g[node.S]){
          lli f=v.F;
          lli wt=v.S;
          if(dis[f]>dis[node.S]+wt){
            dis[f]=dis[node.S]+wt;
            pq.push(MP(-dis[f],f));
          }
        }
    }
}


void solve(){
   cin>>n>>m;
   vector<vpii> g;
   vv.resize(n);
  dis.assign(n,1e17);
   g.clear();
   bridges.clear();
   vector<pair<lli,pii>> edges;
   g.resize(n);
   for(int i=0;i<m;i++){
    lli a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    g[a].pb(MP(b,c));
    g[b].pb(MP(a,c));
    vv[a][b]=i;
    vv[b][a]=i;
    edges.pb(MP(a,MP(b,c)));
   }
  vis.assign(n,0);
   dij(n-1,g);
   vis.assign(n,0);
   disn.assign(n,0);
   for(int i=0;i<n;i++){
    disn[i]=dis[i];
   }
   dis.assign(n,1e17);
   dij(0,g);
  lli min_=1e17;
  
  if(dis[n]==1e17){
    for(int i=0;i<m;i++){
      no;
    }
    return;
  }
  //  pr(dis);
  //  pr(disn);

  for(int i=0;i<m;i++){
    auto [a,d]=edges[i];
    lli b=d.F,c=d.S;
    lli ff=min(dis[a]+disn[b]+c,dis[b]+disn[a]+c);
    min_=min(min_,ff);
  }
  
  gg.resize(n);
  for(int i=0;i<m;i++){
    auto [a,d]=edges[i];
    lli b=d.F,c=d.S;
    lli ff=min(dis[a]+disn[b]+c,dis[b]+disn[a]+c);
    if(ff==min_){
      gg[a].pb(b);
      gg[b].pb(a);
    }
  }
  find_bridges();
  vector<string> ans;
  ans.assign(m,"No");
  for(auto a:bridges){
    ans[a]="Yes";
  }
  // pr(bridges);
  for(auto a:ans){
    cout<<a<<endl;
  }
}




int main(){
 IOS
 
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
//  fact[0]=1;
//  inv_fact[0]=bin_pow<lli>(fact[0],M-2,M);
//  for(int i=1;i<1000100;i++){
//    fact[i]=i*fact[i-1];
//    fact[i]%=M;
//    inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
//  }

// deb(nCr(5,2));

//  cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--)
  solve();
}