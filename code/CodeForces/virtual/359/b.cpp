//09, 08, 2018, 11:12:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 110;
int b[N], a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &b[i]);
        a[i] = b[i];
    }

    sort(a, a + n);

    for(int i = 0 ; i < n ; i++){
        if(b[i] != a[i]){
            for(int j = i + 1 ; j < n ; j++){
                if(b[j] == a[i]){
                    int t = j;

                    while(t != i){
                        swap(b[t], b[t - 1]);
                        printf("%d %d\n", t, t + 1);
                        
                        t--;
                    }

                    break;
                }
            }
        }
    }

    return 0;
}