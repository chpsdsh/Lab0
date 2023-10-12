#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void toUp(char *str){
    for(int i = 0; str[i]!='\0';i++)
        *(str+i) = toupper(*(str+i));
}


void proverkab1 (char *chislo, int b1){
    int cnt = 0;
        for(int i = 0; i < strlen(chislo); i++)
            if(((int)chislo[i] > (int)'0' && (int)chislo[i] <= (int)((b1 - 1) + '0')) || chislo[i] == '.' || (((int)chislo[i] - (int)'0' - b1 - 7 < 0)))
                cnt++;

    if (cnt != strlen(chislo))
        printf("bad input");
}


float To10(char*chislo, int b1){
    int tochka = strlen(chislo);
    float sum = 0;
    for(int i = 0; i<strlen(chislo); i++)
        if (chislo[i] == '.')
            tochka = i;
    for(int i = tochka - 1, pok = 0; i >= 0; i--,pok++){
        if ((int)chislo[i]>=(int)'0' && (int)chislo[i]<=(int)'9')
            sum += ((int)chislo[i] - (int)'0') * pow(b1,pok);
        else
            sum += ((int)chislo[i] - (int)'0' - 7) * pow(b1,pok);
    }
    for(int i = tochka + 1, pok = -1; i < strlen(chislo); i++,pok--) {
        if ((int) chislo[i] >= (int) '0' && (int) chislo[i] <= (int) '9')
            sum += ((int) chislo[i] - (int) '0') * pow(b1, pok);
        else
            sum += ((int) chislo[i] - (int) '0' - 7) * pow(b1, pok);
    }
    return sum;
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
    toUp(chislo);
    proverkab1(chislo,b1);
    printf("%f", To10(chislo,b1));

    return 0;

}