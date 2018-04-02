#include <stdio.h>

int main(){
    int N[20];

    printf("#include <stdio.h>\n\n");

    printf("int main{\n");
    printf("    int N[1000];\n\n");
    
    for(int i = 19 ; i >= 0 ; i--){
        printf("    scanf(\"%%d\", &N[%d]);\n", i);
    }

    for(int i = 0 ; i < 20 ; i++){
        printf("    printf(\"%%d\\n\", N[%d]);\n", i);
    }

    printf("\n    return 0;\n");
    printf("}\n");
}