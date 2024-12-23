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
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d,t0,t1,t2;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}
#undef mid

vector<ld> arr,brr;
vector<vector<ld>> dp;
vvi dp1,test;

ld rec(lli lvl,lli prev){
  if(lvl==n){
    return 0;
  }
  if(test[lvl][prev]!=-1){
    return dp[lvl][prev];
  }
  ld ans=-1e17;
  if(brr[lvl]>=0){
    ans=max(ans,rec(lvl+1,1));
  }
  else{
    if(prev==1){
    ans=max(ans,rec(lvl+1,0));
    }
    ans=max(ans,brr[lvl]+rec(lvl+1,1));
  }
  test[lvl][prev]=0;
  return dp[lvl][prev]=ans;
}



lli check_avg(ld mid){
  brr.resize(n);
  ld sum=0;
  
  for(int i=0;i<n;i++){
    brr[i]=arr[i]-mid;
    if(brr[i]>=0){
      sum+=brr[i];
    }
  }
  test.assign(n,vi(2,-1));
  dp.assign(n,vector<ld>(2,-1));
  // pr(brr);
  // deb(sum);
  sum=sum+rec(0,1);
  // deb(rec(0,1));
  return sum>=0LL;
}



lli rec1(lli lvl,lli prev){
  if(lvl==n){
    return 0;
  }
  if(dp1[lvl][prev]!=-1){
    return dp1[lvl][prev];
  }
  lli ans=brr[lvl]+rec1(lvl+1,1);
  if(prev==1){
    ans=min(ans,rec1(lvl+1,0));
  }
  return dp1[lvl][prev]=ans;
}


lli check_med(lli mid){
   brr.assign(n,1);
   lli cnt=0;
   for(int i=0;i<n;i++){
    if(arr[i]>=mid){
      brr[i]=0;
      cnt++;
    }
   }
   dp1.assign(n,vi(2,-1));
   lli req=cnt-1;
   lli sum=rec1(0,1);
   return req>=sum;
}


lli solve(lli n1,lli m1){
  cin>>n;
  arr.resize(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  ld lo=0,hi=1e9+1,ans=-1;
  for(int i=0;i<=80;i++){
     ld mid=(1.0*(lo+hi)/2.0);
     if(check_avg(mid)){
       ans=mid;
       lo=mid+1;
     }
     else{
      hi=mid-1;
     }
  }

  // check_avg(5);
  cout<<fixed<<setprecision(6)<<ans<<endl;


  lo=0,hi=1e9;
  lli ans1=-1;
  while(lo<=hi){
    lli mid=(lo+hi)/2;
    if(check_med(mid)){
      ans1=mid;
      lo=mid+1;
    }
    else{
      hi=mid-1;
    }
  }

  cout<<ans1<<endl;
 return 1;
}


int main(){
 IOS
 
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
 

  //  for(lli i=0;i<=200200;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }

// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--){
   solve(0,0);
  }
  
}