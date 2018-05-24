//13, 05, 2018, 06:05:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

map<int, int>mp;
vector<int>v;
int a[100000];

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){

        cin >> a[i];
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        int x = a[i];

        if(mp[x] == 0){
            v.push_back(x);
            mp[x] = 1;
        }
    }

    cout << v.size() << endl;

    for(int i = v.size() - 1 ; i >= 0 ; i--){
        char c = i == 0 ? '\n' : ' ';

        cout << v[i] << c;
    }


    return 0;
}