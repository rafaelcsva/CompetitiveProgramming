#include <bits/stdc++.h>

using namespace std;

const int N = 400100;
int fat[N];

int comb(int n, int k){
    int r = 1;

    while(n || k){
        int ni = n % 3;
        int ki = k % 3;

        if(ni < ki){
            r = 0;
        }else{
            r = r * (fat[ni] * fat[ki] * fat[ni - ki]) % 3;
        }

        // printf("C(%d, %d) = %d\n", ni, ki, fat[ni] * fat[ki] * fat[ni - ki]);

        n /= 3;
        k /= 3;
    }

    return r;
}

int main(){
    
    fat[0] = 1;

    for(int i = 1 ; i < 3 ; i++){
        fat[i] = (i * fat[i - 1]) % 3;
    }

    int n;
    string s;

    cin >> n >> s;

    int sum = 0;

    char v[3] = {'W', 'R', 'B'};

    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'W'){
            continue;
        }else if(s[i] == 'R'){
            sum += comb(n - 1, i);
            // printf("C(%d, %d) %d\n", n - 1, i, comb(n - 1, i));
        }else{
            sum += 2 * comb(n - 1, i);
            // printf("C(%d, %d) %d\n", n - 1, i, comb(n - 1, i));
        }
        // printf("%d\n", sum);
        sum %= 3;
    }

    if((n & 1) == 0){
        sum = -sum;
    }

    sum = (sum % 3 + 3) % 3;

    cout << v[sum] << "\n";

    return 0;
}