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
lli nCr(lli n,lli r){if(n==0)return 0;if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,h,c,w,l,r;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi arr,brr,crr;
vi pref;

vpii t;
// void build(lli ix,lli l,lli r){
//   if(l==r){
//     t[ix]=arr[l];

//   return;
//   }
//  build(2*ix,l,mid);
//  build(2*ix+1,mid+1,r);
//  auto a=t[2*ix],b=t[2*ix+1];
// t[ix]=max(a,b);
// }

void update(lli ix,lli l,lli r,lli pos,pii val){ 
 if(pos<l || pos>r){
   return; 
  }
  
 if(l==r){
      t[ix]=val;
   return;
  }
 update(2*ix,l,mid,pos,val);
 update(2*ix+1,mid+1,r,pos,val);
 auto a=t[2*ix],b=t[2*ix+1];
 t[ix]=max(a,b);
}

pii query(lli ix,lli l,lli r,lli x,lli y){
  if(y<l || r<x){
    return MP(0,-1);
  }


  if(x<=l && r<=y){
    return t[ix];
  }
   
 auto a=query(2*ix,l,mid,x,y);
 auto b=query(2*ix+1,mid+1,r,x,y);
 auto c=max(a,b);
  
  
 return c;
}


vvi g;
lli dp[200200];
vpii pos;
vi back;

void solve(){
   cin>>h>>w;
   t.assign(4*w+4,MP(0,-1));
   g.resize(h+1);

   cin>>n;
   g[1].pb(1);
   g[h].pb(w);
   for(int i=0;i<n;i++){
    lli x,y;
    cin>>x>>y;
    g[x].pb(y);
   }
   for(int i=1;i<=h;i++){
    sort(all(g[i]));
   }
   pos.resize(n+3);
   lli cnt=1;
   for(int i=1;i<=h;i++){
    for(auto a:g[i]){
      pos[cnt]=MP(i,a);
      cnt++;
    }
   }
 
   back.assign(n+3,-1);  
  //  pr(pos);
   for(int i=n+2;i>=1;i--){
    if(i==n+2){
      dp[i]=0;
      update(1,0,w,w,MP(dp[i],i));
      back[i]=-1;
      continue;
    }
    lli wt=1;
    if(i==1)wt=0;
    auto [x,y]=pos[i];
    auto [val,ii]=query(1,0,w,y,w);
    dp[i]=wt+val;
    back[i]=ii;
    // deb2(i,ii);
    // deb(val);
    update(1,0,w,y,MP(dp[i],i));
   }
   cout<<dp[1]<<endl;
  //  pr(back);
   lli curr=1;
   string str;
   while(back[curr]!=-1){
    lli nxt=back[curr];
    auto [x1,y1]=pos[curr];
    auto [x2,y2]=pos[nxt];
    // deb2(curr,nxt);
    while(y1!=y2){
      str+='R';
      y1++;
    }
    while(x1!=x2){
      str+='D';
      x1++;
    }
    curr=nxt;
   }
   cout<<str<<endl;
}
 
 
 
int main() {
    IOS
  // std::ofstream ofs("input.txt", std::ios::trunc); // Opening file in trunc mode
 
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  //  fact[0]=1;
  //  for(lli i=1;i<=200200;i++){
  //    fact[i]=(i*fact[i-1])%M;
  //  }
  //  for(lli i=0;i<=200200;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }
  //  deb(nCr(5,2));
    // ordered_set st;
    // st.insert(1);
    // st.insert(1);
    // cout<<st.order_of_key(1+1)<<endl;
    //  cin>>tt;
    tt=1;
     lli cnt=1;
    while(tt--){
    //  cout<<"Case #"<<cnt<<": ";
     solve();
     cnt++;
    }
    
 
}