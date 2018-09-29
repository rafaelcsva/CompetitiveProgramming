//03, 09, 2018, 19:07:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5);
vector< int > question;
bool asked[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 2 ; i <= n ; i++){
        for(int j = 2 ; j <= i ; j++){
            if(i % j == 0){
                if(!asked[j]){
                    question.push_back(j);
                    asked[j] = true;
                }
            }
        }
    }

    printf("%lu\n", question.size());
    for(int i = 0 ; i < question.size() ; i++){
        printf("%d ", question[i]);
    }
    printf("\n");

    return 0;
}