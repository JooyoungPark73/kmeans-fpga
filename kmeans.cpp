#include "common.h"

float euclid_dist_2(float* coord_obj, float* coord_center){
    float dist = 0;
    assert(coord_obj != NULL && coord_center != NULL);
    for(int i=0; i<nDimension; i++)
        dist += (coord_obj[i+1] - coord_center[i]) * (coord_obj[i+1] - coord_center[i]);

    return dist;
}

int find_closest_center(float** object, float** center){
    for(int i=0; i<nObject; i++){   //  Fill object array distance part
        for(int j=0; j<nCenter; j++){
            object[i][nDimension+1+j] = euclid_dist_2(object[i], center[j]);
        }
    }

    for(int i=0; i<nObject; i++){   //  Find Closest Cluster
        int min=0;
        for(int j=0; j<nCenter; j++){
            if(object[i][1+nDimension+min] > object[i][1+nDimension+j]) min = j;
        }
    }

}


void kmeans(float** object, float** cluster){

}