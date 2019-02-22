//26, 10, 2018, 13:01:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int vi[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int vj[] = {-2, 2, -2, 2, 1, -1, 1, -1};
int vki[] = {0, 0, 1, -1};
int vkj[] = {1, -1, 0, 0};
map< pii , bool > marked;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            int xi, yi;

            scanf("%d %d", &xi, &yi);

            for(int k = 0 ; k < 8 ; k++){
                int xn = xi + vi[k], yn = yi + vj[k];

                marked[{xn, yn}] = true;
            }
        }

        int x, y;

        scanf("%d %d", &x, &y);

        bool ok = false;

        for(int i = 0 ; i < 4 ; i++){
            int xn = x + vki[i];
            int yn = y + vkj[i];

            if(!marked[{xn, yn}]){
                ok = true;
                break;
            }
        }

        if(!ok){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

        marked.clear();
    }

    return 0;
}