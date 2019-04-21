//23, 02, 2019, 07:51:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 200;
int a[N];
vector< int > v1, v2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int i = 0;

    while(v1.size() != (n + 1) / 2){
        v1.push_back(a[i]);

        i += 2;
    }

    if(n & 1){
        i = n - 2;
    }else{
        i = n - 1;
    }

    while(v1.size() != n){
        v1.push_back(a[i]);
        i -= 2;
    }

    for(int i = 0 ; i < n ; i++){
        cout << v1[i] << " ";
    }

    cout << endl;

    return 0;
}