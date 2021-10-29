#include <bits/stdc++.h>

using namespace std;

vector< int > phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i){
                if(j == 4){
                    printf("j: %d\n", j);
                }
                phi[j] -= phi[j] / i;
            }
        }
    }

    return phi;
}

int main(){
    auto v = phi_1_to_n(10);

    printf("%d\n", v[4]);

    return 0;
}