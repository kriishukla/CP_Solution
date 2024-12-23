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
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d,t0,t1,t2;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}
#undef mid
ld s,t;
vector<pair<pii,pii>> arr,brr;

ld dp[2][7][(1LL<<7)];
lli test[2][7][(1LL<<7)];

ld rec(lli way,lli prev,lli mask){
  if(mask==((1LL<<n)-1)){

    // cout<<'y'<<endl;
    return 0;
  }
  if(prev!=-1 && test[way][prev][mask]==tt){
    return dp[way][prev][mask];
  }
  ld ans=1e17;
  // deb(mask);
  for(int i=0;i<n;i++){
    if(((mask>>i)&1LL)==0){
      // deb2(prev,i);

      lli nmask=(mask^(1LL<<i));
      auto [a_b,c_d]=arr[i];
      auto [a,b]=a_b;
      auto [c,d]=c_d;
      ld len,dis_cd,dis_ab;
      if(prev==-1){
        len=sqrt((a-c)*(a-c)+(b-d)*(b-d));
        dis_cd=sqrt(c*c+d*d);
        dis_ab=sqrt(a*a+b*b);
      }
      else{
        auto [p_a,p_b]=arr[prev].F;
        if(way==1){
          p_a=arr[prev].S.F;
          p_b=arr[prev].S.S;
        }
            // deb2(p_a,p_b);
        len=sqrt((a-c)*(a-c)+(b-d)*(b-d));
        dis_cd=sqrt((c-p_a)*(c-p_a)+(d-p_b)*(d-p_b));
        dis_ab=sqrt((a-p_a)*(a-p_a)+(b-p_b)*(b-p_b));
      }
      // deb2(prev,mask);
      // deb2(way,nmask);
      // deb(i);
  

      // deb2(dis_cd,dis_ab);
      // deb2(s,t);
      // deb(len);
      // deb(dis_cd/s+len/t);
      // deb2(rec(1,i,nmask),rec(0,i,nmask));
       ans=min({ans,dis_ab/s+len/t+rec(1,i,nmask),dis_cd/s+len/t+rec(0,i,nmask)});
      // deb(ans);
    }
  }
// deb2(s,t);
// deb2(prev,way);
// deb2(mask,ans);
  if(prev==-1)return ans;
  test[way][prev][mask]=tt;
  return dp[way][prev][mask]=ans;
}

void solve(){
  cin>>n;
  cin>>s>>t;
  // cout<<(1LL<<n)-1<<endl;
  for(int i=0;i<n;i++){
    lli a,b,c,d;
    cin>>a>>b>>c>>d;
    arr.pb(MP(MP(a,b),MP(c,d)));
  }
//  for(int ways=0;ways<=1;ways++){
//   for(int prev=-1;prev<=1;prev++){
//     for(int mask=0;mask<4;mask++){
//       deb2(prev,mask);
//       deb2(ways,rec(ways,prev,mask));
//     }
//   }
//  }
for(int i=0;i<2;i++){
  for(int j=0;j<7;j++){
    for(int kk=0;kk<(1LL<<7);kk++){
      dp[i][j][kk]=-1;
    }
  }
}
cout<<fixed<<setprecision(10)<<rec(0,-1,0)<<endl;
}


int main(){
 IOS
 
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

mem(test,-1);
// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--)
  solve();
}