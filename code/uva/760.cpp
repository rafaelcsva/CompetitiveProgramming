//13, 08, 2018, 19:55:15 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define MAX_N 5000                         // second approach: O(n log n)
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
char lcsans[MAX_N][450];
char P[MAX_N];
int m;

int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];

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
        while(T[i + L] == T[Phi[i] + L]){
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
    return (idx < n - m - 1 ? 1 : 2);
}

void LCS(vector< int > &idx){
    int i, maxLCP = -1;

    for(i = 1 ; i < n ; i++){
        if(owner(SA[i]) != owner(SA[i - 1]) && LCP[i] > maxLCP){
            maxLCP = LCP[i];
        }
    }

    for(i = 1 ; i < n ; i++){
        if(owner(SA[i]) != owner(SA[i - 1]) && LCP[i] == maxLCP){
            idx.push_back(i);
        }
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
    
    while(scanf("\n%s", T) != EOF){
        scanf("\n%s", P);
        // printf("%s\n", P);
        if(print){
            printf("\n");
        }
        print = true;
        
        strcat(T, "$");
        
        m = strlen(P);
        strcat(T, P);
        strcat(T, "#");
        
        n = strlen(T);

        constructSA();
        computeLCP();
        
        LCS(r);
        int len = LCP[r[0]];

        if(len != 0){
            for(int i = 0 ; i < r.size() ; i++){
                strncpy(lcsans[i], T + SA[r[i]], len);
                lcsans[i][len] = '\0'; 
            }

            qsort(lcsans, r.size(), sizeof(lcsans[0]), mcompar);

            for(int i = 0 ; i < r.size() ; i++){
                if(i && strcmp(lcsans[i], lcsans[i - 1]) == 0){
                    continue;
                }
                
                printf("%s\n", lcsans[i]);
            }
        }else{
            printf("No common sequence.\n");
        }

        r.clear();
    }

    return 0;
}