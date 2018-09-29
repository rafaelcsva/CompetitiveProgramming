//27, 07, 2018, 13:39:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 110;
string word[N];
int b[N];

void KMP_preprocess(string &p){
    int n = p.length();
    int i = 0, j = -1;
    b[0] = -1;

    while(i < n){
        while(j >= 0 && p[i] != p[j]){
            j = b[j];
        }

        j++, i++;
        b[i] = j;
    }
}

int KMP_search(string &t, string &p){
    int i = 0, j = 0;
    int n = t.length();
    int m = p.length();

    while(i < n){
        while(j >= 0 && p[j] != t[i]){
            j = b[j];
        }

        i++, j++;

        if(i == n){
            return j;
        }

        if(j == m){
            j = b[j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int k, w;

        cin >> k >> w;

        for(int i = 0 ; i < w ; i++){
            cin >> word[i];
        }

        int sz = word[0].length();
        string t = word[0];

        for(int i = 1 ; i < w ; i++){
            KMP_preprocess(word[i]);
            int r = KMP_search(t, word[i]);

            if(r != k){
                t += word[i].substr(r, k - r);
            }
        }

        cout << t.length() << endl;
    }

    return 0;
}