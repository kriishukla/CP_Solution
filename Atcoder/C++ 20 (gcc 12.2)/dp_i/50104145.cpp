#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ld=long double;
#define endl '\n'
#define F first
#define S second
lli INF= 1e15;
#define MP make_pair
using pii= pair<lli,lli>;
#define mid (l+r)/2
lli M=1000000007;
lli n,t,k,w;

ld dp[3001][3001];
vector<ld> arr;

ld rec(lli x,lli head){
    if(x==n){
        if(head>n-head)return 1;
        return 0;
    }
    if(dp[x][head]!=-1){
        return dp[x][head];
    }
    ld ans=(1-arr[x])*rec(x+1,head)+arr[x]*rec(x+1,head+1);
  
  return dp[x][head]=ans;

}


void solve(){
 cin>>n;
 arr.resize(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 
 for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
        dp[i][j]=-1;
    }
 }
cout<<fixed<<setprecision(10)<<rec(0,0)<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}