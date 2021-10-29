#include <bits/stdc++.h>

using namespace std;

vector< int > v;

int main(){
    int t;

    int num = 1;

    while(v.size() != 1000){
        if(num % 3 == 0 || num % 10 == 3){
            num++;
            continue;
        }

        v.push_back(num);
        num++;
    }

    scanf("%d", &t);

    while(t--){
        int ki;

        scanf("%d", &ki);

        printf("%d\n", v[ki - 1]);
    }

    return 0;
}