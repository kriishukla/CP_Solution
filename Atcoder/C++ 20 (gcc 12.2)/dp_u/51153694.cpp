#include <bits/stdc++.h>
using namespace std;
#define lli long long 
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
lli INF=1e17;
#define S second
#define all(o) o.begin(),o.end()
lli M=1000000007;
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
lli n,w,t,m,k,d;
lli dp[2][2][101][10200];

vector<lli> cost;
vector<state> q;
string str,str1;
 
vector<string> brr,crr,a1,b1,fin;


 
lli rec(lli lvl,lli sum,lli flag1,lli flag2){
   if(lvl==n){
     if(sum%d==0){
        return 1;
     }
     return 0;

   }
   if(dp[flag1][flag2][sum][lvl]!=-1){
    return dp[flag1][flag2][sum][lvl];
   }
 
  lli lo=0,hi=9,f1=0,f2=0;
  if(flag1==1){
    lo=str1[lvl]-'0';
    f1=1;
  }
  if(flag2==1){
    hi=str[lvl]-'0';
    f2=1;
  }
  lli ans=0;
  
  for(int i=lo;i<=hi;i++){
    if(i==lo && i==hi){
     ans=(ans+rec(lvl+1,(sum+i)%d,f1,f2))%M;
    }else if(i==lo){
      ans=(ans+rec(lvl+1,(sum+i)%d,f1,0))%M;
    }
    else if(i==hi){
      ans=(ans+rec(lvl+1,(sum+i)%d,0,f2))%M;
    }
    else{
      ans=(ans+rec(lvl+1,(sum+i)%d,0,0))%M;
    }
  }
  // deb2(lvl,ans);
  // deb2(f1,f2);

   return dp[flag1][flag2][sum][lvl]=ans;
}
 
void solve() {
  cin>>str>>d;
  memset(dp,-1,sizeof(dp));
 n=str.size();
 for(int i=0;i<str.size();i++){
  if(i==str.size()-1){
    str1.push_back('1');
  }
  else{
    str1.push_back('0');
  }
 }
 //cout<<str<<" "<<str1<<endl;
 cout<<rec(0,0,1,1)<<endl;
}
 
 
int main() {
   IOS

    //cin>>t;
    t=1;
    while(t--)
     solve();
   
//  for(auto a:fin){
//   cout<<a<<endl;
//  }
 
}