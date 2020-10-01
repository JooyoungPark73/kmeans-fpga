#include "common.h"

/*
 initiates arrays before kmeans procedure
 1. fills up object[][]
 2. returns center[], which contains center value
*/

float** kmeans_init(float** object, int nObject, int nDimension, int nCenter){

    float** center = (float**)malloc(sizeof(float*) * nCenter); /* allocate center array */
    for(int i = 0; i < nObject; i++)
        center[i] = (float*)malloc(sizeof(float) * nDimension);

    std::srand((unsigned int)std::time(0));
    int* random_center = (int*)malloc(sizeof(int)* nCenter);

    for(int i=0; i<nCenter; i++){
        random_center[i] = rand()%nObject;
        for(int i_sub=0; i_sub<i; i_sub++){
            if(random_center[i] == random_center[i_sub]){
                i--;
                break;
            }
        }
    }

    std::cout << "celected random centers are: " << std::endl;
    for(int i=0; i<nCenter; i++){
        std::cout << random_center[i]<< ":  " ;
        for(int j=1; j<nDimension+1; j++) {
            center[i][j] = object[random_center[i]][j];
            std::cout << center[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    return center;
}