//28, 07, 2018, 08:56:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        ll m;

        scanf("%d %lld", &n, &m);

        ll work_hour = 0LL;
        int hour_start, minute_start, hour_end, minute_end;

        for(int i = 0 ; i < n ; i++){
            scanf("%d:%d %d:%d", &hour_start, &minute_start, &hour_end, &minute_end);

            ll diff = hour_end * 60LL + minute_end - (hour_start * 60LL + minute_start);

            work_hour += diff;
        }

        m *= 60LL;

        if(work_hour >= m){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}