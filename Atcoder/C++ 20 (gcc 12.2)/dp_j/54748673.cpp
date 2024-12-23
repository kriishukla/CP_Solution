#include<bits/stdc++.h>
 
using namespace std;
#define lli long long int

#define endl '\n'
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
#define ld double
#define S second
#define all(o) o.begin(),o.end()
lli M=1e9+7;
using mll = map<lli,lli>;
using vi = vector<lli>;
using vvi = vector<vector<lli>>;
using vpii = vector<pii>;
// lli INF=K;
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
lli n,m,x,k,tt,q,p,l,d,r,y,z,h,c;
 lli lcm(lli a,lli b){
  return (a*b/__gcd(a,b));
 }

vi cost,dd,cntk,brr,w,arr,crr,hh;

// #undef mid
 vi prime,primes;
 vector<map<lli,lli>> g;
 vi vis,par;


vi a;
map<lli,vi> mp;

double dp[303][303][303];


void solve(){
   cin>>n;
  arr.resize(n);
  lli cnt1=0,cnt2=0,cnt3=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==1)cnt1++;
    if(arr[i]==2)cnt2++;
    if(arr[i]==3)cnt3++;
  }
//  deb(n);.

 for(int k=0;k<=300;k++){
  // deb(k);
   for(int j=0;j<=300;j++){
    for(int i=0;i<=300;i++){
      if(i+j+k==0){
        dp[i][j][k]=0;
        continue;
      }
    
      dp[i][j][k]=(1.0*n)/(i+j+k);
    if(i>=1) dp[i][j][k]+=1.0*i*dp[i-1][j][k]/(1.0*(i+j+k));
    if(j>=1)  dp[i][j][k]+=1.0*j*dp[i+1][j-1][k]/(1.0*(i+j+k));
    if(k>=1)  dp[i][j][k]+=1.0*k*dp[i][j+1][k-1]/(1.0*(i+j+k));
    }
   }

 }

 cout<<fixed<<setprecision(15)<<dp[cnt1][cnt2][cnt3]<<endl;
}
 
int main() {
   IOS
 
    // cin>>tt; 
    tt=1;
    while(tt--)
     solve();
}