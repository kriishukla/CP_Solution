#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
#define endl '\n'
#define F first
#define S second
lli INF= 1e15;
#define MP make_pair
using pii= pair<lli,lli>;
#define mid (l+r)/2
lli M=1000000007;
lli n,t,k,w;

vector<vector<lli>> dp;
vector<pii> arr;
lli rec(lli x,lli left){
 if(left<0)return -INF;
 if(x==n)return 0;
 if(dp[x][left]!=-1){
  return dp[x][left];
 }

 lli ans=rec(x+1,left);
 if(arr[x].F<=left){
  ans=max(ans,arr[x].S+rec(x+1,left-arr[x].F));
 }
//cout<<"x:"<<x<<" "<<ans<<" "<<left<<endl;
return  dp[x][left]=ans;
}

void solve(){
cin>>n>>w;
dp.assign(n+2,vector<lli>(w+2,-1));

for(int i=0;i<n;i++){
  lli w1,v1;
  cin>>w1>>v1;
  arr.push_back(MP(w1,v1));
}




cout<<rec(0,w)<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}