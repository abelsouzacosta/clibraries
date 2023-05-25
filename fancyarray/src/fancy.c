#include "../include/fancy.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct FancyArray {
  int capacity;
  int size;
  float *data;
};

/**
 * @brief Creates (allocate) an float array  with the capacity given in
 * the argument, an FancyArray is an special type of array with just float
 * numbers
 *
 * @param capacity -> array capacity
 * @return FancyArray*
 */
FancyArray *create(int capacity) {
  FancyArray *array = (FancyArray *)calloc(1, sizeof(FancyArray));
  array->size = 0;
  array->capacity = capacity;
  array->data = (float *)calloc(capacity, sizeof(float));
  return array;
}

/**
 * @brief Destroys the array
 */
void destroy(FancyArray **array) {
  FancyArray *arr = *array;
  free(arr->data);
  free(arr);
  *array = NULL;
}

/**
 * @brief Returns the size of the array
 *
 * @param array -> the array with the elements
 */
int size(const FancyArray *array) { return array->size; }

/**
 * @brief Returns the capacity of the array
 *
 * @param array -> the array with the elements
 */
int capacity(const FancyArray *array) { return array->capacity; }

/**
 * @brief Appends an new element at the end of the array
 *
 * @param array -> the array to append new element
 */
void append(FancyArray *array, float newElement) {
  if (array->size == array->capacity) {
    fprintf(stderr,
            "Error: was not possible to append element %f, the array is full",
            newElement);
    exit(EXIT_FAILURE);
  }

  if (array->size == array->capacity - 1) {
    array->data[array->size] = newElement;
  }

  array->data[array->size] = newElement;
  array->size += 1;
}

/**
 * @brief Returns the data of a index
 *
 * @param array -> the array
 * @index -> the index of the element
 */
float get(const FancyArray *array, int index) { return array->data[index]; }

/**
 * @brief Prints the array in the parameter given
 *
 * @param array -> array to be printed
 */
void print(const FancyArray *array) {
  printf("----------------------------------\n[");
  for (int counter = 0; counter < array->size; counter += 1) {
    if (counter == array->size - 1) {
      printf("%.2f", array->data[counter]);
    } else {
      printf("%.2f, ", array->data[counter]);
    }
  }
  printf("]\n--------------------------------\n");
}

/**
 * @brief Sets an element in a position withiun the given array
 *
 * @param array -> array to set the element
 * @param index -> index position to fit the element
 * @param newElement -> the element
 */
void set(const FancyArray *array, int index, float newElement) {
  if (array->size == array->capacity) {
    fprintf(stderr,
            "Error: was not possible to set %f at %d, index already occupied "
            "by the element %f",
            newElement, index, array->data[index]);
    return;
  }

  if (array->data[index] != 0) {
    for (int counter = array->size; counter > index; counter += 1) {
      float prev = array->data[counter - 1];
      array->data[counter] = prev;
    }

    array->data[index] = newElement;
  }
}

/**
 * @brief Removes an element at the position
 *
 * @param array-> memory address of the array
 * @index -> index of the element to be removed
 */
void remove_element(FancyArray **array, int index) {
  size_t original_size = (*array)->size;
  size_t new_size = original_size - 1;
  FancyArray *new_array = (FancyArray *)create(new_size);

  for (size_t counter = 0; counter < original_size; counter += 1) {
    if (counter != index) {
      append(new_array, (*array)->data[counter]);
    }
  }

  fprintf(stdout, "Removing element %.2f at position %d", (*array)->data[index],
          index);

  free((*array)->data);
  free(*array);
  *array = new_array;
}
