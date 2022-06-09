#include<stdio.h>
#include<time.h>
#include <stdlib.h>

int main(){
  int max_stride = 16;
  int N = 1000000,i_stride;
  //float *p = malloc(sizeof(int));
  float * x, *y, *z;
  x = (float *)malloc(max_stride * N * sizeof(float));
  y = (float *)malloc(max_stride * N * sizeof(float));
  z = (float *)malloc(max_stride * N * sizeof(float));
  
  float rt[20];
  float cpu[20];
  float mean, msec,rate;
  
  for (int i = 0; i < N * max_stride;i++){
  	for (int j = 0; i < N * max_stride;i++){
  		x[i,j] = 1.0;
  		y[i,j] = 1.0;
  		z[i,j] = 0.0;
	  }
    }
    
    for(i_stride = 1; i_stride <= max_stride; i_stride++){
	    clock_t begin = clock();
	    
	  	for (int i = 0; i < N * max_stride;i++){
		  	for (int j = 0; i < N * max_stride;i++){
		  		for (int k = 0; i < N * max_stride;i++){
		  			z[i,j] = z[i,j] + x[i,k]* y[k,j];
				  }
			  }
		    }
	    
	    //getting end time;
       clock_t end = clock();
       // Cpu_Time
       float msec = end - begin;
       // Bande_passante
       rate = 8 * N * (1000.0/msec) / (1024*1024);
       printf("-----------------------------------------\n\n");
       printf("i_stride = %d\nmean = %f\nCPU_Time = %f\nrate = %f\n", i_stride,mean,msec,rate);
       rt[i_stride-1] = rate;
       cpu[i_stride-1] = msec;

    }
    printf("Y = [");
    for(i_stride = 1; i_stride <= max_stride; i_stride++){
    	printf("%f,",rt[i_stride-1]);
	}
	printf("] \nY1 = [");
	for(i_stride = 1; i_stride <= max_stride; i_stride++){
    	printf("%f,",cpu[i_stride-1]);
	}
	printf("]");
    return 0;

	
}
