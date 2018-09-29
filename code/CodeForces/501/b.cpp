//31, 07, 2018, 12:43:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 100;
char s[N], t[N];
vector< int > swaps;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    scanf("\n%s", s);
    scanf("\n%s", t);

    for(int i = 0 ; i < n ; i++){
        if(s[i] != t[i]){
            bool find = false;

            for(int j = i ; j < n - 1 ; j++){
                if(s[j + 1] == t[i]){
                    find = true;

                    while(j >= i){
                        swaps.push_back(j + 1);
                        swap(s[j], s[j + 1]);
                        j--;
                    }

                    break;
                }
            }

            if(!find){
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%lu\n", swaps.size());

    for(int u: swaps){
        printf("%d ", u);
    }

    printf("\n");
    

    return 0;
}