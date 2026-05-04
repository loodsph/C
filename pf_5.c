#include <stdio.h>

typedef struct  {
    const char *nome;
    int (*processa)(int);
} filtro;

int normalizza(int x) { return x / 10; }          
int inverti(int x)    { return -x; }               
int soglia(int x)     { return x > 50 ? 50 : x; }     

filtro filtri[] = {
    {"normalizza", normalizza},
    {"inverti",    inverti},
    {"soglia",     soglia},
};

void applica_pipeline(int *arr, int n, filtro *filtri, int *indici, int n_filtri){
    for (int i=0; i<n_filtri; i++){
        filtro f = filtri[indici[i]];
        for(int j=0; j<n; j++){
            arr[j] = f.processa(arr[j]);
        }
        
    }
}
 int main(){
    int dati[] = {100, -30, 200, 45, 80};
    int n = 5;


    int pipeline_a[] = {0, 2};
    applica_pipeline(dati, n, filtri, pipeline_a, sizeof(pipeline_a)/sizeof(pipeline_a[0]));
        for (int i=0; i<sizeof(dati)/sizeof(dati[0]);i++){
        printf("%d ", dati[i]);
    }
    printf("\n");
return 0;
 }