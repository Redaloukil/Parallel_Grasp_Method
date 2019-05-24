#include<iostream>
#include<vector>
#include<math.h>
#include<parcels.cpp>

#define NUMBEROFWORKERS 3



// std::mutex rcl_mutex;
void pushGlobalRcl(Parcel parcel , int thread_index , Rcl rcl){
    rcl->parcels[thread_index] = parcel;

}


__GLOBAL__ 
void SelectionPhase(Parcels *parcels ,Rcl *rcl  ,Cordinate position){
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
            SelectParcel parcel;parcel.index = index;parcel.parcel = parcels->parcels[i];
            printf(" selected\n");
            localRcl->parcels.push_back(parcel);
        }else {
            printf(" not selected\n");
        }
    }
    //select randomly from rcl
    int elem = randBetweenInt(0 , rcl->parcels.size());
    Parcel selectedParcel = rcl->parcels[elem];
    
    //push selected parcel to the global rcl 
    pushGlobalRcl(selectedParcel ,t , rcl);
}   


void parellelConstructionPhase(vector<Parcel> parcels){
    Rcl rcl;
    //Cuda malloc list Rcl
    while(parcels.size() > 0){
        float min = calculateMin(position , parcels);
        float max = calculateMax(position , parcels);
        
        float item = min + ALPHA*(max - min);
        //Copy list memory to Device 
        
        //host to device 
        //start Kernels
        SelectionPhase<<<NUMBEROFWORKERS , 1 >>>(parcels , rcl);
        //wait Kernel end
        cudaDeviceSychronize();
    }
}



