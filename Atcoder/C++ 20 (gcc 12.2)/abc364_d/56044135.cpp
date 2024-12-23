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
lli fact[1000100],inv_fact[1000100];
lli nCr(lli n,lli r){if(r>n || n<0 ||r<0)return 0;lli d=(inv_fact[r]*inv_fact[n-r])%M;  lli f=(fact[n]*d)%M;return f;}
lli nPr(lli n,lli r){return (nCr(n,r)*fact[r])%M;}
lli n,m,x,k,tt,q,p,y,z,h,c,w,l,r;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}
#undef mid
vi prime,primes;

vi arr,pref1,pref,vis;
vvi rg;
vector<pair<lli,pii>> brr;
deque<lli> v,v1;

lli check(lli mid,lli k,lli i){
  lli dis1=brr[i].F+mid;
  lli dis=brr[i].F-mid;
  lli num1=ub(all(v1),dis1)-v1.begin();
  lli num2=lb(all(v),dis)-v.begin();
  num2=v.size()-num2;
  return num1+num2>=k;
}

void solve(){
  cin>>n>>q;
  arr.resize(n);
  brr.resize(q);

  for(int i=0;i<n;i++){
    cin>>arr[i];
    v1.pb(arr[i]);
  }
   sort(all(v1));

  for(int i=0;i<q;i++){
   lli x,k;
   cin>>brr[i].F>>brr[i].S.F;
   brr[i].S.S=i;
  }
  sort(all(brr));
 vi ans1;
 ans1.assign(q,0);

  for(int i=0;i<q;i++){
   lli x=brr[i].F;
   lli k=brr[i].S.F;
   lli pos=brr[i].S.S;
   while(!v1.empty() && v1.front()<x){
    lli mm=v1.front();
    v1.pop_front();
    v.pb(mm);
   }
//    deb2(i,pos);
//    deb2(x,k);
//    cout<<"v:"<<endl;
//    for(auto a:v){
//     cout<<a<<" ";
//    }
//    cout<<endl;
//    cout<<"v1:"<<endl;
//  for(auto a:v1){
//     cout<<a<<" ";
//    }
//    cout<<endl;
   lli lo=0,hi=1e9,ans=-1;
   while(lo<=hi){
    lli mid=(lo+hi)/2;
    if(check(mid,k,i)){
      ans=mid;
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }
   }
 
   ans1[pos]=ans;
  }

 for(auto a:ans1){
  cout<<a<<endl;
 }
 
}



int main() {
    IOS
   
  //  fact[0]=1;
  //  for(int i=;i<=1000000;i++){
  //    fact[i]=(i*fact[i-])%M;
  //  }
  //  for(int i=0;i<=1000000;i++){
  //   inv_fact[i]=bin_pow<lli>(fact[i],M-2,M);
  //  }
  //  deb(nCr(5,2));

    // cin>>tt;
    tt=1;
    while(tt--)
     solve();
    
}