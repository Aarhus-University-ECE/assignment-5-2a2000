#include "jollyjumper.h"
#include <stdbool.h>
#include <malloc.h>

int is_In_Array(int* arr, int size, int n ){ 
     for(int i=0; i < size; i++){
        if(arr[i] == n)
        return 1; 
     }
     return 0; 
}
int isJollyJumber(const int seq[], int size) {
/*post: answer to exercise 7.a*/

    if (size <= 0)
        return 0;
    
    // Create array with size - 1 places
    int* dif = malloc(sizeof(int)*(size-1));
    
    // Fill the array
    for (int i=0; i< size - 1; i++){
        dif[i] = abs(seq[i]-seq[i+1]);
    }
    // Calculate max and min
    int max, min;
    max = min = dif[0];
    for(int i=1; i < size -1; i++){ 
        if(dif[i]>max)
        max = dif[i];

        else if (dif[i] < min)
        min = dif[i];
    }

    // Go from min to max and check if all the values are present
    for(int i = min; i <= max; i++){
        if (is_In_Array(dif, size-1, i) == 0 )

            return 0; 
    }

    return 1;
} 