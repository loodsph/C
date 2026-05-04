#include <stdio.h>
#include <string.h>

int cmp_int(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    if (x<y) {return -1;}
    else if (x == y) {return 0;}
    else {return 1;}
}

int cmp_char(const void *a, const void *b){
const char *x = *(const char**)a;
const char *y = *(const char**)b;
return strcmp(x, y);


}
void selection_sort(void *base, int n, int elem_size, int (*cmp)(const void*, const void*)){
    for (int i=0; i < n; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            
            if(cmp((char*)base + min_idx * elem_size, (char*)base + j * elem_size
) == 1 ){ 
    min_idx=j;

}


        }
    char tmp[elem_size];
    memcpy(tmp, (char*)base + i * elem_size, elem_size);
    memcpy((char*)base + i * elem_size, (char*)base + min_idx * elem_size, elem_size);
    memcpy((char*)base + min_idx * elem_size, tmp, elem_size);
    } 
}

int main(){
    int arr[] = {2,9,3,16,5};
    int length = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,length,sizeof(int),cmp_int);
    for (int i=0; i<5;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    char *parole[] = {"banana", "mela", "arancia", "kiwi"};
    int n = 4;
    selection_sort(parole, n, sizeof(char*), cmp_char);
    for (int i=0; i<4;i++){
        printf("%s ", parole[i]);
    }
    printf("\n");
    return 0;
}