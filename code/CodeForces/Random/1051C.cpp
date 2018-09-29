//20, 09, 2018, 18:49:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110;
int cnt[N];
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int x;

        scanf("%d", &x);
        a[i] = x;

        cnt[x]++;
    }

    int un = 0;

    for(int i = 1 ; i < N ; i++){
        if(cnt[i] == 1){
            un++;
        }
    }

    if(un == 0){
        printf("YES\n");
        for(int i = 0 ; i < n ; i++){
            printf("A");
        }
        printf("\n");
    }else if(un & 1){
        int take = -1;

        for(int i = 1 ; i < N ; i++){
            if(cnt[i] > 2){
                take = i;
                break;
            }
        }

        if(take == -1){
            printf("NO\n");
        }else{
            printf("YES\n");

            char c = 'A';

            for(int i = 0 ; i < n ; i++){
                int x = a[i];

                if(cnt[x] == 1){
                    printf("%c", c);

                    if(c == 'A'){
                        c = 'B';
                    }else{
                        c = 'A';
                    }
                }else if(take == x){
                    printf("B");
                    take = -1;
                }else{
                    printf("A");
                }
            }

            printf("\n");
        }
    }else{
        printf("YES\n");

        char c = 'A';

        for(int i = 0 ; i < n ; i++){
            int x = a[i];

            if(cnt[x] == 1){
                printf("%c", c);

                if(c == 'A'){
                    c = 'B';
                }else{
                    c = 'A';
                }
            }else{
                printf("A");
            }
        }

        printf("\n");
    }

    return 0;
}