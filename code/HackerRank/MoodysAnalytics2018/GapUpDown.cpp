//18, 08, 2018, 10:02:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
int low[N], high[N], close[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &low[i]);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &high[i]);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &close[i]);
    }

    int gap_up = 0, gap_down = 0;

    for(int i = 1 ; i < n ; i++){
        if(low[i] > close[i - 1]){
            gap_up++;
        }

        if(high[i] < close[i - 1]){
            gap_down++;
        }
    }

    printf("%d %d\n", gap_up, gap_down);
        
    return 0;
}