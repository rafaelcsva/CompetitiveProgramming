//21, 09, 2018, 11:37:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    if(n % 3 == 0){
        printf("1 1 %d\n", n - 2);
    }else{
        printf("1 2 %d\n", n - 3);
    }
    
    return 0;
}