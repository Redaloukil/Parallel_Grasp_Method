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
    //malloc a list local rcl
    Rcl localRcl;
    
    
    int t = threadIdx.x;
    int T = blockDim.x;
    
    
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
    //push selected parcel to the global rcl 
    pushGlobalRcl();
}   


void parellelConstructionPhase(Parcels parcels){
    Rcl rcl;
    cuda
    
    while(parcels > 0){
        float min = calculateMin(position , parcels);
        float max = calculateMax(position , parcels);
        
        float item = min + ALPHA*(max - min);

        SelectionPhase<<<NUMBEROFWORKERS , 1 >>>(parcels , rcl);
        
        float item = min + ALPHA*(max - min);
    }
}



