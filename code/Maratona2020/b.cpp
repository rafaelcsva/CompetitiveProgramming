#include <bits/stdc++.h>

using namespace std;

int cnt[100][100];

int main(){
    int n;

    scanf("%d", &n);

    bool ok = true;

    for(int i = 0 ; i < n ; i++){
        int d, l, r, c;

        scanf("%d %d %d %d", &d, &l, &r, &c);

        if(d){
            while(l){
                if(r > 10 || c > 10){
                    ok = false;
                    break;
                }

                if(cnt[r][c] > 0){
                    ok = false;
                    break;
                }

                cnt[r][c]++;
                r++;
                l--;
            }
        }else{
            while(l){
                if(r > 10 || c > 10){
                    ok = false;
                    break;
                }

                if(cnt[r][c] > 0){
                    ok = false;
                    break;
                }

                cnt[r][c]++;
                c++;
                l--;
            }
        }

        if(!ok){
            break;
        }
    }

    if(ok){
        printf("Y\n");
    }else{
        printf("N\n");
    }

    return 0;
}