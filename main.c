#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include<time.h>

#include"parcel.c"

#define PARCELSNUMBER 20
#define STARTPOINT 0
#define WORKERS_NUM 4 
#define ALPHACOEFF 0.3
#define CURRENTLAT 1.2
#define CURRENTLON 2.2

float square(float number){
    return number*number;
}

float randBetween(float min, float max) {
    return ((float)rand()/RAND_MAX) * (max - min) + min;
}

float calculateCost(Parcel startPoint , Parcel nextPoint){
    return sqrtf(square(nextPoint.longitude - startPoint.longitude) + square(nextPoint.latitude - startPoint.latitude));
}

float generateCordinates(Cordinate c1 , Cordinate c2 , Cordinate c3 , Cordinate c4){
    return 0;
}



Parcels generateParcels(Parcels *parcels){
    for(int i=0;i<PARCELSNUMBER;i++){
        Parcel parcel;
        parcel.latitude = randBetween(1 , 3);
        parcel.longitude = randBetween(2 , 8);
        *parcels = addParcelAtEnd(parcels , parcel);
    }
    return *parcels; 
}

float calculateMin(Parcel startPoint , Parcels parcels){
    float min = calculateCost(startPoint , parcels.parcels[0]);
    int index = 0;
    for(int i=1; i<parcels.numberParcels;i++){
        if(calculateCost(startPoint , parcels.parcels[i]) < min){
            min = calculateCost(startPoint , parcels.parcels[i]);
            index = i;
        } 
    }
    return min;
}

float calculateMax(Parcel startPoint , Parcels parcels){
    float max = calculateCost(startPoint , parcels.parcels[0]);
    int index = 0;
    for(int i=1; i<parcels.numberParcels;i++){
        if(calculateCost(startPoint , parcels.parcels[i]) > max){
            max = calculateCost(startPoint ,  parcels.parcels[i]);
            index = i;
        } 
    }   
    return max;
}

//35.704482, -0.613292
//35.711626, -0.618666
//35.710345, -0.622024 
//35.708605, -0.625053
int estimateCost(){
    return 0;
}

Parcels selectParcel(Parcels parcels ,Cordinate position){
    Parcels rcl;
    float min = calculateMin(position , parcels);
    float max = calculateMax(position)
    for(int i=0; i<parcels.numberParcels;i++){
        if(estimateCost(parcels.parcels[i]) == 1){
            
        }
    }
}

void constructionPhase(Parcels parcels ,Parcels path){
    Cordinate position;
    position.latitude = CURRENTLAT;
    position.longitude = CURRENTLON;
    while(parcels.numberParcels > 0){
        Parcels rcl;
        rcl = selectParcel(parcels , position);
    }
}


int main(){
    clock_t t;
    
    int listSpot;

    Parcels parcels;
    Parcels path;
    
    //start execution time
    t = clock();
    printf("hello world");

    parcels = generateParcels(&parcels);


    for(int i=0;i<parcels.numberParcels;i++){
        printf("latitude : %f ,longitude :%f\n" ,parcels.parcels[i].latitude ,parcels.parcels[i].longitude);
    }
    
    constructionPhase(parcels , path);
    
    t = clock() - 1;
    //end execution time
    double execution_time = ((double)t);
    printf("it takes %f ms to execute" , execution_time);
    return 0;
}