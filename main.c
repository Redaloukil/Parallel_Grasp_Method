#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <math.h>
#include<time.h>
#include<regex.h>

#include"parcel.c"


#define STARTPOINT 0
#define WORKERS_NUM 4 
#define ALPHA 0.3
#define CURRENTLAT 1.2
#define CURRENTLON 2.2


int main(){
    clock_t t;
    
    int listSpot;

    Parcels parcels;
    Parcels path;
    
    //start execution time
    t = clock();
    
    // char *s;
    // gen_random(&s , 10);
    // printf("%c" , s);


    parcels = generateParcels(&parcels);


    for(int i=0;i<parcels.numberParcels;i++){
        printf("latitude : %f ,longitude :%f, key:%s \n" ,parcels.parcels[i].latitude ,parcels.parcels[i].longitude , parcels.parcels[i].key);
    }
    
    constructionPhase(parcels , path);
    

    t = clock() - 1;
    //end execution time
    double execution_time = ((double)t);
    printf("it takes %f ms to execute" , execution_time);
    return 0;
}