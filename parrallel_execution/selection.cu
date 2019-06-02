#include <stdio.h>

#include <cuda_runtime_api.h>
#include <cuda.h>
// vector::push_back
#include<iostream>
#include"parcel.cpp"
#include<vector>
#include<algorithm>

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
    rcl->parcels[t] = selectedParcel;
    
    
}  