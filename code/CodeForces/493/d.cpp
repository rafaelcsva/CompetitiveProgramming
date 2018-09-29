//01, 07, 2018, 12:02:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int cnt = 0;
set<int>st;
int v[] = {1, 5, 10, 50};
int n;

void gen(int s, int d){
    
    if(d == n){
        st.insert(s);
        return;
    }

    for(int i = 0 ; i < 4;  i++){
        gen(s + v[i], d + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n;

    gen(0, 0);

    cout << st.size() << endl;

    return 0;
}