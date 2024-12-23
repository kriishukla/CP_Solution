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

lli rec(lli x,lli move){
   if(x==0){
     return 0;
   }
   if(dp[x][move]!=-1){
    return dp[x][move];
   }
  lli ans;bool set1=false;

   for(int i=0;i<n;i++){
    if(x>=arr[i] && set1==false){
     //  cout<<" "<<(x-arr[i])<<endl;
      ans=1-rec(x-arr[i],(move+1)%2);
      set1=true;
      continue;
    }
    if(x>=arr[i]){ //cout<<" "<<(x-arr[i])<<endl;
      ans=(ans|(1-rec(x-arr[i],(move+1)%2)));
   }
   }
  // cout<<"x:"<<x<<" "<<ans<<endl;
 if(set1==false){
    return dp[x][move]=0;
 }
   return dp[x][move]=ans;
}

void solve(){
cin>>n>>k;

arr.resize(n);
dp.assign(k+2,vector<lli>(2,-1));

for(int i=0;i<n;i++){
 cin>>arr[i];
}

if(rec(k,0)){
  cout<<"First"<<endl;
}
else{
  cout<<"Second"<<endl;
}

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}