//11, 06, 2018, 21:30:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 40;
ll c[N][N];
ll v[] = {4, 2, 4, 3, 3, 4};//red red, blue blue, green green, red blue, green blue, red green

void pascal(){
    for(int i = 0 ; i < N ; i++){
        c[i][0] = c[i][i] = 1LL;

        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

}

int main(){
    pascal();

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        
        scanf("%d", &n);

        ll total = 0LL;
        
        for(int blue = 0 ; blue <= n ; blue++){
            for(int red = 0 ; red <= n / 2 ; red++){
                for(int green = 0 ; green <= n / 2 ; green++){
                    if(2 * red + 2 * green + blue == n){
                        total ++;
                    }
                }
            }
        }
        

        cout << total << endl;
    }

    return 0;
}