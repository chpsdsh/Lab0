#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void proverkab1 (char *chislo, int b1){
    int cnt = 0;
        for(int i = 0; i < strlen(chislo); i++)
            if(((int)chislo[i] > (int)'0' && (int)chislo[i] <= (int)((b1 - 1) + '0')) || chislo[i] == '.' || (((int)chislo[i] - (int)'0' - b1 - 7 < 0)))
                cnt++;

    if (cnt != strlen(chislo))
        printf("bad input");
}

int splitsum(char*chislo){
    int tochka;
    float sum;
    for(int i = 0; i<strlen(chislo); i++)
        if (chislo[i] == '.')
            tochka = i;

}
int main(){
    int b1, b2;
    char chislo[13];
    scanf("%d %d\n",&b1, &b2);
    scanf("%s",&chislo);
    if(b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16){
        printf("bad input");
        return 0;
    }
    proverkab1(chislo,b1);


    return 0;

}