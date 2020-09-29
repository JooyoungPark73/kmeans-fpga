#include "common.h"

// Find out where MAX_ITERATION_VALUE is defined!
#define MAX_ITERATION_VALUE 300

float euclid_dist_2(float* coord_obj, float* coord_center){
    float dist = 0;
    assert(coord_obj != NULL && coord_center != NULL);
    for(int i=0; i<nDimension; i++)
        dist += (coord_obj[i+1] - coord_center[i]) * (coord_obj[i+1] - coord_center[i]);

    return dist;
}

void find_closest_center(float** object, float** center, float** newCenter, int* newCenterSize, int* changeObjects){
    /*
        This function consists [step 3] ~ [step 4].
    */
    int min;

    /* [step 3] Calculate distance and store that to "c". */
    for(int i=0; i<nObject; i++){   //  Fill object array distance part
        for(int j=0; j<nCenter; j++)
            object[i][nDimension+1+j] = euclid_dist_2(object[i], center[j]);
    }

    /* [step 4] Find Closest Cluster. */
    for(int i=0; i<nObject; i++){ 
        min=0;
        for(int j=0; j<nCenter; j++){
            if( object[i][nDimension+1+min] > object[i][nDimension+1+j] ) min = j;
        }
        /* [step 4-1] Update new cluster centers. */
        newCenterSize[min]++;
        for (int j=0; j<nCenter; j++)
            newCenter[min][j] += object[i][j];
        /*  [step 4-2]
                Use the previous value to check the change of objects[i][0].
                Then, place number of smallest value at center_number (object[i][0])   */
        if (object[i][0] != object[i][nDimension+1+min]) changeObjects[i] += 1;
        object[i][0] = object[i][nDimension+1+min];
    }
}

void kmeans(float** object, float** cluster){
    /*
        This function consists [step 3] ~ [step 7]!
    */

    int i, j;
    int loop = 0;       // To check iteration times!
    int changeCluster;  // Changed == n, Not changed == 0!

    /*
        To check the change of value of centers!
        Initialization the array!
    */
    int* changeObjects = (int*) malloc(sizeof(int) * nObject);
    for (i=0; i<nObject; i++)
        changeObjects[i] = 0;

    /*
        New cluster center.
        If you want to change value of cluster, use this array (Used on line 85).
    */
    int* newCenterSize = (int*) malloc(sizeof(int) * nCenter);
    float** newCenter = (float**) malloc(sizeof(float*) * nCenter);
    for(int i = 0; i < nObject; i++)
        newCenter[i] = (float*)malloc(sizeof(float) * nDimension);

    /* [step 3] ~ [step 7] */
    do
    {
        /*
            [step 3] ~ [step 4]
            [step 3] calculate euclid distance btw objects and store at "C".
            [step 4] place number of smallest value at "a".
        */
        find_closest_center(object, cluster, newCenter, newCenterSize, changeObjects);
        /*
            [step 5] to go through all objects and calculate new center.
            Average the sum and replace old cluster centers with newClusters.
        */
        for (i=0; i<nCenter; i++) {
            for (j=0; j<nDimension; j++) {
                if (newCenterSize[i] > 1)
                    cluster[i][j] = newCenter[i][j] / newCenterSize[i];
                newCenter[i][j] = 0.0;  /* reset */
            }
            newCenterSize[i] = 0;       /* reset */
        }

        /*
            [step 6] Check the change of value of centers!
        */ 
       for (i=0; i<nObject; i++) {
           changeCluster += changeObjects[i];
           changeObjects[i] = 0;
       }
    } while (changeCluster == 0 || loop++ < MAX_ITERATION_VALUE);
    /* [step 7] If conditions are sufficient, the loop is over! */
}