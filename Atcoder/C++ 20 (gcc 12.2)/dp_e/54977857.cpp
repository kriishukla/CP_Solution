#include <bits/stdc++.h>
using namespace std;
#define lli long long 
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
lli INF=1e17;
#define S second
#define endl '\n'
#define all(o) o.begin(),o.end()
lli M=1000000007;
#define pb push_back
#define lb lower_bound
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
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
lli n,m,x,k,tt,p,y,z,h,c,w;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}
using vi = vector<lli>;
lli dy[]={1,0,-1,0};
lli dx[]={0,1,0,-1};

vector<lli> arr,brr,crr,a1,b1,fin;
char d[]={'P','R','S'};


//if level==m and its B work done
map<lli,vector<lli>> mp;
lli dp[101][100100];
vi v;

lli rec(lli lvl,lli val){
  if(lvl==n){
    if(val==0){
      return 0;
    }
    return 1e17;
  }
  if(dp[lvl][val]!=-1){
    return dp[lvl][val];
  }
  lli ans=rec(lvl+1,val);
  if(v[lvl]<=val){
    ans=min(ans,rec(lvl+1,val-v[lvl])+arr[lvl]);
  }
  return dp[lvl][val]=ans;
}


void solve() {
cin>>n>>w;
memset(dp,-1,sizeof(dp));
arr.resize(n);
v.resize(n);
for(int i=0;i<n;i++){
  cin>>arr[i]>>v[i];
}

for(int i=100000;i>=0;i--){
  if(rec(0,i)<=w){
    cout<<i<<endl;
    return;
  }
}

}


int main() {
   IOS

  //  cin>>t;
  lli t;
   t=1;
    while(t--)
     solve();
   
 for(auto a:fin){
  cout<<a<<endl;
 }

}