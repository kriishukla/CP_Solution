#include <bits/stdc++.h>
using namespace std;
#define lli long long 
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
#define S second
#define all(o) o.begin(),o.end()
lli M=1000000007;
lli n,w,t,m,k;
lli dp[3001][3001];
string str1,str2;
lli rec(lli x,lli y){
  if(x==str1.size()|| y==str2.size()){
    return 0;
  }
  if(dp[x][y]!=-1){
    return dp[x][y];
  }
  lli ans=rec(x+1,y);
   ans=max(ans,rec(x,y+1));
   if(str1[x]==str2[y]){
    ans=max(ans,1+rec(x+1,y+1));
   }
   return dp[x][y]=ans;
}

string str;
string fin;
void find_str(lli x,lli y){
    if(x==str1.size()|| y==str2.size()){
    return;
    }

    if(rec(x,y)==rec(x+1,y)){
      find_str(x+1,y);
    }
    else if(rec(x,y)==rec(x,y+1)){
          find_str(x,y+1);
    }
    else{
      fin+=str1[x];
         find_str(x+1,y+1);
    }

}

void solve() {

  cin>>str1>>str2;
  for(int i=0;i<=str1.size();i++){
    for(int j=0;j<=str2.size();j++){
      dp[i][j]=-1;
    }
  }
  lli len=rec(0,0);

 //cout<<len<<endl;
  find_str(0,0);
  cout<<fin<<endl;
}


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
   
    t=1;
   
    while(t--)
     solve();

    

}