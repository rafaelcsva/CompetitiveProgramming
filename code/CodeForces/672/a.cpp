#include <bits/stdc++.h>

using namespace std;

const int N = int(5e5);
int a[N], b[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }

        sort(b, b + n, greater< int > ());

        bool ver = true;

        for(int i = 0 ; i < n ; i++){
            if(b[i] != a[i]){
                ver = false;
                break;
            }

            if(i && b[i] == b[i - 1]){
                ver = false;
                break;
            }
        }

        if(ver){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}