#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void toUp(char *str){
    for(int i = 0; str[i]!='\0';i++)
        *(str+i) = toupper(*(str+i));
}

void razvorot(char *result){
    char tmp;
    for(int i = 0; i < strlen(result)/2; i++){
        tmp = result[i];
        result[i] = result[strlen(result) - i - 1];
        result[strlen(result) - i - 1] = tmp;
    }

}
void proverkab1 (char *chislo, int b1){
    int cnt = 0;
        for(int i = 0; i < strlen(chislo); i++)
            if(((int)chislo[i] > (int)'0' && (int)chislo[i] <= (int)((b1 - 1) + '0')) || chislo[i] == '.' || (((int)chislo[i] - (int)'0' - b1 - 7 < 0)))
                cnt++;

    if (cnt != strlen(chislo))
        printf("bad input");
}


double To10(char*chislo, int b1){
    int tochka = strlen(chislo);
    double sum = 0;
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

void From10(double chislo, int b2) {
    char *result;
    int resultSize = 0;
    result = (char*) malloc(sizeof(char));
    result[0]='\0';
    long long int intPart =(long long int)chislo;
    double floatPart = chislo - intPart;
    printf("%lld %f\n",intPart,floatPart);

    while(intPart > 0){
        result[resultSize] = ('0' + (intPart % b2));
        result[resultSize+1] = '\0';
        intPart /= b2;
        resultSize++;
        result =(char*)realloc(result,resultSize * sizeof(char));
    }
    printf("%s %d\n",result,15%16);
    razvorot(result);

    if (floatPart>0){
        result[resultSize]= '.';
        resultSize++;
        result =(char*)realloc(result,resultSize * sizeof(char));


        while(floatPart != 0){
            result[resultSize] = '0' + ((int)(floatPart * b2));
            result[resultSize+1] = '\0';
            floatPart = (floatPart * b2)-(int)(floatPart * b2);
            //printf("%s %f\n",result,floatPart);
            resultSize++;
            result =(char*)realloc(result,resultSize * sizeof(char));
        }
    }
    printf("%s",result);
}

int main(){
    int b1, b2;
    char chislo[13];
    scanf("%d %d",&b1, &b2);
   if(b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16){
        printf("bad input");
        return 0;
    }
    scanf("%s",&chislo);
    toUp(chislo);
    proverkab1(chislo,b1);
    double decimal = To10(chislo,b1);
    printf("%f\n",decimal);
    From10(decimal, b2);

    return 0;

}