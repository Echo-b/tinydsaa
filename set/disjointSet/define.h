/**
 * @file define.h
 * @author echo
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * @brief simple union find set implimation
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100
int disjointSet[SIZE];

bool makeset(int S[], int size);
int find(int S[],int x);
bool Union(int S[],int root1, int root2);
