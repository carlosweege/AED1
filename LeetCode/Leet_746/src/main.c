#include <stdio.h>
#include <stdlib.h>

int minCostClimbingStairs(int* cost, int costSize);

int main(){

    int *arraySteps, numSteps, aux = 0;

    printf("Digite o numero de degraus: \n");
    scanf("%d" ,&numSteps);

    if ( numSteps <= 2 ){
        printf("Custo Minimo: 0\n");
        return 1;
    }


    arraySteps = (int *) malloc( numSteps * sizeof(int) );

    if ( arraySteps == NULL ){
        printf("falha para alocar o array!\n");
        return 1;
    }


    while ( aux != numSteps){
        printf("Digite o custo do degrau %d :", aux + 1);
        scanf(" %d", &arraySteps[aux]);
        aux++;
    }

    int result = minCostClimbingStairs( arraySteps, numSteps );
    printf("Custo Minimo: %d\n", result);

    free(arraySteps);

    return 0;
}

int minCostClimbingStairs(int* cost, int costSize){

    int totalCost0 = cost[0];
    int totalCost1 = cost[1];
    int i;

    for ( i = 0; i + 2 < costSize;){

        if ( cost[i+1] < cost[i+2] ){
            i++;
            totalCost0 += cost[i];
        } else{
            i += 2;
            totalCost0 += cost[i];
        }
    }
        
    totalCost0 += cost[i];

    for ( i = 1; i + 2 < costSize;){

        if ( cost[i+1] < cost[i+2] ){
            i++;
            totalCost1 += cost[i];
        } else{
            i += 2;
            totalCost1 += cost[i];
        }
    }

    totalCost1 += cost[i];

    if ( totalCost0 < totalCost1 )
        return totalCost0;
    else
        return totalCost1;
}
