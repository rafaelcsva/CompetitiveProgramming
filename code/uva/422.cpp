//30, 07, 2018, 14:04:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 200;
char t[N][N];
char s[N];
int n, m;
int b[N];

bool ok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < n;
}

void KMP_preprocess(){
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m){
        while(j >= 0 && s[i] != s[j]){
            j = b[j];
        }

        j++, i++;
        b[i] = j;
    }
}

bool KMP_search(int i, int j, pii add){
    int l = 0;
    int ki = i, kj = j;
    
    while(ok(i, j)){
        while(l >= 0 && s[l] != t[i][j]){
            l = b[l];
        }

        l++;
        
        if(l == m){
            printf("%d,%d %d,%d\n", (i + 1) - (m - 1) * add.first, (j + 1) - (m - 1) * add.second, i + 1, j + 1);
            return true;
        }

        i += add.first;
        j += add.second;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("\n%c", &t[i][j]);
            t[i][j] |= 32;
        }
    }

    while(true){
        scanf("\n%s", s);

        if(strcmp(s, "0") == 0){
            break;
        }

        bool finded = false;
        m = strlen(s);

        KMP_preprocess();

        for(int addi = -1 ; addi <= 1 ; addi++){
            for(int addj = -1 ; addj <= 1; addj++){
                if(addi == 0 && addj == 0)
                    continue;

                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(KMP_search(i, j, {addi, addj})){
                            finded = true;
                            break;
                        }
                    }

                    if(finded)
                        break;
                }

                if(finded)
                    break;
            }

            if(finded)
                break;
        }

        if(!finded){
            printf("Not found\n");
        }
    }

    return 0;
}