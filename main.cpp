#include "common.h"

int main(int argc, char* argv[]){
    /*  Usage:  ./main filename nObject nDimension nCenter */
    argv[1] = "../example.txt";
    argv[2] = "100";
    argv[3] = "18";
    argv[4] = "5";

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

    for(int i = 0; i < nObject; i++)
    {
        for(int j = 1; j < nDimension + 1; j++)
            std::cout << object[i][j] << "    ";
        std::cout << std::endl;
    }

    center = kmeans_init(object, nObject, nDimension, nCenter);
    kmeans(object,center, nObject, nDimension, nCenter);

    for(int i = 0; i < nObject; i++)
    {
        for(int j = 0; j < nDimension + 2; j++)
            std::cout << object[i][j] << "    ";
        std::cout << std::endl;
    }

    return 0;
}