#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
lli M=1000000007;
lli n,m,k;
vector<lli> arr,fin,brr,pref;
lli dp[404][404];

lli rec(lli l,lli r){
    if(l==r)return 0;
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    lli ans=1e17;
   for(int i=l;i<r;i++){
      ans=min(ans,pref[r+1]-pref[l]+rec(l,i)+rec(i+1,r));
   }
   return dp[l][r]=ans;
}


void solve(){
    cin>>n;
    arr.resize(n);
    pref.resize(n+1);
memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }

 for(int i=0;i<=n;i++){
    if(!i){
        pref[i]=0;
    }
    else{
        pref[i]=arr[i-1]+pref[i-1];
    }
 }

  cout<<rec(0,n-1)<<endl;
}

int main() {
    IOS;
    lli t ; 
    //cin>>t;
    t=1;
    
    while(t--){
        solve();
    }

    return 0;
}
