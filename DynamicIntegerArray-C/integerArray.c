

/**
    @CreatedDate: 22-SEP-2018
    @Author: Rocky Jain
*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "integerArray.h"



/**
    @function: createIntegerArray
    @inputParams: void
    @returnType: IntegerArray

    allocating the memory to INTEGER ARRAY
*/
IntegerArray * createIntegerArray(){

    IntegerArray *mNew;

    mNew = (IntegerArray*)malloc(sizeof(IntegerArray));

    if(mNew != NULL)
    {
        mNew->Array = (int*) calloc(INTIALSIZE,sizeof(int));

        if(mNew->Array!=NULL)
        {
            mNew->capacity = INTIALSIZE;
            mNew->len = INTIALLENGTH;
            return mNew;
        }

        return NULL;
    }

    return NULL;

}


/**
    @function: increaseCapacity
    @inputParams: IntegerArray
    @returnType: IntegerArray

    increase the size of INTEGER ARRAY, called by "readIntegerArray"
*/
IntegerArray* increaseCapacity(IntegerArray* mArray){
    mArray->capacity <<= 1;
    mArray->Array = (int*)realloc(mArray->Array, sizeof(int) * mArray->capacity);
    if(mArray->Array!=NULL)
        return mArray;
    return NULL;
}


/**
    @function: readIntegerArray
    @inputParams: IntegerArray
    @returnType: void

    read INTEGERS FROM STDIN and store in INTEGER ARRAY
*/
void readIntegerArray(IntegerArray* mArray)
{
    if(mArray!=NULL){
        int index = mArray->len;
        int count = mArray->len;
        int key = 0;
        int data = 0;
        char c,*cp;
        cp =&c;
        while(scanf("%c",&c) && c!='\n')
        {

           if(c != SPACE && c > 47 && c < 58 ){
                key = 1;
                data = data * 10 + atoi(cp);

           }
           else if(c == SPACE && key){
                key = 0;
                if(mArray->capacity <= count)
                    mArray = increaseCapacity(mArray);
                count++;
                mArray->Array[index++] = data;
                mArray->len++;
                data = 0;
           }
           else if(c == SPACE) key = 0;
        }
        if(key){
            key = 0;
            if(mArray->capacity <= count)
                mArray = increaseCapacity(mArray);
            count++;
            mArray->Array[index++] = data;
            mArray->len++;
            data = 0;
        }
        if(mArray->capacity > (mArray->len + INTIALSIZE))
            shrinkCapacity(mArray);
    }
}


/**
    @function: shrinkCapacity
    @inputParams: IntegerArray
    @returnType: IntegerArray

    shrink the size of INTEGER ARRAY
*/
IntegerArray * shrinkCapacity(IntegerArray* mArray){

    mArray->capacity = (mArray->len + INTIALSIZE);
    mArray->Array = (int*)realloc(mArray->Array, sizeof(int) * mArray->capacity);
    if(mArray->Array!=NULL)
        return mArray;
    return NULL;

}


/**
    @function: valueAt
    @inputParams: IntegerArray and INT
    @returnType: INT

    return valueAt given index on INTEGER ARRAY
*/
int valueAt(IntegerArray *mArray, int position){
    if(position <= mArray->len && mArray!=NULL)
        return mArray->Array[position];
    return NULL;
}


/**
    @function: arrayLength
    @inputParams: IntegerArray
    @returnType: INT

    return length on INTEGER ARRAY
*/
int arrayLength(IntegerArray* mArray){

    if(mArray!= NULL)
        return mArray->len;

    return NULL;
}


/**
    @function: arrayCapacity
    @inputParams: IntegerArray
    @returnType: INT

    return capacity on INTEGER ARRAY
*/
int arrayCapacity(IntegerArray *mArray){

    if(mArray != NULL)
        return mArray->capacity;

    return NULL;
}
