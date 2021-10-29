#include <bits/stdc++.h>

using namespace std;

vector< pair< int, int > > v;

const int N = int(3e5) + 10;
int a[N];
bool ver[50];

int main(){
    int n, q;

    scanf("%d %d", &n, &q);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    for(int j = 0 ; j < q ; j++){
        int ai;

        scanf("%d", &ai);

        int pos = 0;

        for(int i = 0 ; i < n ; i++){
            if(a[i] == ai){
                pos = i;
                break;
            }
        }

        rotate(a, a + pos, a + pos + 1);

        // for(int i = 0 ; i < n ; i++){
        //     printf("%d ", a[i]);
        // }
        printf("%d ", pos + 1);
    }
    printf("\n");

    return 0;
}