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

lli M=1000000007;
lli n,t,k,w,m;

lli dp[110][105000];
vector<pii> arr;
string str1,str2,str;
set<string> st;
lli mark[3001];




lli rec(lli x,lli left_val){
if(x<=n && left_val<=0)return 0;
if(x==n){
    if(left_val>0)return INF;
    return 0;
}
if(dp[x][left_val]!=-1){
   return dp[x][left_val];
}
lli ans=rec(x+1,left_val);

    ans=min(ans,arr[x].F+rec(x+1,left_val-arr[x].S));
   // if(left_val<0)return ans;
return dp[x][left_val]=ans;
}

lli check(lli val){//cout<<rec(0,val)<<endl;
  return w>=rec(0,val);
}

void solve(){
 cin>>n>>w;
 memset(dp,-1,sizeof(dp));

 for(int i=0;i<n;i++){
    lli y,z;
    cin>>y>>z;
    arr.push_back(MP(y,z));
 }

 lli lo=1,hi=1e5+500,ans=-1;
 while(lo<=hi){
    lli mid=(lo+hi)/2;
  // cout<<"mid:"<<mid<<endl;
    if(check(mid)){
        ans=mid;
        lo=mid+1;
    }
    else{
        hi=mid-1;
    }
 }
//cout<<check(35)<<endl;
 cout<<ans<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}