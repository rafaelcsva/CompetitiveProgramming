//30, 11, 2018, 14:58:44 Rafaelcs cpp
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

    int sum = 0;

    for(int i = 1 ; i < n ; i++){
        sum += a[i] - a[i - 1] - 1;
    }

    printf("%d\n", sum);

    return 0;
}