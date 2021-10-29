#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, a, b;

        scanf("%d %d %d %d", &n, &m, &a, &b);

        vector< int > v;

        for(int i = 0 ; i < m ; i++){
            int ai;

            scanf("%d", &ai);

            v.push_back(ai);
        }

        int nums = min(abs(a - b) - 1, m);
        sort(v.begin(), v.end());
        int tim = 0;

        if(a < b){
            tim = b - 2;
        }else{
            tim = n - b - 1;
        }

        int cnt = 0;

        for(int i = nums - 1 ; i >= 0 ; i--){
            if(v[i] + cnt <= tim){
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}