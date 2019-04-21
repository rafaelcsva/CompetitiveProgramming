//22, 02, 2019, 19:51:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e4 + 10);
char s[N], s1[N], s2[N], s3[N];
char r1[N], r2[N], r3[N];
int mp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%s", s);

    int n = strlen(s);
    int i = 0;

    for(char a = 'a' ; a <= 'z' && i != n ; a++){
        for(char b = 'a' ; b <= 'z' && i != n; b++){
            for(char c = 'a' ; c <= 'z' && i != n ; c++){
                s1[i] = a;
                s2[i] = b;
                s3[i] = c;

                i++;
            }
        }
    }

    s1[n] = s2[n] = s3[n] = 0;

    printf("? %s\n", s1);
    fflush(stdout);

    scanf("\n%s", r1);

    printf("? %s\n", s2);
    fflush(stdout);

    scanf("\n%s", r2);

    printf("? %s\n", s3);
    fflush(stdout);

    scanf("\n%s", r3);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(s1[i] == r1[j] && s2[i] == r2[j] && s3[i] == r3[j]){
                mp[i] = j;

                // printf("%d->%d\n", j, i);
                break;
            }
        }
    }    

    printf("! ");

    for(int i = 0 ; i < n ; i++){
        printf("%c", s[mp[i]]);
    }

    printf("\n");

    fflush(stdout);

    return 0;
}