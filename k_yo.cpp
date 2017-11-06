#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
int k;

bool vi[30];
int cnt = 0;
bool check(int m){
    for(int i=1;i<=24;++i) vi[i] = 0;
    cnt = 0;
    int ss = 1,now = 1;
    while(cnt<12){
        now++;
        if(now == 25) now -= 24;
        if(!vi[now]) ss++;
        if(ss == m) {
            vi[now] = 1,ss=0,cnt++;
            //cout<<now<<"\n";
            if(now<=12) return 0;
        }
    }
    return 1;
}


int main(){
   // for(k=13;k<=99999999;++k)
   //     if(check(k))
   //     cout<<k<<"\n";
   cout<<check(1358657);
    return 0;
}
