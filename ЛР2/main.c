/*
 * Для заданного целого n ≥ 0 вычислить:
 * (2n + 1)!! = 1·3·5·...· (2n + 1)
 *
 * То есть произведение нечетных чисел до чмсла (2*n+1)
 *
 */



#include <stdio.h>
#include <limits.h>


int main()
{

    int n = -1;

    printf("Enter n >= 0: ");
    scanf("%d",&n);

    //Проверка правильности ввода

    while (n < 0){
        fflush(stdin); //Очищает буфер введённых значений
        printf("\nEnter again: ");        
        scanf("%d",&n);
    }

    printf("You wrote %d\n",n);


    unsigned long long int p = 1; // Использую тип переменных long long int
    int i = 0;
    short IsOverFlow = 0; // переменная отвечающая за переполнением


    while ( (i < n) && !IsOverFlow ){

        printf(" for i = %u : p = %llu \n",i,p);

        i += 1;

        p = p*(2*i + 1);

        if (LONG_LONG_MAX/(2*i + 1) <= p){ // проверка переполнения
            IsOverFlow = 1;
        }

    }

    printf("Last i = %u : p = %llu \n",i,p);

    if (IsOverFlow){
        printf("Error: when i = %u is over flow.", i + 1 );
    }

    return 0;
}
