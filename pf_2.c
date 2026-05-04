#include <stdio.h>
#include <stdlib.h>

void map(int *arr, int *out, int n, int (*fn)(int)){
    for(int i=0; i<n; i++){
        out[i] = fn(arr[i]);
    }

}

int is_even(int a){
    if (a % 2 == 0) {return 1;}
    else {return 0;}
}

void filter(int *arr, int *out, int *out_n, int n, int (*predicato)(int)){
        for(int i=0; i<n; i++){
            if (predicato(arr[i]) == 1){
                out[*out_n] = arr[i];
                (*out_n)++;
            }
    }

}

int reduce(int *arr, int n, int acc, int (*fn)(int, int)){
    for(int i=0; i<n;i++){
        acc = fn(acc, arr[i]); 
    }
    return acc;
}

int somma(int x, int y) {return x + y;}
int doppio(int x)   { return x * 2; }
int quadrato(int x) { return x * x; }

int main(){
    
    int len = 7;
    int arr[len];
    int out_map[len];
    int out_filter[len];
    for(int i=0; i<len; i++){
        arr[i] = rand() % 20;
    }
    for (int i=0; i<len;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
        int out_n=0;
    filter(arr,out_filter,&out_n,len, is_even);
    for (int i=0; i<out_n;i++){
        printf("%d ", out_filter[i]);
    }
    map(out_filter, out_map, out_n, quadrato);
    for (int i=0; i<out_n;i++){
        printf("%d ", out_map[i]);
    }
    printf("\n");
    int acc = 0;
    acc = reduce(out_map, out_n, acc, somma);
    printf("%d", acc);
    printf("\n");
    return 0;
    
}