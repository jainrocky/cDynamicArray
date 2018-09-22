#include <stdio.h>
#include <stdlib.h>

// INCLUDE INTEGERARRAY HEADER FILE TO USE INTEGER ARRAY
#include "integerArray.h"
/**
    An Example to show how to use Dynamic Integer Array in "C"
*/
int main(){

// Declaring IntegerArray
        IntegerArray *mArray;
// Allocating memory to mArray
        mArray = createIntegerArray();
// show a message to user
        printf("Enter Any No Of Element\n");
//Reading Integer Values
        readIntegerArray(mArray);
// show a message to user
        printf("Enter Any No Of Element\n");
//Again Reading Integer Values
        readIntegerArray(mArray);
//Printing all value of mArray
        for(int i = 0; i < arrayLength(mArray) ; i++)
            printf("\nvalueAt %d: %d",i,valueAt(mArray,i));
//Capacity of mArray
//Capacity is may be greater than length by atmost 4
        printf("\n\nCapacity: %d",arrayCapacity(mArray));
//Length of mArray
        printf("\nLength: %d",arrayLength(mArray));

    return 0;
}
