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
lli dp[1<<17],pref[102][102][102],s_t[1<<17];
string str,p;
map<char,vector<lli>> mp;
vector<vector<char>> v;
vector<lli> div1[2001];
vector<vector<lli>> dis,gcd1,arr;
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


void solve(){
 cin>>n;
 memset(dp,0,sizeof(dp));
 memset(s_t,0,sizeof(s_t));
 arr.assign(n+1,vector<lli>(n+1,0));
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
 }

 for(int i=1;i<(1<<n);i++){
   
 vector<lli> a1;
    for(int j=0;j<32;j++){
        if((i>>j)&1){
            a1.push_back(j);
        }
    }
  lli cost=0;
    for(int i1=0;i1<a1.size();i1++){
        for(int j=i1;j<a1.size();j++){
            cost+=arr[a1[i1]][a1[j]];
        }
    }

    s_t[i]=cost;
 }


// for(int i=0;i<(1<<n);i++){
//   cout<<s_t[i]<<" ";
// }
// cout<<endl;

for(int i=1;i<(1<<n);i++){
    for(int s=i;s>0;s=((s-1)&i)){
       dp[i]=max(dp[i],s_t[s]+dp[i&(~s)]); 
    }
}

fin.push_back(dp[(1<<n)-1]);

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