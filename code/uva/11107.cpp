//14, 08, 2018, 07:55:03 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500000                         // second approach: O(n log n)

typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1100, M = 1010, INC = 4;
char t[N][M];

char T[MAX_N];
int len[N], st[N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
char lcsans[N][M];
char P[MAX_N];
int m;
int indx[MAX_N];
int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];
int sz;
set< int > un;

bool comp(int a, int b){
    return strcmp(T + a, T + b) < 0;
}

void countingSort(int k){
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);

    for(i = 0 ; i < n ; i++){
        c[i + k < n ? RA[i + k] : 0]++;
    }

    for(i = sum = 0 ; i < maxi ; i++){
        int t = c[i];
        c[i] = sum;
        sum += t;
    }

    for(i = 0 ; i < n ; i++){
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    }

    for(i = 0 ; i < n ; i++){
        SA[i] = tempSA[i];
    }
}

void constructSA(){
    int i, k, r;

    for(i = 0 ; i < n ; i++){
        RA[i] = T[i];
    }
    for(i = 0 ; i < n ; i++){
        SA[i] = i;
    }
    for(k = 1 ; k < n ; k <<= 1){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for(i = 1 ; i < n ; i++){
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        }

        for(i = 0 ; i < n ; i++){
            RA[i] = tempRA[i];
        }

        if(RA[SA[n - 1]] == n - 1){
            break;
        }
    }
}

void computeLCP(){
    int i, L;
    Phi[SA[0]] = -1;

    for(i = 1 ; i < n ; i++){
        Phi[SA[i]] = SA[i - 1];
    }

    for(i = L = 0 ; i < n ; i++){
        if(Phi[i] == -1){
            PLCP[i] = 0;
            continue;
        }
        while(i + L < n && Phi[i] + L < n && T[i + L] == T[Phi[i] + L]){
            L++;
        }
        PLCP[i] = L;
        L = max(L - 1, 0);
    }

    for(i = 0 ; i < n ; i++){
        LCP[i] = PLCP[SA[i]];
    }
}

int owner(int idx){
    return indx[idx];
}

void LCS(vector< int > &idx){
    int i, maxLCP = -1;
    
    int best = 0;
    int bt = 1e9, en = -1;

    for(i = 1 ; i < n ; i++){
        int tmp = 1e9;

        for(int j = i ; j < n ; j++){
            un.insert(owner(SA[j - 1]));
            un.insert(owner(SA[j]));
            tmp = min(tmp, LCP[j]);

            if(tmp <= best){
                break;
            }
            
            if(un.size() >= (sz / 2) + 1){
                if(best < tmp){
                    best = tmp;
                }
            }        
        }

        un.clear();
    }
    printf("sai aqui Oh\n");
    idx.push_back(best);
    
    for(i = 1 ; i < n ; i++){
        bt = 1e9, en = -1;
        int tmp = 1e9;
        
        for(int j = i ; j < n ; j++){
            un.insert(owner(SA[j - 1]));
            un.insert(owner(SA[j]));
            tmp = min(tmp, LCP[j]);

            if(tmp < best){
                break;
            }

            if(un.size() >= (sz / 2) + 1){
                if(tmp == best){
                    bt = i;
                    en = j;
                }
            }        
        }

        for(int k = bt ; k <= en ; k++){
            idx.push_back(k);
        }

        un.clear();
    }
}

int mcompar(const void *a, const void *b){
    char *f = (char * )a, *d = (char *) b;

    return strcmp(f, d);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector< int > r;
    bool print = false;

    while(scanf("%d", &sz) != EOF){
        if(sz == 0){
            break;
        }

        if(print){
            printf("\n");
        }

        print = true;

        n = 0;
        T[0] = 0;
        
        char term = '$';
        
        for(int i = 0 ; i < sz ; i++){
            scanf("\n%s", t[i]);

            len[i] = strlen(t[i]);
            st[i] = n;
            n += len[i];
            // printf("LOG: %d %d %s\n", len[i], n, t[i]);
            for(int j = 0 ; j < len[i] ; j++){
                t[i][j] += INC;
                indx[st[i] + j] = i;
            }

            strcat(T, t[i]);
            
            indx[n] = i;
            T[n++] = term;
            T[n] = 0;
            term--;
        }

        if(sz == 1){
            for(int i = 0 ; i < len[0] ; i++){
                t[0][i] -= INC;
            }

            printf("%s\n", t[0]);
            continue;
        }
        // printf("n = %d\n", n);
        // printf("entrei\n");
        constructSA();
        
        computeLCP();
        // printf("sai0\n");
        // fflush(stdout);
        // printf("entrando dnv\n");
        LCS(r);
        // printf("sai\n");
        

        int len = r[0];
        // lcsans = (char **) malloc(sizeof(char *) * r.size());
        // for(int i = 0 ; i < r.size() ; i++){
        //     lcsans[i] = (char *) malloc(sizeof(char) * (len + 3));
        // }
        // printf("len = %d %s %d encontramos %lu substrings\n", len, T, n, r.size());
        // printf("\nThe LCP information of 'T+P' = '%s':\n", T);
        // printf("i\tSA[i]\tLCP[i]\tOwner\tSuffix\n");
        // for (int i = 0; i < n; i++)
        //     printf("%2d\t%2d\t%2d\t%2d\t%s\n", i, SA[i], LCP[i], owner(SA[i]), T + SA[i]);
        
        if(len != 0){
            for(int i = 0; i < int(r.size()) - 1 ; i++){
                strncpy(lcsans[i], T + SA[r[i + 1]], len);
                // lcsans[i][len] = 0;
                // printf("%s se torna ", lcsans[i]);
                for(int j = 0 ; j < len ; j++){
                    lcsans[i][j] -= INC;
                }
                // printf("%s\n", lcsans[i]);
                lcsans[i][len] = 0;
            }

            qsort(lcsans, int(r.size()) - 1, sizeof(lcsans[0]), mcompar);

            for(int i = 0 ; i < int(r.size()) - 1 ; i++){
                if(i && strcmp(lcsans[i], lcsans[i - 1]) == 0){
                    // printf("continuado\n");
                    continue;
                }

                printf("%s\n", lcsans[i]);
            }
        }else{
            printf("?\n");
        }

        r.clear();
    }

    return 0;
}