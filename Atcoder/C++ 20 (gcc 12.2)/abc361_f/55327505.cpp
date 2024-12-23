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
using mll = map<lli,lli>;
using vi = vector<lli>;
using vvi = vector<vector<lli>>;
using vpii = vector<pii>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define state pair<lli,pii>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mid (l+r)/2
#define lb lower_bound
#define ub upper_bound
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T bin_pow(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli fact[200200],inv_fact[200200];
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,z,h,c,w;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}

vi cost,dd,cntk,brr,crr,hh;

#undef mid
vi prime,primes;
vector<vpii> g;
vi arr,dis;


 lli dp[55][55][2505];
lli dx[]={0,0,1,-1};
lli dy[]={1,-1,0,0};


lli check(lli num){
  lli tmp=num*num;
  assert(tmp>0);
  return tmp<=n;
}

lli check1(lli num,lli n1){
  lli tmp=num*num;
  assert(tmp>0);
  return tmp<=n1;
}

lli pow2(lli num){
 lli lo=1,hi=1e9,ans=-1;
   while(lo<=hi){
    lli mid=(lo+hi)/2;
    if(check1(mid,num)){
        ans=mid;
        lo=mid+1;
    }
    else{
        hi=mid-1;
    }
  }
    
  if(ans*ans==num){
    return 1;
  }
  return 0;
 
}

void solve(){
  cin>>n;
  lli lo=1,hi=1e9,ans=-1;
  while(lo<=hi){
    lli mid=(lo+hi)/2;
    if(check(mid)){
        ans=mid;
        lo=mid+1;
    }
    else{
        hi=mid-1;
    }
  }
 
 lli sum=ans;
//  deb(sum);
 map<lli,lli> mp;
 for(lli i=2;i<=1000000;i++){
   lli tmp=i*i;
   if(tmp>n)break;
   for(int j=3;j<=80;j++){
   if(n/i<tmp)break;
    tmp=tmp*i;
    
       if( tmp>n)break;
       if(pow2(tmp))continue;
    mp[tmp]++;
   }
 }
cout<<sum+mp.size()<<endl;
}



int main() {
    IOS
  
    // cin>>tt;
    tt=1;
    while(tt--)
     solve();
    
}