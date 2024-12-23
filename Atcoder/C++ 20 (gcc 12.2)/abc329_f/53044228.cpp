#include <bits/stdc++.h>

using namespace std;
#define lli long long int 
#define ld long double
#define endl '\n'
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
lli INF=1e17;
#define pb push_back
#define S second
#define all(o) o.begin(),o.end()
#define mid (l+r)/2
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

lli n,w,m,k,d,tt,t,a,b,q,x,y;
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T bin_pow(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}

// vector<vector<char>> v;
vector<lli> div1[2001];
vector<vector<lli>> gcd1,v;
lli dis[1001][1001],vis[1001][1001];
char arr[1001][1001];
lli lcd[1000101];
ld is_prime[100110];
vector<vector<pii>> g;
bool is_valid(lli i,lli j){
  if(i>=0 && i<n && j>=0 && j<m){
    return 1;
  }
  return 0;
}
lli dx[]={0,0,1,-1,1,1,-1,-1};
lli dy[]={1,-1,0,0,1,-1,1,-1};
#undef mid

pii st,en;


lli min_cycle;

// vector<pii> neigh(lli i,lli j){
//   vector<pii> p;
//   for(int mm=0;mm<4;mm++){
//     lli r=i+dx[mm];
//     lli c=j+dy[mm];
//     if(is_valid(r,c)){
//       p.pb(MP(r,c));
//     }
//   }
//   return p;
// }
map<pii,lli> mp;

vector<state> neigh(lli i,lli j){
  vector<state> p;
  for(int mm=0;mm<4;mm++){
    lli r=i+dx[mm];
    lli c=j+dy[mm];
    if(is_valid(r,c)){
     
  }
  }
  return p;

}


void bfs(lli i,lli j){
  deque<state> dq;
  dq.pb(MP(0,MP(i,j)));
  dis[i][j]=0;
  while(!dq.empty()){
    state node=dq.front();
    dq.pop_front();//cout<<"ii"<<endl;
    lli i1=node.S.F,j1=node.S.S,d=node.F;
    // deb2(i1,j1);
    // deb(d);
    // cout<<"in"<<endl;
    for(auto a:neigh(i1,j1)){
      lli i2=a.S.F,j2=a.S.S,dd=a.F;
      // deb2(i2,j2);
      // cout<<neigh(i,j).size()<<endl;
      if(dis[i2][j2]>dis[i1][j1]+dd){
        dis[i2][j2]=dis[i1][j1]+dd;
        if(dd==0){
          dq.push_front(MP(dis[i2][j2],MP(i2,j2)));
        }
        else{
          dq.pb(MP(dis[i2][j2],MP(i2,j2)));
        }
      }
    }
  }
}
vector<lli> par,size1;
vector<lli> fin;
vector<lli> stg;
lli find(lli x){
  if(par[x]==x){
    return x;
  }
  return par[x]=find(par[x]);
}

lli merge(lli x,lli y,vector<set<lli>>& st){
  lli m=find(x),n=find(y);
  if(m==n)return 0;
  if(size1[m]>size1[n]){
    size1[m]+=size1[n];
    // stg[m]+=stg[n];
    par[n]=m;
   for(auto& a:st[n]){
    st[m].insert(a);
   }
  }
  else{
    size1[n]+=size1[m];
    // stg[n]+=stg[m];
    par[m]=n;
   for(auto& a:st[m]){
    st[n].insert(a);
   }
  }
  return 1;
}

void solve(){
  vector<lli> vis;
vector<pii> edges,query;
 cin>>n>>q;
 par.resize(n+1);
 size1.assign(n+1,1);
 vector<set<lli>> st;
 st.resize(n+1);
 for(int i=0;i<=n;i++){
  par[i]=i;
 }
 for(int i=0;i<n;i++){
  lli x;
  cin>>x;
  st[i+1].insert(x);
 }

 vis.assign(m+1,0);
//  for(int i=0;i<m;i++){
//    lli u,v;
//    cin>>u>>v;
//    edges.pb(MP(u,v));
//  }

 for(int i=0;i<q;i++){
   lli x,y;
   cin>>x>>y;
   if(st[y].size()<st[x].size()){
        swap(st[x],st[y]);
    
   }
   for(auto a:st[x]){
      st[y].insert(a);
    }
     st[x].clear();
     cout<<st[y].size()<<endl;
 }
 
 
}






int main() {
   IOS
 for(int i=0;i<100100;i++){
     is_prime[i]=1;
 }
  for(lli i=2;i<100100;i++){
    if(is_prime[i]==1){
      for(lli j=i*i;j<100100;j+=i){
        is_prime[j]=0;
      }
    }
  }
  is_prime[0]=0,is_prime[1]=0;
  for(int i=1;i<100100;i++){
    is_prime[i]+=is_prime[i-1];
  }
  // for(int i=0;i<10;i++){
  // cout<<is_prime[i]<<endl;
  // }

  //  cin>>tt;
 tt=1; 
  while(tt--){

    solve();
  }

//  for(auto a:fin){
//   cout<<a<<endl;
//  }

}