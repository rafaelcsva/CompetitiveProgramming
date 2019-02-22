#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
int n;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        if(i){
            if(a[i] <= a[i - 1]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    int b;

    scanf("%d", &b);

    for(int i = 1 ; i < n ; i++){
        int r = b % a[i];

        if(r == 0 || a[i - 1] % r != 0){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    
    return 0;
}