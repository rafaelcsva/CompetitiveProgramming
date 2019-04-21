//13, 04, 2019, 09:31:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    int mx = 0;
    int see = 0;

    for(int i = 0 ; i < n ; i++){
        if(a[i] >= mx){
            see++;
            mx = a[i];
        }
    }

    cout << see << endl;
    
    return 0;
}