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
vpii brr;
vi arr,pref;
#undef mid



lli check(lli mid,lli pos){
  lli num=arr[pos]+mid;
  lli left=k-mid;
  auto it=ub(all(arr),num);
  lli numbers=arr.end()-it;
  
  // deb2(num,left);
  
  if(numbers>=m)return 0;
  auto pos1=it-arr.begin();
  
  // deb2(numbers,pos1);

  lli sum=pref[pos1-1];
  // deb(sum);
  lli num2=pref[n-m-1],l=n-m;
  if(pos>=n-m){
    num2=pref[n-m-2]+arr[pos];
  }
  sum-=num2;

  lli r=pos1-1;

// deb2(num2,n-m);
// deb2(r,l);

  lli req=(arr[pos]+mid+1)*(r-l+1)-sum;
  // deb2(req,sum);
  if(req>left)return 1;
  return 0;
}

void solve(){
 cin>>n>>m>>k;

 arr.resize(n);
 brr.resize(n);
 pref.resize(n);
 lli sum=0;
 for(int i=0;i<n;i++){
  cin>>brr[i].F;
  brr[i].S=i;
  sum+=brr[i].F;
 }
 sort(all(brr));
 for(int i=0;i<n;i++){
  pref[i]=brr[i].F;
  arr[i]=brr[i].F;
  if(i){
    pref[i]+=pref[i-1];
  }
 }

 k-=sum;
 if(m==n){
  for(int i=0;i<n;i++){
    cout<<0<<" ";
  }
  cout<<endl;
  return;
 }
 
 vi fin;
 fin.resize(n);
//  pr(arr);
//  pr(brr);
//  pr(pref);
 for(int i=0;i<n;i++){
  lli lo=0,hi=k,ans=-1;
  while(lo<=hi){
    lli mid=(lo+hi)/2;
    if(check(mid,i)){
      ans=mid;
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }  
  }
  fin[brr[i].S]=ans;
 }
 for(int i=0;i<n;i++){
  cout<<fin[i]<<" ";
 }
 cout<<endl;

  check(1,3);

}

int main(){
 IOS

// cin>>tt;
tt=1;
while(tt--)
solve();

}