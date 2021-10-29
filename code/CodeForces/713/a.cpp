#include <bits/stdc++.h>

using namespace std;

int cnt[110];
int a[110];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            cnt[a[i]]++;
        }

        for(int i = 0 ; i < n ; i++){
            if(cnt[a[i]] == 1){
                cout << i + 1 << endl;
                break;
            }
        }

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}