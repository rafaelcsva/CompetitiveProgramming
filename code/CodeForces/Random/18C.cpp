//29, 04, 2018, 07:15:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(1e5 + 100);
int a[N];

int main(){
    int n;

    cin >> n;

    int tot = 0;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        tot += a[i];
        a[i] += a[i - 1];    
    }

    if(tot % 2 == 0){
        tot /= 2;
        int cnt = 0;

        for(int i = 1 ; i <= n - 1 ; i++){
            if(a[i] == tot){
                cnt++;
            }
        }

        cout << cnt << endl;
    }else{
        cout << "0" << endl;
    }

    return 0;
}