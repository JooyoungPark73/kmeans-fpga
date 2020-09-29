#include "common.h"

int main(int argc, char* argv[]){
    /*  Usage:  ./main filename nObject nDimension nCenter */
    argv[1] = "example.txt";
    argv[2] = "5";
    argv[3] = "3";
    argv[4] = "2";

    if(5 != argc){
        std::cout << "invalid input; Usage:  ./main filename nObject nDimension nCenter" << std::endl;
    }

    char* filename;
    float** object;
    float** center;
    filename = argv[1];
    nObject = atoi(argv[2]);
    nDimension = atoi(argv[3]);
    nCenter = atoi(argv[4]);

    object = file_read(filename);
    assert(object != NULL);

    for(int i = 0; i < nObject; i++)
    {
        for(int j = 1; j < nDimension + 1; j++)
            std::cout << object[i][j] << "    ";
        std::cout << std::endl;
    }

    center = kmeans_init(object);
    kmeans(object,center);

    return 0;
}