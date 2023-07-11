#include "../inc/SortedCollection.h"



void SortedCollection::add(double item) {
    size++;
    double x;
    //check to see if the array capacity needs to be expanded, use tempArray to store contents of the dbl array while memory is being reallocated.
    if (size > capacity) {
        double* tempArray;
        capacity = 2 * capacity;
        tempArray = new double[capacity];
        for (int i = 0; i < size - 1; i++) {
            tempArray[i] = this->dbl[i];
        }
        //Uses overloaded = operator to copy over data
        this->dbl = tempArray;
    }

    //adding and sorting instructions
    if (size == 1) {
        dbl[0] = item;
    }
    else {
        //iterate through each spot in the collections array, use variable x to store larger values when shifting their position while sorting.
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                dbl[i] = item;
            }
            if (dbl[i] > item) {
                x = dbl[i];
                dbl[i] = item;
                item = x;
            }
            
        }
    }
}
