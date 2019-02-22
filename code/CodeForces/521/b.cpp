//16, 11, 2018, 13:34:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    int cnt = 0;

    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1){
            cnt++;
            a[i - 1] = a[i + 1] = 0;
        }
    }

    printf("%d\n", cnt);

    return 0;
}