#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    if (argc != 4){
        puts("Reto: Dame tres números cuya suma < 90");
        puts("      Pero al menos uno de ellos debe ser > 90");
        printf("Uso: %s [num1] [num2] [num3]\n", argv[0]);
        return 1;
    }

    unsigned char t_c1 = atoi(argv[1]), t_c2 = atoi(argv[2]), t_c3 = atoi(argv[3]), t_total;
    t_total = t_c1+t_c2+t_c3;

    if (t_total < 90 && (t_c1 > 90 || t_c2 > 90 || t_c3 > 90))
        puts("Quinta y última pista: https://drive.google.com/file/d/1r0kgLQXht3VLsizOnJPb-8q5Xjb5-APL/view?usp=sharing");
    else puts("Ni modo, seguí intentando :(");
    return 0;
}
