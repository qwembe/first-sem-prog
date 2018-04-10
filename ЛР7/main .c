#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <malloc.h>
#define MAX_N 100


int init_arr(int ***arr_ptr){
		
	
	FILE *f = fopen("input.txt","r");
	if (f == NULL){
		fprintf(stderr,"Error: file not found!");
		exit(EXIT_FAILURE);
		}
        
        int N,d,isOk;
        
        fscanf(f,"%d",&N);
       
        
        *arr_ptr = (int**) malloc(N*sizeof(int*));
        for (int i=0; i<N; i++) (*arr_ptr)[i] = (int*)malloc(N*sizeof(int));
        
        int *ptr = **arr_ptr;
        
        for(int i = 0; i<N ;i++)
            {
            ptr = (*arr_ptr)[i];
            for(int j = 0; j<N ;j++,++ptr)
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
        
        return N;
    
}

void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}


void alg(int ***alg,int N,int **result){
    
    /*
     * на вход этому алгоритму дается int ***alg,int N и int **result
     * result это вспомагательный массив ,который содержит в себе 
     * [0] - сумма всех набранных очков команды
     * [1] - место , которое заняла команда
     * [2] - номер команды{заполнен - 1,2,3...} (нужен для того ,чтобы во время перестановки значений в порядке не убывания не потерялся номер команды)
     * 
     * массив alg - устроен по так: массив указателей, которые ссылаются на выделенную память
     * массив result - цельный кусок памяти
     * 
     */
    
    //подсчитывает кол-во очков
    
    for(int i = 0; i<N ; i++){
        for(int j = 0 ; j<N ; j++)
            {
            (*result)[i*3] += *((*alg)[i]+j);
            }    
    }
    
    //определяет место каждой команды
    
    int leader=0;
    
    for(int i = 0; i<N ; i++){
        leader = (*result)[i*3];
        for(int j = 0; j<N ;j++){
            if (leader >= (*result)[j*3]){
                (*result)[j*3 + 1] += 1;
            }            
        }
    }
  
    //сортирует в соответсвии с условием
    
    int k = 1;
    int j = 0;
    
    while(k != N)
        {   
        for(int i = j;i < N;i++)
            {
            if( (*result)[i*3+1] == k )
               {        
                swap(&(*result)[j*3],&(*result)[i*3]);
                swap(&(*result)[j*3+1],&(*result)[i*3+1]);
                swap(&(*result)[j*3+2],&(*result)[i*3+2]);
                j++;           
                }
            }
        k++;
        }
      
}

void output_arr(int **result,int N){

	FILE *f = fopen("output.txt","w");       
        
        for(int i = 0; i<N ;i++){
            fprintf(f,"Team number %d has %d points\n",(*result)[i*3+2],(*result)[i*3+0]);
        }

}
        


int main(){

    int **arr_ptr;
    int j = 0;
    
    int N = init_arr(&arr_ptr);
    
    int *result = (int *) malloc(N*3*sizeof(int *));
    for(int i = 0; i<N ; i++){
        for(int j = 0 ; j<3 ; j++){
            result[i*3+j] = 0;
            result[i*3+2] = i+1;
        }
    
    }
    
    alg(&arr_ptr,N,&result);
    
    output_arr(&result,N);



}
