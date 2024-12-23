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
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,t0,t1,t2;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vvi arr,brr,crr;
vi pref,pref1;


map<char,pii> mp1;
char d[]={'N','S','E','W'};
map<char,char> opp;

vvi vis;
map<lli,map<lli,vpii>> v; 


pii path_comp(lli x,lli y,char dir){
      lli xx=x,yy=y;
//    cout<<"in:"<<endl;
   for(int i=0;i<4;i++){
    if(dir!=d[i])continue;
    // deb2(dir,d[i]);
    vpii vv;
    vv.pb(MP(x,y));
    while(xx>=1 && xx<=h && yy>=1 && yy<=w &&vis[xx][yy]==1){
        pii curr=v[xx][yy][i];
        xx=curr.F;
        yy=curr.S;
        
        vv.pb(curr);
        // if(x==2 && y==2){
        //   deb2(xx,yy);
        // }
        // deb2(xx,yy);
    }
    for(auto a:vv){
      lli x=a.F,y=a.S;

        if(vis[x][y]==1)
      v[x][y][i]=MP(xx,yy);
    }
    if(xx>=1 && xx<=h && yy>=1 && yy<=w){
    vis[xx][yy]=1;
       v[xx][yy].resize(4);
      v[xx][yy][0]=MP(xx-1,yy);
      v[xx][yy][1]=MP(xx+1,yy);
      v[xx][yy][2]=MP(xx,yy-1);
      v[xx][yy][3]=MP(xx,yy+1);
    }
   }
   return MP(xx,yy);
}

void solve(){
  cin>>h>>w>>q;
  vis.assign(h+2,vi(w+2,0));
  lli sum=h*w;
  for(int i=0;i<q;i++){
    cin>>r>>c;
    if(vis[r][c]==0){
      vis[r][c]=1;
      v[r][c].resize(4);
      v[r][c][0]=MP(r-1,c);
      v[r][c][1]=MP(r+1,c);
      v[r][c][2]=MP(r,c-1);
      v[r][c][3]=MP(r,c+1);
      // deb(i);
      sum--;
    }
    else{
      // deb(i);
      for(int j=0;j<4;j++){
        // if(r==2 && c==2){
        //   cout<<"yy"<<endl;
        // }
        pii xy=path_comp(r,c,d[j]);
        if(xy.F>=1 && xy.F<=h && xy.S>=1 && xy.S<=w){
            sum--;
            vis[xy.F][xy.S]=1;
        }
        
      }
    }
  //  deb(i);
  }

  cout<<sum<<endl;

}
 
 
 
int main() {
    IOS

    mp1['E']=MP(0,1);
   mp1['W']=MP(0,-1);
   mp1['S']=MP(1,0);
   mp1['N']=MP(-1,0);
    opp['N']='S';
    opp['S']='N';
    opp['E']='W';
    opp['W']='E';
  //  fact[0]=1;
  //  for(lli i=1;i<=200200;i++){
  //    fact[i]=(i*fact[i-1])%M;
  //  }
  //  for(lli i=0;i<=200200;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }
  //  deb(nCr(5,2));

    //  cin>>tt;
   tt=1;
    // tt=1;
    while(tt--)
     solve();
    
 
}