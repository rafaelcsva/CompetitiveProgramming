#include <bits/stdc++.h>

using namespace std;

const int N = int(1e7) + 10;
int cnt[N];
int ans[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1 ; i < N ; i++){
        for(int j = i ; j < N ; j += i){
            cnt[j] += i;
        }
    }

    // printf("aqui!\n");
    for(int i = 1 ; i < N ; i++){
        if(cnt[i] < N && ans[cnt[i]] == 0){
            ans[cnt[i]] = i;
        }
    }

    int t;

    cin >> t;

    while(t--){
        int ai;

        cin >> ai;

        cout << (ans[ai] ? ans[ai] : -1) << endl;
    }

    return 0;
}