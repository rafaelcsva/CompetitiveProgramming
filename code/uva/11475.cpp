//27, 07, 2018, 10:42:03 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

string t;
string p;
const int N = 1e5 + 100;
int n, m;
int b[N];

void KMP_preprocess(){
    int i = 0, j = -1;
    b[0] = -1;

    while(i < m){
        while(j >= 0 && p[j] != p[i]){
            j = b[j];
        }

        i++, j++;
        b[i] = j;
    }
}

int KMP_search(){
    int i = 0, j = 0;

    while(i < n){
        while(j >= 0 && p[j] != t[i]){
            j = b[j];
        }

        i++, j++;

        if(i == n){
            return j;
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> t){
        p = t;
        reverse(p.begin(), p.end());

        m = p.length();
        n = t.length();
        
        KMP_preprocess();
        
        int r = KMP_search();
        
        for(int i = 0 ; i < n ; i++){
            cout << t[i];
        }

        for(int i = r ; i < m ; i++){
            cout << p[i];
        }

        cout << endl;
    }   

    return 0;
}