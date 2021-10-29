#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5);
bool square[N];

int main(){
    for(int i = 1 ; i * i < N ; i++){
        square[i * i] = true;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        bool ver = false;

        for(int i = 0 ; i < n ; i++){
            int xi;

            scanf("%d", &xi);

            ver |= !square[xi];
        }

        printf("%s\n", ver ? "YES" : "NO");
    }

    return 0;
}