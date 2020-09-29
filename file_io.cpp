#include "common.h"

float** file_read(char* filename){
    float** object;
    char* line;
    int linelength = nDimension+nCenter+1;
    //FILE *infile;
    std::ifstream infile(filename);

    if(!infile.is_open()){  // if file is not open, return
        std::cout << "File name " << filename << " does not exist" << std::endl;
        return NULL;
    }
    line = (char*)malloc(MAX_CHAR_PER_LINE);

    object = (float**)malloc(sizeof(float*) * nObject); /* allocate object array */
    for(int i = 0; i < nObject; i++)
        object[i] = (float*)malloc(sizeof(float) * linelength);

    int i = 0;
    while (!infile.eof()) {
        infile.getline(line, MAX_CHAR_PER_LINE);
        object[i][1] = std::atof(strtok(line, " ,\t\n"));
        //printf("object[%d][1]=%f\n",i,object[i][1]); //delete before code release
        for (int j=2; j<(nDimension)+1; j++) {
            object[i][j] = std::atof(strtok(NULL, " ,\t\n"));
            //printf("object[%d][%d]=%f\n",i,j,object[i][j]); //delete before code release
        }
        i++;
    }

    return object;
}