//25, 04, 2018, 07:16:50 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, int> pii;
const int N = int(1e6 + 100);
int v[N];
char s[N];

int main(){

    scanf("%s", s);

    int start = 0, end = strlen(s) - 1u;

    for(int i = 0 ; i < strlen(s) ; i++){
        if(s[i] == 'l'){
            v[end--] = i + 1;
        }else{
            v[start++] = i + 1;
        }
    }

    for(int i = 0 ; i < strlen(s) ; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}