#ifndef _Tool_
#define _Tool_

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void Swap(int &a, int &b);
void CreateMatrix(int *a, int size, int range);
void DisMatrix(int *a, int size);
bool SaveFile(int *a, int size);
int ReadFile(int *a);
void CreateTestDataFile(int a);

#endif