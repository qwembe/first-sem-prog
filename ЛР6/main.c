#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#define MAX_SIZE 100


int input_arr(int *a);
void output_arr(int df,int len);
int alg(int *a,int len);
void *input();




int main(){
    
    int a[MAX_SIZE],len = input_arr(a);
   
    int df = alg(a,len);
    
    output_arr(df,1);
    
    return 0;
}

int input_arr(int *a){
    
    FILE *f = input();
    
    int n,i = 0;
    int isOk = fscanf(f, "%d" , &n); ;

       
    while(isOk != -1) {
        
        
        a[i] = n;
               
        if(isOk != 1) {
            fprintf(stderr, "Error: incorrect file format!\n");
            exit(EXIT_FAILURE);            
        }
        
        isOk = fscanf(f, "%d" , &n);
        i++;
        

    }
    fclose(f);
    return i;
}

void *input(){
    FILE *f = fopen("input.txt","r");
    
    if(f == NULL){
        fprintf(stderr, "Error: file not found!");
        exit(EXIT_FAILURE);        
    }
    
    return f;
}

void output_arr(int df,int len){
   
    FILE *f = fopen("output.txt","w");
    for(int i = 0; i < len; i++){
    fprintf(f,"Number: %d \n",df);
    }
    fcloseall();
}

int alg(int *a,int len){
    int sum = len*(len+1)/2; // Сумма арифметической прогресси от 0 до n
    
    for(int i = 0;i < len;i++){
        sum = sum - a[i];    // Вычитание всех чисел из суммы и посиск недостающего
    };
    if(sum < 0 || sum > len){
    
     fprintf(stderr,"Error: incorect data!");
     exit(EXIT_FAILURE);     

     }

	     
    return sum;
}



