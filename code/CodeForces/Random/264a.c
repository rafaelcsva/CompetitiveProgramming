#include <stdio.h>
#include <string.h>

int N = (int)1e6 + 100;
int v[1000010];
char s[1000010];
int start, end, i, n;

int main(){

    scanf("%s", s);

    n = strlen(s);
    
    start = 0, end = n - 1u;

    for(i = 0 ; i < n ; i++){
        while(end < 0 || start >= n){
            printf("asdfas\n");
        }

        if(s[i] == 'l'){
            v[end--] = i + 1;
        }else{
            v[start++] = i + 1;
        }
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}