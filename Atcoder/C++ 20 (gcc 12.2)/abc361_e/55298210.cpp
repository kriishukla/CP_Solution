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
lli fact[200200],inv_fact[200200];
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,z,h,c,w;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi cost,dd,cntk,brr,crr,hh;

#undef mid
vi prime,primes;
vector<vpii> g;
vi arr,dis;


 lli dp[55][55][2505];
lli dx[]={0,0,1,-1};
lli dy[]={1,-1,0,0};

pii in_dp[200200];
lli out_dp[200200];

void dfs(lli node,lli par){
    in_dp[node]=MP(0,-1);
    vi aa;
   for(auto [b,wt]:g[node]){
      if(b==par)continue;
        dfs(b,node);
        aa.pb(wt+in_dp[b].F);
   }
   sort(all(aa),[](lli a,lli b){
    return a>b;
   });

   if(aa.size()==0)return;
   if(aa.size()==1){
     in_dp[node]=MP(aa[0],-1);
   }
   else{
    in_dp[node]=MP(aa[0],aa[1]);
   }
}


void dfs1(lli node,lli par,lli wt){
    if(node==1){
        out_dp[node]=0;
    }
    else{
      out_dp[node]=wt+out_dp[par];
      if(in_dp[par].S!=-1){
        if(in_dp[par].F==in_dp[node].F+wt){
            out_dp[node]=max(out_dp[node],wt+in_dp[par].S);
        }
        else{
             out_dp[node]=max(out_dp[node],wt+in_dp[par].F);
        }
      }
    }
    for(auto [b,wt]:g[node]){
        if(b==par)continue;
        dfs1(b,node,wt);
    }
}


void solve(){
  cin>>n;
  g.resize(n+1);
  lli sum=0;
  for(int i=0;i<n-1;i++){
    lli a,b,c;
    cin>>a>>b>>c;
    sum+=(2*c);
    g[a].pb(MP(b,c));
    g[b].pb(MP(a,c));
  }

  dfs(1,0);
  dfs1(1,0,0);

  lli max_=0;
  for(int i=1;i<=n;i++){
   max_=max(max_,in_dp[i].F+out_dp[i]);
  } 

 cout<<sum-max_<<endl;

}



int main() {
    IOS
  
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();
    
}