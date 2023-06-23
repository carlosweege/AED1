/*Fac ̧a um programa que leia uma quantidade qualquer de n  ́umeros armazenando-os na
mem  ́oria e pare a leitura quando o usu  ́ario entrar um n  ́umero negativo. Em seguida,
imprima o vetor lido. Use a func ̧  ̃ao REALLOC*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *p = (int *)malloc( sizeof(int) );
    int num, count = 0;
    
    for(;;){
        printf("digite um numero: ");
        scanf("%d", &num);
        
        if ( num < 0 ){
            break;
        }
        
        p[count] = num;
        count++;
        
        p = (int *)realloc( p, (sizeof(int) + sizeof(p)) );
        
    }
    
    for( int i = 0; i < count; i++ ){
        
        printf("%d\n", p[i]);
    }
    
}