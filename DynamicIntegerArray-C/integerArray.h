

/**
    @CreatedDate: 22-SEP-2018
    @Author: Rocky Jain
*/


#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H
#define INTIALSIZE 4
#define INTIALLENGTH 0
#define SPACE 32

/**
    INTEGER ARRAY STRUCTURE define as a "IntegerArray"
    @params: capacity
             CAPACITY of INTEGER ARRAY, Capacity is may be greater than length by atmost 4

    @params: len
             LENGTH of INTEGER ARRAY, may be equal or less than capacity

    @params: POINTER ARRAY
*/
typedef struct IntegerArray{

    int capacity;
    int len;
    int *Array;

}IntegerArray;

/**
    @function: createIntegerArray
    @inputParams: void
    @returnType: IntegerArray

    allocating the memory to INTEGER ARRAY
*/
IntegerArray * createIntegerArray(void);

/**
    @function: increaseCapacity
    @inputParams: IntegerArray
    @returnType: IntegerArray

    increase the size of INTEGER ARRAY, called by "readIntegerArray"
*/
IntegerArray* increaseCapacity(IntegerArray*);

/**
    @function: shrinkCapacity
    @inputParams: IntegerArray
    @returnType: IntegerArray

    shrink the size of INTEGER ARRAY
*/
IntegerArray* shrinkCapacity(IntegerArray*);

/**
    @function: readIntegerArray
    @inputParams: IntegerArray
    @returnType: void

    read INTEGERS FROM STDIN and store in INTEGER ARRAY
*/
void readIntegerArray(IntegerArray*);

/**
    @function: valueAt
    @inputParams: IntegerArray and INT
    @returnType: INT

    return valueAt given index on INTEGER ARRAY
*/
int valueAt(IntegerArray*, int);

/**
    @function: arrayLength
    @inputParams: IntegerArray
    @returnType: INT

    return length on INTEGER ARRAY
*/
int arrayLength(IntegerArray*);

/**
    @function: arrayCapacity
    @inputParams: IntegerArray
    @returnType: INT

    return capacity on INTEGER ARRAY
*/
int arrayCapacity(IntegerArray*);




#endif // INTEGERARRAY_H
