//20, 07, 2018, 13:34:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 110;
int a[N], b[N];
map<int, bool>mp;
int n;

bool can_insert(int number){
    for(int i = 0; i < n ; i++){
        if(!mp[number + a[i]]){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    int m;

    cin >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> b[i];

        mp[b[i]] = true;
    }

    set<int>st;

    for(int number = 1 ; number <= 100 ; number++){
        if(can_insert(number)){
            st.insert(number);
        }
    }

    for(set<int>::iterator it = st.begin() ; it != st.end() ; it++){
        cout << *it << ' ' ;
    }

    cout << endl;

    return 0;
}