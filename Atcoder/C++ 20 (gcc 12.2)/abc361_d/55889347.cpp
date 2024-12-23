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
lli n,m,x,k,tt,q,p,y,z,h,c,w;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}
#undef mid
vi prime,primes;

vvi arr,brr,pref1,pref;
vvi rg;
vvi g;

vector<lli> par,size1;
string str,str1;
vector<map<string,lli>> dis,vis,gone;


void dij(string &x,lli n){
    queue<pair<lli,string>> q;
    q.push(MP(n,x));
    while(!q.empty()){
      auto node=q.front();
      q.pop();
      lli nn=node.F;
      string xx=node.S;
      // deb2(xx,nn);
      if(vis[node.F][node.S])continue;
      vis[node.F][node.S]=1;
      for(int i=0;i+1<xx.size();i++){
       if(xx[i]=='.'|| xx[i+1]=='.')continue;
       string s=xx;
       swap(s[i],s[nn]);
       swap(s[i+1],s[nn+1]);
       if(gone[i][s]==1){
        if(dis[i][s]>dis[nn][xx]+1){
          dis[i][s]=dis[nn][xx]+1;
          q.push(MP(i,s));
        }
        continue;
       }
       else{
        gone[i][s]=1;
         dis[i][s]=dis[nn][xx]+1;
         q.push(MP(i,s));
       }
        
      }
    }
}





void solve(){
   cin>>n;
   cin>>str>>str1;
   lli cnt=0;
   dis.resize(15);
   gone.resize(15);
   vis.resize(15);
  str.pb('.');
  str.pb('.');
  str1.pb('.');
  str1.pb('.');
   if(str==str1){
    cout<<0<<endl;
    return;
   }
  dij(str,n);
    // pr(dis[n]);
  lli x=dis[n][str1];

  if(x!=0){
    cout<<x<<endl;
  }
  else{
    cout<<-1<<endl;
  }
}


int main() {
    IOS
  //  fact[0]=1;
  //  for(int i=;i<=1000000;i++){
  //    fact[i]=(i*fact[i-])%M;
  //  }
  //  for(int i=0;i<=1000000;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }
  //  deb(nCr(5,2));

  // ordered_set mt;
  // mt.insert(1);
  // mt.insert(1);
  // mt.insert(1);
  // cout<<mt.order_of_key(1)<<endl;

    // cin>>tt;
    tt=1;
    while(tt--)
     solve();
    
}