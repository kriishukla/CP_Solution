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
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d,t0,t1,t2,i;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi arr,brr,pref;
vpii primes;
vi vis;
vvi g;

struct segt{


vector<lli> t;

segt(lli n){
  t.resize(4*n+4);
}

void build(lli ix,lli l,lli r){
  if(l==r){
    t[ix]=arr[l];

  return;
  }
 build(2*ix,l,mid);
 build(2*ix+1,mid+1,r);
 auto a=t[2*ix],b=t[2*ix+1];
t[ix]=a+b;
}

void update(lli ix,lli l,lli r,lli pos,lli val){ 
 if(pos<l || pos>r){
   return; 
  }
  
 if(l==r){
      t[ix]=val;
   return;
  }
 update(2*ix,l,mid,pos,val);
 update(2*ix+1,mid+1,r,pos,val);
 lli a=t[2*ix],b=t[2*ix+1];
 t[ix]=a+b;
}

lli query(lli ix,lli l,lli r,lli x,lli y){
  if(y<l || r<x){
    return 0;
  }


  if(x<=l && r<=y){
    return t[ix];
  }
   
 lli a=query(2*ix,l,mid,x,y);
 lli b=query(2*ix+1,mid+1,r,x,y);
  lli c=a+b;
  
  
 return c;
}
};

#undef mid



lli solve(lli n1,lli m1){
  cin>>n>>m;
  segt sgt(m);
  segt sgt1(m);

  arr.resize(n);
  pref.resize(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    pref[i]=arr[i];
    if(i){
      pref[i]+=pref[i-1];
    }
    pref[i]%=m;
  }
  
  lli dp[n+1]={0};
  lli sum=0;

  for(int i=0;i<n;i++){
    if(i==0){
      dp[i]=arr[i]%m;
      sgt.update(1,0,m-1,arr[i]%m,1);
      sgt1.update(1,0,m-1,arr[i]%m,arr[i]%m);
      lli cnt=1+(dp[i]==0);
      sgt.update(1,0,m-1,0,cnt);
        sum+=dp[i];
      continue;
    }
    lli x=0,y=0,sumx=0,sumy=0;
    if(pref[i]>=0){
      x+=sgt.query(1,0,m-1,0,pref[i]-1);
      sumx+=sgt1.query(1,0,m-1,0,pref[i]-1);
    }
    
    if(pref[i]+1<m){
      y+=sgt.query(1,0,m-1,pref[i]+1,m-1);
      sumy+=sgt1.query(1,0,m-1,pref[i]+1,m-1);
    }
    // deb(i);
    // deb2(x,y);
    // deb2(sumx,sumy);

    dp[i]=x*pref[i]-sumx;
    dp[i]+=(m*y+pref[i]*y-sumy);
    sum+=dp[i];
    lli xx=sgt.query(1,0,m-1,pref[i],pref[i]);
    xx++;
    sgt.update(1,0,m-1,pref[i],xx);
    sgt1.update(1,0,m-1,pref[i],xx*pref[i]);

  }

  cout<<sum<<endl;
 return 1;

}


int main(){
 IOS

  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
//  fact[0]=1;
//  inv_fact[0]=bin_pow<lli>(fact[0],M-2,M);
//  for(int i=1;i<1000100;i++){
//    fact[i]=i*fact[i-1];
//    fact[i]%=M;
//    inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
//  }
//  deb(nCr(5,2));

// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--){
    // deb(tt);
  solve(0,0);
  
  }
  
}