#include <stdio.h>
#include <stdlib.h>

int doppio(int a){return a*2;}
int quadro(int a){return a*a;}
int clamp(int a){
    if (a<0) {return 0;}
    else if (a>100) {return 100;}
    else {return a;}    
}
void applica(int *arr, int n, int (*fn)(int)){
    for (int i=0; i<n; i++){
        arr[i] = fn(arr[i]);
    }
}

int positivo(int a){
    if (a>0) {return 1;}
    else {return 0;}
}

void filtra(int *arr, int n, int *out, int *m, int (*predicato)(int)){
    for (int i=0;i<n;i++){
        if(predicato(arr[i])==1) {
            out[*m] = arr[i];
            (*m)++;
        }
    }
}

int main(){
    int nums[3] = {-2,7,9};
    int length = sizeof(nums)/sizeof(nums[0]);
    applica(nums, length, doppio);
    for (int i=0; i<length;i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    applica(nums, length, quadro);
    for (int i=0; i<length;i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    applica(nums, length, clamp);
    for (int i=0; i<length;i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    int out[length];
    int m = 0;
    filtra(nums, length, out, &m, positivo);
    for (int i=0; i<m;i++){
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
}
