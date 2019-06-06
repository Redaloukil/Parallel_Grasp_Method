#include <stdio.h>
#include <stdlib.h>

int main(){
   int num;
   FILE *fptr;

   if ((fptr = fopen("/home/redaloukil/Desktop/coding/pfe/Cuda_Tsp_GRASP_Simulation/parrallel_execution/egypt.tsp.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d", &num);

   printf("Value of n=%d", num);
   fclose(fptr); 
  
   return 0;
}