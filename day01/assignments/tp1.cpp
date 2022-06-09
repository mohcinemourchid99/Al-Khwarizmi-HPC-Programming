#include<stdio.h>
#include<time.h>

int main (){
 
  int max_stride = 10,seed = 86456;
  int N = 100000,i_stride;
  float a[N * max_stride];
  float mean, msec,rate;


   
    for (int i = 0; i < N * max_stride;i++){
       a[i] = 0;
    }

    for(i_stride = 1; i_stride < max_stride; i_stride++){

      mean = 0.0;
      // getting starting time
      clock_t begin = clock();

      for (int i=0; i< N * i_stride; i+=i_stride){
        mean = mean + a[i];
      }

      //getting end time;
      clock_t end = clock();
      // Cpu_Time
      float temp = end - begin;
      msec = (temp / 10000);
      // Bande_passante
      rate = 8 * N * (1000.0/msec) / (1024*1024);
      printf("-----------------------------------------\n\n");
      printf("i_stride = %d\nmean = %f\nCPU_Time = %f\nrate = %f\n", i_stride,mean,msec,rate);

    }

    return 0;

}
