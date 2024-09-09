#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
    int* data;
    size_t len;
} array_list;

array_list collatzConjecture(int);
int calculateNextValue(int);
int* appendValue(int*, size_t, int);

int main(int argc, char** argv){
    if(argc <= 1){
        printf("Please define a number.\n");
        return 1;
    }
    else if(argc > 2){
        printf("Too many arguments.\n");
        return 1;
    }
    
    char* numberStr = argv[1];
    int number = 0;
    sscanf(numberStr, "%d", &number);
    
    array_list sequence = collatzConjecture(number);
    if(sequence.data == NULL){
        printf("Number must be greater than 0.\n");
        return 1;
    }

    printf("[");
    for(int i = 0; i < sequence.len; ++i){
        printf("%d", *(sequence.data+i));
        if((i+1) < sequence.len){
            printf(" ");
        }
    }
    printf("]\n");
    return 0;
}

array_list collatzConjecture(int initialNumber){
    if(initialNumber <= 0){
        array_list list;
        return list;
    }
    size_t count = 0;
    int number = initialNumber;
    int *numbers = NULL, *prev = NULL;
    numbers = appendValue(prev, count, number);
    ++count;
    while(number != 1){
        if(prev){
            free(prev);
        }
        prev = numbers;
        number = calculateNextValue(number);
        numbers = appendValue(prev, count, number);
        ++count;
    }
    if(prev){
        free(prev);
    }
    array_list list;
    list.data = numbers;
    list.len = count;
    return list;
}

int calculateNextValue(int number){
    if((number % 2) == 0){
        return number / 2;
    }
    else {
        return ((3 * number) + 1) / 2;
    }
}

int* appendValue(int* a, size_t length, int value){
    int* tmp = (int*)malloc(sizeof(int)*(length+1));
    for(int i = 0; i < length; ++i){
        *(tmp+i) = *(a+i);
    }
    *(tmp+length) = value;
    return tmp;
}