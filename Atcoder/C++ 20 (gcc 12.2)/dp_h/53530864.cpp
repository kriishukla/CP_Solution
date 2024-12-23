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

lli dp[1010][1010],min_[100100];
bool done[100100];

void solve(){
  lli h,w;
 cin>>h>>w;


 vector<vector<char>> arr,brr,crr;
arr.assign(h+5,vector<char>(w+5,'.'));
// brr.resize(n);
for(int i=1;i<=h;i++){
  for(int j=1;j<=w;j++){
  cin>>arr[i][j];
  }
}

for(int i=0;i<=1005;i++){
  for(int j=0;j<=1005;j++){
    dp[i][j]=0;
  }
}

for(int i=1;i<=h;i++){
  for(int j=1;j<=w;j++){
    if(i==1 && j==1){
      dp[i][j]=1;
      continue;
    }
    if(arr[i][j]=='#')continue;
    dp[i][j]=dp[i-1][j]+dp[i][j-1];
    dp[i][j]%=M;
  }
}

cout<<dp[h][w]<<endl;

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