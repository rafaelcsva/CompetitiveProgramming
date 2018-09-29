//18, 08, 2018, 09:05:48 Rafaelcs cpp
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

    int have = 0;
    
    for(int i = 1 ; i <= n ; i+=2){
        int cnt = 0;

        for(int j = 1 ; j <= i ; j++){
            if(i % j == 0){
                cnt++;
            }
        }

        if(cnt == 8){
            have++;
        }
    }

    printf("%d\n", have);

    return 0;
}