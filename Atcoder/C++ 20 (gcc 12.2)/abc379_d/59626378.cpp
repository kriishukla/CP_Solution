#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 //find_by order()->iterator of indexed element,  order_of_key()-> number of elements strictly less than x
#define lli long long int
typedef tree < lli,  null_type ,  less_equal<lli> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
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
lli n,m,x,k,tt,q,p,y,h,c,w,l,r,d,t0,t1,t2,i;
lli lcm(lli a,lli b){
    return (a*b/__gcd(a,b));
}


vi arr,brr,pref;
vpii primes;
vi vis,fin,pos;
vvi g;





struct node{
  lli sum,lazy,inc,ble;
  node(){
    sum=0;
    lazy=0;
    inc=0;
    ble=0;
  }   
};

vector<node> t;


void push(lli ix,lli l,lli r){
  
    //+=inc
          t[ix].sum+=t[ix].inc *(r-l+1);
          if(l!=r){
            t[ix<<1].inc+=t[ix].inc;
            t[ix<<1|1].inc+=t[ix].inc;
          }
          t[ix].inc=0;
  
}

void build(lli ix,lli l,lli r){
   if(l==r){
    t[ix].sum=arr[l];
    t[ix].lazy=0;
    t[ix].inc=0;
    return;

   }
   build(ix<<1,l,mid);
   build(ix<<1|1,mid+1,r);
   
   t[ix].sum=t[ix<<1].sum+t[ix<<1|1].sum;
   t[ix].lazy=0;
   t[ix].inc=0;

}


void update(lli ix,lli l,lli r,lli lq,lli rq,lli val,lli type){
  push(ix,l,r);
    if(r<lq || l>rq)return;
    if(l>=lq && r<=rq){
        if(type==1)t[ix].inc+=val;
        if(type==2){
          t[ix].lazy=val;
          t[ix].inc=0;
        }
        t[ix].ble=1;
      push(ix,l,r);
      return;
    }
    update(ix<<1,l,mid,lq,rq,val,type);
    update(ix<<1|1,mid+1,r,lq,rq,val,type);
   t[ix].sum=t[ix<<1].sum+t[ix<<1|1].sum;
   t[ix].lazy=0;
   t[ix].inc=0;
}

lli query(lli ix,lli l,lli r,lli lq,lli rq){
   push(ix,l,r);
    if(r<lq || l>rq)return 0;
    if(l>=lq && r<=rq){
      return t[ix].sum;
    }
    return query(ix<<1,l,mid,lq,rq)+query(ix<<1|1,mid+1,r,lq,rq);
}

#undef mid


lli check(lli mid,lli h){
  lli xx=query(1,0,n,mid,mid);
  return xx>=h;
}


lli solve(lli n1,lli m1){
  cin>>n;
  t.resize(4*(n+2)+4);
  lli en=n,st=n+1;

  for(int i=0;i<n;i++){
    lli x;
    assert(st>=0 && en>=0);
    cin>>x;
    if(x==1){
      st--;
    }
    else if(x==2){
      lli t;
      cin>>t;
      if(st<=en){
        update(1,0,n,st,en,t,1);
      // cout<<"2"<<endl;
      // deb2(st,en);
      // deb(query(1,0,n,st,en));
      }
    }
    else{
      // cout<<'3'<<endl;
      lli h;
      cin>>h;
      if(st>en){
        cout<<0<<endl;
        continue;
      }
      lli lo=st,hi=en,ans=-1;
      while(lo<=hi){
        lli mid=(lo+hi)/2;
        // deb(mid);
        if(check(mid,h)){
         ans=mid;
         hi=mid-1;
        }
        else{
          lo=mid+1;
        }
      }
      if(ans==-1){
        cout<<0<<endl;
        continue;
      }
          cout<<en-ans+1<<endl;
      en=ans-1;
    }
  }
  return 1;
}


int main(){
 IOS

  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
 
//  deb(nCr(5,2));
// mem(dp,-1);
// mem(test,-1);

// cin>>tt;
tt=1;
// lli cnt=1;
  while(tt--){
    // deb(tt);
  solve(0,0);
  
  }
  
}