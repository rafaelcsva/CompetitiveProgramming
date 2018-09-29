//19, 07, 2018, 10:48:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    char op;

    int ac = 0;

    while(scanf("\n%d%c%d", &a, &op, &b) != EOF){
        char num[4];

        scanf("\n=%s", num);

        if(num[0] != '?'){
            int r = atoi(num);
            
            if(op == '-'){
                if(a - b == r){
                    ac++;
                }
            }else{
                if(a + b == r){
                    ac++;
                }
            }
        }
    }

    printf("%d\n", ac);

    return 0;
}