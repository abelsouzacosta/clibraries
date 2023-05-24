#ifndef FANCY_H
#define FANCY_H

typedef struct FancyArray FancyArray;

FancyArray *create(int capacity);

void destroy(FancyArray **array);

int size(const FancyArray *array);

int capacity(const FancyArray *array);

float at(const FancyArray *array, int index);

float get(const FancyArray *array, int index);

void append(FancyArray *array, float newElement);

void set(const FancyArray *array, int index, float newElement);

void print(const FancyArray *array);

#endif
