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


void solve(){ 
  lli h,w,k;
  cin>>h>>w>>k;
  lli stx,sty;
  cin>>stx>>sty;
  stx--;
  sty--;
  vvi arr;
  arr.resize(h,vi(w,0));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cin>>arr[i][j];
    }
  }
 
  for(int kk=0;kk<=min(k,h*w);kk++){
      for(int i=0;i<h;i++){
         for(int j=0;j<w;j++){
           if(kk==0){
            if(i==stx && j==sty)dp[i][j][kk]=0;
            else{
                dp[i][j][kk]=-1e17;
            }
             continue;
           }
           dp[i][j][kk]=-1e17;
          dp[i][j][kk]=max(dp[i][j][kk],arr[i][j]+dp[i][j][kk-1]);
          for(int dir=0;dir<4;dir++){
            lli r=i+dx[dir];
            lli c=j+dy[dir];
            if(r>=0 && r<h && c>=0 && c<w){
                dp[i][j][kk]=max(dp[i][j][kk],arr[i][j]+dp[r][c][kk-1]);
            }
          }
        }
      }
  }

//   for(int kk=0;kk<=min(k,h*w);kk++){
//       cout<<"kk:"<<kk<<endl;
//       for(int i=0;i<h;i++){
//          for(int j=0;j<w;j++){
//          cout<<dp[i][j][kk]<<" ";
//          }
//          cout<<endl;
//       }
//   }
lli max_=0;
 if(k>h*w){
      for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      dp[i][j][h*w]+=(k-h*w)*arr[i][j];
      max_=max(max_,dp[i][j][h*w]);
      }
   }
 }
else{
   for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        max_=max(max_,dp[i][j][min(k,h*w)]);   
      }
   }
}
cout<<max_<<endl;
}


int main() {
    IOS
  
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();
    
}