//
// Created by Joo-Young Park on 2020/09/22.
//
#pragma once
#ifndef KMEANS_FPGA_COMMON_H
#define KMEANS_FPGA_COMMON_H


#include "cstdlib"
#include "cstdio"
#include "iostream"
#include "cassert"
#include "fstream"
#include "cstring"
#define MAX_CHAR_PER_LINE 128
#define MAX_ITERATION 10

float** file_read(char* filename, int nObject, int nDimension, int nCenter);
float** kmeans_init(float** object, int nObject, int nDimension, int nCenter);
void kmeans(float** object, float** center, int nObject, int nDimension, int nCenter);

#endif //KMEANS_FPGA_COMMON_H
