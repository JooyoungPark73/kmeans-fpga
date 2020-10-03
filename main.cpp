#include "common.h"

int main(int argc, char* argv[]){
    /*  Usage:  ./main filename nObject nDimension nCenter */
    argv[1] = "../example_color_100_18.txt";
    argv[2] = "100";
    argv[3] = "9";
    argv[4] = "10";

    if(5 != argc){
        std::cout << "invalid input; Usage:  ./main filename nObject nDimension nCenter" << std::endl;
    }

    char* filename;
    float** object;
    float** center;
    filename = argv[1];
    int nObject = atoi(argv[2]);
    int nDimension = atoi(argv[3]);
    int nCenter = atoi(argv[4]);

    object = file_read(filename, nObject, nDimension, nCenter);
    assert(object != NULL);

//    for(int i = 0; i < nObject; i++)
//    {
//        for(int j = 1; j < nDimension + 1; j++)
//            std::cout << object[i][j] << "    ";
//        std::cout << std::endl;
//    }

    center = kmeans_init(object, nObject, nDimension, nCenter);
    kmeans(object,center, nObject, nDimension, nCenter);

    std::cout  << "Center" << std::endl;
    for(int i=0; i< nCenter; i++){
        std::cout <<"["<< i << "]  ";
        for(int j=0; j<nDimension+1; j++) std::cout << center[i][j] << "   ";
        std::cout << std::endl;
    }


    return 0;
}