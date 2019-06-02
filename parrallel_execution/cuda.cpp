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


__GLOBAL__ 
void SelectionPhase(vector<Parcel> *parcels ,Rcl *rcl  ,Cordinate position){
    //malloc a list local restricted candidates list
    Rcl localRcl;
    
    //thread block dimentions 
    int t = threadIdx.x;
    int T = blockDim.x;

    //map function : for each evaluate cost and push to local rcl
    for (int i = t;i<parcels->parcels.size(); i += T){
        float cost = calculateCost(position , parcels->parcels[i]);
        if(cost <= item){
            int index = i;
            SelectParcel parcel;parcel.index = index;
            parcel.parcel = parcels->parcels[i];
            printf("selected\n");
            localRcl->parcels.push_back(parcel);
        }else {
            printf("not selected\n");
        }
    }
    //select randomly from rcl
    int elem = randBetweenInt(0 , rcl->parcels.size());
    Parcel selectedParcel = rcl->parcels[elem];
    
    //push selected parcel to the global rcl 
    pushGlobalRcl(selectedParcel ,t , &rcl);
}   


void parellelConstructionPhase(vector<Parcel> *parcels , vector<Parcel> *path){
    Rcl rcl;
    Cordinate position;
    
    Rcl h_g_rcl;
    
    Parcel d_parcels = &parcels.parcels[0]
    
    Rcl d_g_rcl;
    //MALLOC DEVICE MEMORY SPACE    
    cudaMalloc((void**)&d_parcels, parcels.parcels.size() * sizeof(Parcel));
    cudaMalloc((void**)&d_g_rcl, NUMBER_THREADS * sizeof(SelectParcel));
    // cudaMalloc(&h_parcels, sizeof(parcels));
    cudaMemcpy(d_parcels, h_parcels, h_parcels.size() * sizeof(Parcel), cudaMemcpyHostToDevice);
    cudaMemcpy(d_g_rcl, h_g_rcl, NUMBER_THREADS * sizeof(SelectParcel), cudaMemcpyHostToDevice);

    
    //Cuda malloc list Rcl
    while(parcels.size() > 0){
        float min = calculateMin(position , parcels);
        float max = calculateMax(position , parcels);
        float item = min + ALPHA*(max - min);
        
        //Copy list memory to Device 
        
        //host to device 
        //start Kernels
        SelectionPhase<<< NUMBER_THREADS , NUMBER_BLOCKS >>>(d_parcels , d_g_rcl , position);
        //wait Kernel end
        cudaDeviceSychronize();
        int elem = randBetweenInt(0 , rcl->parcels.size());
        Parcel selectedParcel = rcl->parcels[elem];
        path[path.size()] = selectParcel;
        *parcels = removeParcel(parcels , selectParcel.index); 
        printf("the length of path %d\n" , (int )path->parcels.size());
        printf("the length of parcels %d\n" , (int )parcels->parcels.size());
        
        position.latitude = selectedParcel.parcel.latitude;
        position.longitude = selectedParcel.parcel.longitude;

        rcl.clear();

    }
}



