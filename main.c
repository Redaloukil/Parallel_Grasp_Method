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

float generateCordinates(Cordinate c1 , Cordinate c2 , Cordinate c3 , Cordinate c4){
    return 0;
}

Parcels generateParcels(Parcels *parcels){
    for(int i=0;i<PARCELSNUMBER;i++){
        Parcel parcel;
        parcel.latitude = -1.2;
        parcel.longitude = 29.3;
        addParcelAtEnd(*parcels , parcel);
    } 
}

Parcels generateColisList(int number_parcels){
    Parcels parcels;

}

float square(float number){
    return number*number;
}

float calculateMin(Parcel startPoint , Parcels parcels){
    float min = calculateCost(startPoint , parcels.parcels[0]);
    for(int i=1; i<parcels.numberParcels;i++){
        if(calculateCost(parcels.parcels[i]) < min) min = calculateCost(parcels.parcels[i]);
    }
    return min;
}

float calculateMax(Parcel startPoint , Parcels parcels){
    float max = calculateCost(startPoint , parcels.parcels[0]);
    for(int i=1; i<parcels.numberParcels;i++){
        if(calculateCost(parcels.parcels[i]) > max) max = calculateCost(parcels.parcels[i]);
    }   
    return min;
}

float calculateCost(Parcel startPoint , Parcel nextPoint){
    return sqrt(square(nextPoint.longitude - startPoint.longitude) + square(nextPoint.latitude - startPoint.latitude));
}


void constructionPhase(){

}
//lunch cost calculation 

int main(){
    clock_t t;
    
    int listSpot;
    Parcel Parcels;
    
    //start execution time
    t = clock();
    
    parcels = generateColisList(&parcels);
    
    t = clock() - 1;
    
    //end execution time
    double execution_time = ((double)t);
    printf("it takes %f ms to execute" , execution_time);
    return 0;
}