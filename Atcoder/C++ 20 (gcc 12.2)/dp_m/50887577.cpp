#include<bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define F first
#define S second
#define MP make_pair
#define INF 1e17
#define pii pair<lli,lli>
const int M = 1000000007;
lli n,m,x,y,z,b,k;
vector<lli> arr,fin,pref;
lli dp[2][100100];
lli dx[]={0,1,0,-1};
lli dy[]={-1,0,1,0};
map<char,pii> mp;
map<pii,lli> rmp;
string str1,str2;
lli vis[7][7];

 
lli rec(lli level,lli cd){
    if(cd>k)return 0;
  if(level==n){
   if(cd==k){
    return 1;
   }
   return 0;
   }

   if(dp[level][cd]!=-1){
    return dp[level][cd];
   }
   lli ans=0;
   for(int i=0;i<=arr[level] && cd+i<=k;i++){
    ans=(ans+rec(level+1,cd+i))%M;
   }
   return dp[level][cd]=ans;
}


void solve() {
memset(dp,0,sizeof(dp));
  
 cin>>n>>k;
 arr.resize(n);
 pref.resize(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
  
}

for(int level=n;level>=0;level--){
    for(int cd=k;cd>=0;cd--){

  if(level==n){
   if(cd==k){
    dp[level&1][cd]=1;
    continue;
   }
   dp[level&1][cd]=0;
   continue;
   }

   lli ans=0;
//    for(int i=0;i<=arr[level] && cd+i<=k;i++){
//     ans=(ans+rec(level+1,cd+i))%M;
//    }
    //pref sum
    lli up=min(k,cd+arr[level]);
    ans=(dp[(level+1)&1][cd]-dp[(level+1)&1][up+1])%M;
    ans=(ans+M)%M;

    dp[level&1][cd]=ans;
    if(cd+1<=k){
       dp[level&1][cd]=(dp[level&1][cd]+dp[level&1][cd+1])%M;
    }
    }
}

cout<<dp[0][0]<<endl;
}
 
 
int main() {
    IOS;
    lli t;
    //cin >> t;

   t = 1;
    while (t--) {
        solve();
    }

  return 0;
}