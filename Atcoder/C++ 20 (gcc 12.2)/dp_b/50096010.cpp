#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
#define endl '\n'
#define F first
#define S second
lli INF= INT_MAX;
#define MP make_pair
using pii= pair<lli,lli>;
#define mid (l+r)/2
lli M=1000000007;
lli n,t,k;

vector<lli> arr,dp;

lli rec(lli x){
  if(x==n-1)return  0;
  if(dp[x]!=-1){
    return dp[x];
  }
  lli ans=INF;
  for(int i=1;i<=k && x+i<n;i++){
    // cout<<"x:"<<" "<<"i:"<<endl;
    // cout<<x<<" "<<i<<endl;
    lli ans1=abs(arr[x]-arr[x+i])+rec(x+i);
   // cout<<ans1<<endl;
    ans=min(ans,ans1);
  }

return dp[x]=ans;
}

void solve(){
cin>>n>>k;
dp.assign(n+1,-1);
arr.resize(n);
for(int i=0;i<n;i++){
  cin>>arr[i];
}

cout<<rec(0)<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}