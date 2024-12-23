#include <bits/stdc++.h>

using namespace std;
#define lli long long int 
#define endl '\n'
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
lli INF=1e7;
#define S second
#define all(o) o.begin(),o.end()
lli M=1000000007;
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

lli n,w,totalcost,t,m,k,x,y;

vector<lli> cost,fin;

vector<state> q;
lli dp[1<<22],pref[102][102][102],s_t[1<<17];
string str,p;
map<char,vector<lli>> mp;
// vector<vector<char>> v;
vector<lli> div1[2001];
vector<vector<lli>> dis,gcd1,arr,v;
char d[]={'a','e','i','o','u'};

void divisors(){
   for(lli i=1; i<=2000; ++i){
       for(lli j=i; j<=2000; j+=i){
           div1[j].push_back(i);
       }
   }
}

long long GCD(long long x, long long y)
{
    if (y == 0) return x;
    return GCD(y, x%y);
}

lli rec(lli lvl,lli mask){
    if(lvl==n+1){
        return 1;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    lli ans=0;
    for(auto a:v[lvl-1]){
        if(((mask>>a)&1)==0){
         ans+=rec(lvl+1,(mask|(1<<a)));
         ans%=M;
        }
    }
//   deb2(lvl,ans);
//   deb(mask);
    return dp[mask]=ans;

}

void solve(){
 cin>>n;
 memset(dp,-1,sizeof(dp));
 memset(s_t,0,sizeof(s_t));
 arr.assign(n+1,vector<lli>(n+1,0));
 v.resize(n+1);
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
        if(arr[i][j]==1){
            v[i].push_back(j);
        }
    }
 }
 
// for(auto a:v){
//     for(auto b:a){
//         cout<<b;
//     }
//     cout<<endl;
// }

fin.push_back(rec(1,0));

}



int main() {
   IOS
 
  // cin>>t;
   t=1;
    while(t--)
     solve();

    for(auto a:fin){
      cout<<a<<endl;
    }

}