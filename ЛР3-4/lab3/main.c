/*
 *Лабораторная работа №3-4
 *lab3-4.cpp
 *Вайгачев Андрей Олегович
 * 12.10.2016
 *
 * программа для вычисления косинуса
 *
 */


#include <stdio.h>
#include <math.h>
#define real  double



const real Epsilon () {

    real eps = 1.0;
    while (1 + eps > 1.0){
        eps *= 0.5;
    }
    eps *= 2;
    printf("Epsilon : %Le\n",eps); // %f - в случае если real - float, %lf - в случае если не так
    return eps;

}

const real GiveMeX(){


    real x = 0;
    printf("Enter x: \n");


    while (!scanf("%Lf", &x))  // <---
    {
         getchar();
    }


    printf("You entered : %Lf\n",x); // <---

    return x;

}

real Summator_cos(real *x,real *eps){

    //const real eps = Epsilon();

    real s  = 0;
    real u  = 1;
    int i   = 0;

    while(fabs(u) > *eps){

        s += u;
        u *= -(*x)*(*x)/(2*i+1)/(2*i+2);
        i++;


    }
    printf("Sum : %Lf\n",s); // <---
    return s;
}

void fault_cos(real *sum,real *x){

   real _cos = cos(*x);
   printf("Cos(%f) = %Lf\n",*x,_cos); // <---

   printf("Absolute fault = %le\n",fabs(_cos-*sum)); // <---
   printf("Relative fault = %le %%\n",fabs((fabs(_cos-*sum)/_cos)*100));   // <---

}





int main(){

    const real eps = Epsilon();

    const real x = GiveMeX();

    const real sum = Summator_cos(&x,&eps);

    fault_cos(&sum,&x);

    return 0;
}



