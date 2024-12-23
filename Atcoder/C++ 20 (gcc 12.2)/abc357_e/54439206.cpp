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
lli n,m,x,k,tt,q,p,l,d,r,y,z;

vector<pair<lli,pii>> arr1;
vi cost,dd,brr,hh,w,pp,crr,arr;
 

#undef mid

vvi g,grv,con_g,con_grev;
int cur_scc=0;
int scc_num[200200];
vi vis,tout_order;

void dfs1(lli x){
  vis[x]=1;
  for(auto v:g[x]){
    if(!vis[v]){
      dfs1(v);
    }
  }
 tout_order.pb(x);
}

void dfs2(lli x){
  scc_num[x]=cur_scc;
  vis[x]=1;
  for(auto v:grv[x]){
    if(!vis[v]){
      dfs2(v);
    }
  }
}



// vvi g;
vi v,in_deg;
void kahn(){
    queue<lli> q;
 for(int i=1;i<=cur_scc;i++){
    if(in_deg[i]==0){
       q.push(i);
       v.pb(i);
    }
 }
 while(!q.empty()){
    auto nn=q.front();
    q.pop();
    if(vis[nn])continue;
    vis[nn]=1;
    for(auto a:con_grev[nn]){
        in_deg[a]--;
        if(in_deg[a]==0){
            q.push(a);
            v.pb(a);
        }
    }
 }
//  deb(v.size());
//   for(auto a:v){
//     cout<<a<<" ";
//   }
//   cout<<endl;
//  if(v.size()==n)return 1;
//  return 0;
}

void solve1(){
  cin>>n;
  g.resize(n+1);
  grv.resize(n+1);
 for(int i=1;i<=n;i++){
  lli x,y;
  cin>>x;
  g[i].pb(x);
  grv[x].pb(i);
 }
 vis.assign(n+1,0);
 for(int i=1;i<=n;i++){
  if(!vis[i]){
    dfs1(i);
  }
 }
 reverse(all(tout_order));
 vis.assign(n+1,0);

 for(auto x:tout_order){
  if(!vis[x]){
    cur_scc++;
    dfs2(x);
  }
 }
 con_g.resize(cur_scc+1);
 con_grev.resize(cur_scc+1);
//  debarr(scc_num,n+1);
 in_deg.assign(cur_scc+1,0);
 vis.assign(cur_scc+1,0);

 for(int i=1;i<=n;i++){
  for(auto v:g[i]){
    if(scc_num[i]!=scc_num[v]){
      // deb(i);
      con_g[scc_num[i]].pb(scc_num[v]);
      con_grev[scc_num[v]].pb(scc_num[i]);
      in_deg[scc_num[i]]++;
    }
  }
 }
 map<lli,lli> mp;
 
 for(int i=1;i<=n;i++){
   mp[scc_num[i]]++;  
 }


 for(auto a:con_g){
  if(a.size()==0)continue;
  // debarr(a,a.size());
 }

 kahn();
 vi dp;
 dp.assign(n+1,0);
 for(int i=0;i<v.size();i++){
  dp[v[i]]=mp[v[i]];
  for(auto a:con_g[v[i]]){
    if(a!=v[i])
    dp[v[i]]+=dp[a];
  }
 }

lli sum=0;
 for(int i=1;i<=n;i++){
  if(dp[scc_num[i]]==0)dp[scc_num[i]]=mp[scc_num[i]];
  sum+=dp[scc_num[i]];
 }
cout<<sum<<endl;
}

int main() {
   IOS
 
    // cin>>tt; 
    tt=1;
    while(tt--)
     solve1();


}