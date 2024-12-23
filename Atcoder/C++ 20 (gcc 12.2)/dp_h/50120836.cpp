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
lli n,t,k,w,m,h;


vector<pii> arr;
string str1,str2,str;
set<string> st;
vector<vector<lli>> dp;
vector<vector<char>> v;
lli mark[3001];




lli rec(lli i,lli j){
  
     if(i<0 || i>=h ||j<0 || j>=w)return 0;
     if(v[i][j]=='#')return 0;
     if(i==h-1 && j==w-1)return 1;
     if(dp[i][j]!=-1){
      return dp[i][j];
     }
     lli ans=(rec(i+1,j)%M+rec(i,j+1)%M)%M;
    return dp[i][j]=ans;
}



void solve(){
  cin>>h>>w;
   v.resize(h,vector<char>(w));
   dp.assign(h,vector<lli>(w,-1));
   for(int i=0;i<h;i++){
     for(int j=0;j<w;j++){
      cin>>v[i][j];
     }
   }

 cout<<rec(0,0)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  solve();

    return 0;
}