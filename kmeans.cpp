#include "common.h"

//float euclid_dist_2(float* coord_obj, float* coord_center){
//    float dist = 0;
//    assert(coord_obj != NULL && coord_center != NULL);
//    for(int i=0; i<nDimension; i++)
//        dist += (coord_obj[i+1] - coord_center[i]) * (coord_obj[i+1] - coord_center[i]);
//
//    return dist;
//}
//
//void find_closest_center(float** object, float** center){
//    for(int i=0; i<nObject; i++){   //  Fill object array distance part
//        for(int j=0; j<nCenter; j++){
//            object[i][nDimension+1+j] = euclid_dist_2(object[i], center[j]);
//        }
//    }
//
//    for(int i=0; i<nObject; i++){   //  Find Closest Cluster
//        int min=0;
//        for(int j=0; j<nCenter; j++){
//            if(object[i][1+nDimension+min] > object[i][1+nDimension+j]) min = j;
//        }
//    }
//
//}


void kmeans(float** object, float** center, int nObject, int nDimension, int nCenter){
    /* */
    int i=1;
    while(1)
    {
        int center_change = 0;
        int* past_center =(int *)malloc(sizeof(int)*nObject);
        for(int j=0; j<nObject; j++) past_center[j] = int(object[j][0]);    // Save past center index


        for(int i=0; i<nObject; i++){   //  Calculate center distance -> i th object to j th center k th dimension
            for(int j=0; j<nCenter; j++){
                float dist = 0;
                for(int k=0; k<nDimension; k++) dist += (object[i][k+1] - center[j][k]) * (object[i][k+1] - center[j][k]);
                object[i][nDimension+1+j] = dist;
                std::cout << "distance is " << dist;
            }
            std::cout << std::endl;
        }

        for(int i=0; i<nObject; i++){   //  Find Closest Cluster and insert in object[i][0]
            int min=0;
            for(int j=0; j<nCenter; j++){
                if(object[i][1+nDimension+min] > object[i][1+nDimension+j]) min = j;
            }
            object[i][0] = min;
        }
        std::cout << i << "th iteration" << std::endl << "current center is" << std::endl;
        for(int i=0; i<nObject; i++){
            std::cout << object[i][0];
            if(past_center[i] != object[i][0]) {
                center_change = 1;
                break;
            }
            std::cout << std::endl;
        }
    i++;

        if(i>MAX_ITERATION) return;
    }
}