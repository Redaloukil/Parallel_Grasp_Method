#include<iostream>
#include<vector>
#include<math.h>
#include<parcels.cpp>

#define NUMBEROFWORKERS 3
#define NUMBER_THREADS 8
#define NUMBER_BLOCKS 1


// std::mutex rcl_mutex;
void pushGlobalRcl(Parcel parcel , int thread_index , Rcl *rcl){
    rcl->parcels[thread_index] = parcel;
}


void parellelConstructionPhase(vector<Parcel> *parcels , vector<Parcel> *path){
    
    Cordinate position;
    
    Rcl hgrcl;
    
    Parcel d_parcels = &parcels.parcels[0]
    
    Rcl dgrcl;
    //MALLOC DEVICE MEMORY SPACE    
    cudaMalloc((void**)&d_parcels, parcels.parcels.size() * sizeof(Parcel));
    cudaMalloc((void**)&dgrcl, NUMBER_THREADS * sizeof(SelectParcel));
    
    // cudaMalloc(&h_parcels, sizeof(parcels));
    cudaMemcpy(d_parcels, h_parcels, h_parcels.size() * sizeof(Parcel), cudaMemcpyHostToDevice);
    cudaMemcpy(dgrcl, hgrcl, NUMBER_THREADS * sizeof(SelectParcel), cudaMemcpyHostToDevice);

    
    //Cuda malloc list Rcl
    while(parcels.size() > 0){
        float min = calculateMin(position , parcels);
        float max = calculateMax(position , parcels);
        float item = min + ALPHA*(max - min);
        
        //Copy list memory to Device 
        
        //host to device 

        //start Kernels

        SelectionPhase<<< NUMBER_THREADS , NUMBER_BLOCKS >>>(&d_parcels , &dgrcl , position);

        //wait Kernel end
        cudaDeviceSychronize();

        int elem = randBetweenInt(0 , hgrcl->parcels.size());

        Parcel selectedParcel = h_g_rcl[elem];
        path[path.size()] = selectParcel;
        *parcels = removeParcel(parcels , selectParcel.index); 
        printf("the length of path %d\n" , (int )path->parcels.size());
        printf("the length of parcels %d\n" , (int )parcels->parcels.size());
        
        position.latitude = selectedParcel.parcel.latitude;
        position.longitude = selectedParcel.parcel.longitude;

        rcl.clear();

    }
}



