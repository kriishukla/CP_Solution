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
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
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
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

#undef mid

vi arr;

// vi pref1,pref;
vvi g,rg;
vi vis;

lli in_dp[100100][2];//in_dp[i][j][ch]->num of ways in subtree if curr pos is i and colour is j and ch shows whether you have painted it black before or not
lli out_dp[100100];
vvi pref,pref1;
vi par;

void dfs1(lli nn,lli paren){
   par[nn]=paren;
   for(auto a:g[nn]){
    if(a!=paren){
      dfs1(a,nn);
    }
   }
}
map<lli,lli> mp;
void dfs(lli nn,lli par){     
     lli cnt=0;
     pref[nn].assign(g[nn].size()+3,1);
     pref1[nn].assign(g[nn].size()+3,1);
     in_dp[nn][1]=1;
     vi aa;
     for(auto a:g[nn]){
      if(a==par)continue;
        cnt++;
        mp[a]=cnt;
        dfs(a,nn);
        in_dp[nn][1]*=(in_dp[a][1]+in_dp[a][0]);
        in_dp[nn][1]%=m;
        aa.pb((in_dp[a][1]+in_dp[a][0])%m);
        
     }
    //  deb(nn);
    //  pr(aa);
    //  deb(pref[nn].size());
     for(int i=0;i<aa.size();i++){
       pref[nn][i+1]=aa[i];
       pref[nn][i+1]*=pref[nn][i];
       pref[nn][i+1]%=m;
     }
     for(int i=aa.size()-1;i>=0;i--){
       pref1[nn][i+1]=aa[i];
       pref1[nn][i+1]*=pref1[nn][i+2];
       pref1[nn][i+1]%=m;
     }   

}


void dfs2(lli nn,lli paren){
  if(nn==1){
    out_dp[nn]=1;
  }
  else{
    lli xx=pref[par[nn]][mp[nn]-1];
    xx*=pref1[par[nn]][mp[nn]+1];
    xx%=m;
    out_dp[nn]=(1+xx*out_dp[par[nn]])%m;
  }
  for(auto a:g[nn]){
    if(a!=paren){
      dfs2(a,nn);
    }
  }

}


void solve(){
  cin>>n>>m;
  par.assign(n+1,0);
  g.resize(n+1);
  pref.resize(n+1);
  pref1.resize(n+1);
  for(int i=0;i<n-1;i++){
    lli u,v;
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }
 for(int i=0;i<=n;i++){
  out_dp[i]=1;
  in_dp[i][0]=1;
 }

 dfs(1,0);
 dfs1(1,0);
 dfs2(1,0);
//  for(int i=1;i<=n;i++){
//   deb2(i,out_dp[i]);
//  }
//  for(int i=1;i<=n;i++){
//   deb2(i,in_dp[i][1]);
//  }
//  pr(mp);
//  pr(pref[1]);
//  pr(pref1[1]);
//   pr(pref[2]);
//  pr(pref1[2]);
//   pr(pref[3]);
//  pr(pref1[3]);
//   pr(pref[4]);
//  pr(pref1[4]);
 
 for(int i=1;i<=n;i++){
  cout<<(in_dp[i][1]*out_dp[i])%m<<endl;
 }
 

}


int main() {
    IOS
 
  //  fact[0]=1;
  //  for(lli i=1;i<=200200;i++){
  //    fact[i]=(i*fact[i-1])%M;
  //  }
  //  for(lli i=0;i<=200200;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }
  //  deb(nCr(5,2));

   
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();
    
}