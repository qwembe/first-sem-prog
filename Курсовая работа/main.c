/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: artcet
 *
 * Created on December 5, 2016, 12:28 AM
 */

#include <stdio.h>
#include <stdlib.h>

int N;int M; //глобальные переменные для массива

void init_arr(int ***arr_ptr){ //функция для чтения массива из файла input.txt
		
	FILE *f = fopen("input.txt","r");
	if (f == NULL){
		fprintf(stderr,"Error: file not found!");
		exit(EXIT_FAILURE);
		}
        
        int d,isOk;
        
        fscanf(f,"%d",&N);
        fscanf(f,"%d",&M);       
        
        *arr_ptr = (int**) malloc((N)*sizeof(int*));
        for (int i=0; i<N; i++) (*arr_ptr)[i] = (int*)malloc((M)*sizeof(int));
        
        int *ptr = **arr_ptr;
        
        for(int i = 0; i<N ;i++)
            {
            ptr = (*arr_ptr)[i];
            for(int j = 0; j<M ;j++,++ptr)
                {
                isOk = fscanf(f,"%d",&d);
                *ptr = d;
                if(isOk == -1)
                    {
                    fprintf(stderr,"Error:Can not read file!");
                    exit(EXIT_FAILURE);
                    }
                }
            }
    
}


int min(int a,int b,int c){ //функция для нахождения минимального значения из трёх
    if ((a < b)   && (a < c)) { return a  ;};
    if ((b < a)   && (b < c)) { return b  ;};
    if ((c < b)   && (c < a)) { return c  ;};
}

int alg_output(int ***arr_ptr){//алгоритм и вывод массива B в output.txt (для проверки)
    
    int **A = *arr_ptr;
    int B[N][M];
    
    int max_sq = 0;
    
    for(int i = 0; i<N;i++) { B[i][0] = *(A[0]+i) ;}; 
    for(int j = 0; j<M;j++) { B[0][j] = *(A[j]);};
    for(int i = 1; i<N;i++){
        for(int j = 1;j<M;j++){
            B[i][j] = (min(B[i][j-1],B[i-1][j],B[i-1][j-1])+1)*(*(A[i]+j));
            if (max_sq <= B[i][j]) {max_sq = B[i][j];};
        }
    }     
    
    //!!!!!!!!!-----!!!!!!!!!!!!!
    //вывод массива в файл
     
    FILE *f = fopen("output.txt","w");       
        
        fprintf(f,"Max square is %d\n",max_sq);
        
        int *ptr = *arr_ptr;
        
        for(int i = 0; i<N ;i++){
           // ptr = (*arr_ptr)[i];
            for(int j = 0; j<M ;j++){
                fprintf(f,"%d ",B[i][j]);                
            }
            fprintf(f,"\n");
        } 
     
        return max_sq;    
}





int main() {
    int **arr_ptr;       
     
    init_arr(&arr_ptr);
    
    int max;
    
    max = alg_output(&arr_ptr);   
    
    //printf("Max square is %d",max);
}

  
