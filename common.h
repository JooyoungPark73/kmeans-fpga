//
// Created by Joo-Young Park on 2020/09/22.
//

#ifndef KMEANS_FPGA_COMMON_H
#define KMEANS_FPGA_COMMON_H

#endif //KMEANS_FPGA_COMMON_H

#include "cstdlib"
#include "cstdio"
#include "iostream"
#include "cassert"
#include "fstream"
#include "cstring"
#define MAX_CHAR_PER_LINE 128
#define MAX_ITERATION 500

float** file_read(char* filename);
float** kmeans_init(float** object);
void kmeans(float** object, float** cluster);

int nCenter, nObject, nDimension;