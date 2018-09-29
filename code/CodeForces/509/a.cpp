//16, 09, 2018, 07:36:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    
    int tot = 0;

    for(int i = 1 ; i < n ; i++){
        tot += a[i] - a[i - 1] - 1;
    }

    printf("%d\n", tot);
    
    return 0;
}