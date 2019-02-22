//23, 11, 2018, 11:49:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
int f = 1;
vector< int > s;
int pi[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &pi[i]);
    }

    s.push_back(f);
    f++;

    for(int i = 1 ; i < n ; i++){
        if(pi[i]){
            s.push_back(pi[i] - 1);
        }else{
            s.push_back(f++);
        }
    }

    
    
    return 0;
}