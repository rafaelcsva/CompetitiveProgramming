//01, 08, 2018, 10:53:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 100;
char s[N], t[N];
int dp[N][N];

typedef struct{
    char comm[N];
    int pos;
    char d;
}Command;

vector< Command > operations;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool print = false;

    char tmp;

    while(scanf("%[^\n]s", s) != EOF){
        scanf("%c", &tmp);
        scanf("%[^\n]s", t);
        scanf("%c", &tmp);

        if(print){
            printf("\n");
        }    
        print = true;
        
        int n = strlen(t);
        int m = strlen(s);
        
        for(int j = 1 ; j <= n ; j++){
            dp[0][j] = 1 + dp[0][j - 1];
        }

        for(int i = 1 ; i <= m ; i++){
            dp[i][0] = dp[i - 1][0] + 1;
        }

        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                int cost = s[i - 1] != t[j - 1];

                dp[i][j] = min({dp[i - 1][j - 1] + cost, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }

        int i = m, j = n;

        while(max(i, j) >= 1){
            int cost = s[i - 1] != t[j - 1];
            Command d;
            
            if(i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + cost){
                if(cost){
                    strcpy(d.comm, "Replace");
                    d.pos = j;
                    d.d = t[j - 1];
                    
                    operations.push_back(d);
                }

                i = i - 1;
                j = j - 1;
            }else if(i > 0 && dp[i][j] == dp[i - 1][j] + 1){
                strcpy(d.comm, "Delete");
                d.pos = j + 1;

                operations.push_back(d);
                i = i - 1;
            }else{//dp[i][j] == dp[i][j - 1] + 1
                strcpy(d.comm, "Insert");
                d.pos = j;
                d.d = t[j - 1];

                operations.push_back(d);

                j = j - 1;
            }
        }
        
        reverse(operations.begin(), operations.end());

        printf("%lu\n", operations.size());

        for(int i = 0 ; i < operations.size() ; i++){
            printf("%d %s %d", i + 1, operations[i].comm, operations[i].pos);

            if(strcmp(operations[i].comm, "Delete") != 0){
                printf(",%c", operations[i].d);
            }
            
            printf("\n");
        }

        operations.clear();
        memset(t, 0, sizeof t);
        memset(s, 0, sizeof s);
    }

    return 0;
}