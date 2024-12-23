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
vector<lli> arr;
deque<lli> dq;
lli rec(lli l,lli r){
   if(l>r)return 0;
   if(dp[l][r]!=-1){
    return dp[l][r];
   }

   lli ans=max(arr[l]-rec(l+1,r),arr[r]-rec(l,r-1));
   return dp[l][r]=ans;
}

void solve(){
cin>>n;

arr.resize(n);
dp.assign(n+2,vector<lli>(n+2,-1));

for(int i=0;i<n;i++){
 cin>>arr[i];
 }

cout<<rec(0,n-1)<<endl;


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}