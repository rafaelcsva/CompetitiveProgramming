//23, 11, 2018, 10:32:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
int z[N];
vector< int > b;
int f = 1;
vector< int > s;

vector<int> prefix_function(vector< int > s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// void presfix_function(vector< int > s){
//     int m = s.size(); 
//     int j = -1, i = 0;
//     b[0] = j;

//     while(i < m){
//         while(j >= 0 && s[i] != s[j]) j = b[j];
//         i++, j++;
//         b[i] = j;
//     }
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &z[i]);
    }

    s.push_back(f);
    f++;

    for(int i = 1 ; i < n ; i++){
        if(z[i] == 0 && s.size() < i + 1){
            s.push_back(f++);
        }else{
            // if(i == n - 1){
            //     printf("aqui %d %d %d\n", i, z[i], s.size());
            // }
            for(int j = int(s.size()) - i ; j < z[i] ; j++){
                s.push_back(s[j]);
            }
        }
    }

    // prefix_function(s);
    b = prefix_function(s);

    // printf("meu tam eh %lu\n", s.size());
    // for(int i = 0 ; i < s.size() ; i++){
    //     printf("%d ", s[i]);
    // }
    // printf("\n");

    for(int i = 0 ; i < n ; i++){
        char c = i == (n - 1) ? '\n' : ' ';
        printf("%d%c", b[i], c);
    }

    return 0;
}