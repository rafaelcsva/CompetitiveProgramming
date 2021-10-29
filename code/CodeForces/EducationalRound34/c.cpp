#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
bool mark[N];
int a[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int last = -1;
    int box = 0;

    for(int i = 0 ; i < n ; i++){
        last = -1;

        for(int j = 0 ; j < n ; j++){
            if(mark[j]) continue;

            if(last == -1 || a[j] > a[last]){
                mark[j] = true;
                
                // printf("%d->%d\n", last, j);
                last = j;
            }
        }

        if(last == -1){
            break;
        }

        box++;
    }

    printf("%d\n", box);

    return 0;
}