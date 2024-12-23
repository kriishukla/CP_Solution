#include<bits/stdc++.h>

using namespace std;
#define lli long long int 
#define endl '\n'
using pii=pair<lli,lli>;
#define MP make_pair
#define F first
#define ld long double
#define S second
#define all(o) o.begin(),o.end()
lli M=1e9+7;
lli INF=1e17;
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
lli n,w,m,k,pb1,ps,t;
#define mid (l+r)/2

vector<set<lli>> st;
vector<vector<lli>> g,indi;
vector<lli> par,size1,distinct,val;
vector<pii> edges;



void print(vector<lli> &arr){
  for(auto a:arr){
    cout<<a<<" ";
  }
  cout<<endl;
}


multiset<lli> mt;
vector<lli> fin;
 lli found=0,r;
lli nb,ns,nc,hb,hc,hs,rb,rs,rc;

template <typename T> T bin_pow(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}

#undef mid
  string str;

vector<lli> arr;
vector<lli> primes;
bool is_prime[10001];


lli msb(lli x){
  lli temp=x;
  lli count=0;
  while(temp){
     count++;
     temp/=2;
  }
  return count;
}

lli dp[3003][3003],min_[100100];
bool done[100100];

void solve(){
  lli w;
//  cin>>n;
string s,t;
cin>>s>>t;

 vector<ld> arr,brr,crr;
// arr.resize(n);
// brr.resize(n);


for(int i=0;i<=3000;i++){
  for(int j=0;j<=3000;j++){
    dp[i][j]=0;
  }
}

for(int i=s.size();i>=0;i--){
  for(int j=t.size();j>=0;j--){
    if(i==s.size() || j==t.size()){
      dp[i][j]=0;
      continue;
    }
    dp[i][j]=max({dp[i+1][j],dp[i][j+1]});
    if(s[i]==t[j]){
      dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
    }
  }
}

lli i=0,j=0;
// cout<<dp[0][0]<<endl;
string str;
while(i<s.size() && j<t.size()){
  // deb2(i,j);
  // deb2(dp[i][j],dp[i+1][j]);
  // deb2(dp[i+1][j+1],dp[i][j+1]);
   if(dp[i][j]==dp[i+1][j]){
    i++;
   }
   else if(dp[i][j]==dp[i][j+1]){
    j++;
   }
   else if(s[i]==t[j] && dp[i][j]==(1+dp[i+1][j+1])){
   str.pb(s[i]);
    i++;
    j++;
    
   }
}
cout<<str<<endl;
}





int main() {
   IOS
  // for(int i=0;i<10001;i++){
  //   is_prime[i]=true;
  // }

  // for(int i=2;i<=10000;i++){
  //   if(is_prime[i]){
  //     primes.pb(i);
  //     for(int j=i*i;j<=10000;j+=i){
  //       is_prime[j]=false;
  //     }
  //   }
  // }
  // cout<<primes.size()<<endl;

  // cin>>t;
  t=1;
    while(t--)
     solve();


}