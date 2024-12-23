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

vector<vector<lli>> arr,dp;

lli rec(lli x,lli match,lli prev){
if(x==n)return 0;
if(match>=2)return -INF;
if(prev!=-1 && dp[prev][x]!=-1) {
  return dp[prev][x];
}

lli ans=-INF;
//cout<<"x:"<<x<<endl;
for(int i=0;i<3;i++){
  if(i!=prev){//cout<<i<<endl;
  ans=max(ans,arr[i][x]+rec(x+1,1,i));
 // cout<<"ans:"<<ans<<" "<<arr[i][x]+rec(x+1,1,i)<<endl;
  
  }
}
if(prev==-1)return ans;
return dp[prev][x]=ans;
}

void solve(){
cin>>n;
arr.resize(3,vector<lli>(n));
dp.assign(3,vector<lli>(n,-1));

for(int i=0;i<n;i++){
  for(int j=0;j<3;j++){
    cin>>arr[j][i];
  }
}


cout<<rec(0,0,-1)<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}