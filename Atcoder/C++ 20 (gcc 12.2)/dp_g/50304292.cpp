#include <bits/stdc++.h>
using namespace std;
#define lli long long 
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
#define S second
#define all(o) o.begin(),o.end()
lli M=1000000007;
lli n,w,t,m,k;
lli dp[100100];
string str1,str2;
vector<vector<lli>> g;

lli rec(lli pos){
  if(dp[pos]!=-1){
    return dp[pos];
  }
  lli ans=0;
  for(auto p:g[pos]){
    ans=max(ans,1+rec(p));
  }
 return dp[pos]=ans;
}


void solve() {
cin>>n>>m;
g.resize(n+1);
for(int i=0;i<m;i++){
  lli x,y;
  cin>>x>>y;
  g[x].push_back(y);
}
for(int i=0;i<=n;i++){
  dp[i]=-1;
}
   lli fin=0;
for(int i=1;i<=n;i++){
  fin=max(fin,rec(i));
}
cout<<fin<<endl;
}


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
   
    t=1;
   
    while(t--)
     solve();

    

}