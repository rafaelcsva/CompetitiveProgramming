//27, 08, 2018, 13:44:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int BLOCK = 500;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < BLOCK ; i++){
        printf("9");
    }    

    printf("\n");

    for(int i = 0 ; i < BLOCK ; i++){
        printf("9");
    }
    
    for(int i = 0 ; i < BLOCK - 1 ; i++){
        printf("0");
    }

    printf("1\n");
    
    return 0;
}