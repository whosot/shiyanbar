#include<cstdio>
#include<iostream>
#include<cmath>
#include<ctime>

typedef long long LL;
const LL  K = 2000000000;
inline LL mi(LL a,LL b) {return a<b?a:b;}
inline LL sq(LL a,LL b) { 
    LL ans = 1;
    while(b){
        if(b&1) ans=mi(ans*a,K);
        a=mi(a*a,K);
        b>>=1;
    }
   // std::cout<<ans<<"\n";
    return  mi(ans,K);
} 
using namespace std;
LL N = 1600000;
LL kk[35];

bool check(LL x){
    LL cnt = 0;
    LL xx=x;
    for(LL k=2;k<=10;++k){
        xx=x;
        LL j=30;
        while(sq(k,j) > xx) j--;
       // cout<<j<<"\n";
        LL c = 0;
        while(xx || j>=0){
            LL tp = sq(k,j);
            c++;
            kk[c] = 0;
            if(tp <= xx) {
                
                while(tp<=xx) { kk[c]++,xx-=tp;//cout<<tp<<" "<<xx<<"\n";
                }
            }
            j--;
            //cout<<j<<"\n";
        }
        int f = 0;
        //for(int i=1;i<=c;++i) cout<<kk[i];
        //cout<<"\n";
        for(int i=1;i<=c/2;++i) if(kk[i] != kk[c-i+1]) {f=1;break;}
        if(!f) cnt++;
       // cout<<f<<"\n";
    }
    if(cnt >= 2) return 1;
    return 0;
}

int main(){
    while(1){
        N++;
        //cout<<N<<"\n";
        if(check(N)){
            cout<<N<<"\n";
            break;
        }
    }
   // cout<<check(1632995);
    cout<<clock();
    return 0;
}

