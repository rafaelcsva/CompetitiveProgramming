#include <stdio.h>

int main(){
    for(int i = 0 ; i < 200000 ; i++){
        printf("%d", i % 2);
    }
}