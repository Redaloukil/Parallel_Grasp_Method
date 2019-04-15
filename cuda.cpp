#include<iostream>
#include<vector>
#include<math.h>
#include<parcels.cpp>

#define NUMBEROFWORKERS 3

// __global__
// void parallelMinCalculation(Parcels parcels){
//     min = getMinValue(parcels);

// }


void pushGlobalRcl(){
    // mutual exclusion condition
    while(){

    }
}
__GLOBAL__
void SelectionPhase(Parcels *parcels , Rcl *rcl ,Cordinate position){
    float min = calculateMin(position , parcels);
    float max = calculateMax(position , parcels);

    float item = min + ALPHA*(max - min);

    Rcl localRcl;     
    
    int t = threadIdx.x;
    int T = blockDim.x;
    
    for (int i = t;i<parcels->parcels.size(); i += NUMBEROFWORKERS){
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
    pushGlobalRcl(rcl , localRcl->parcels[cbegin() + elem]);

}   


void parellelConstructionPhase(Parcels parcels){
    Rcl rcl;
    rcl = initializeRCList(&rcl);
    while(parcels > 0){
        rcl = SelectionPhase(parcels , rcl)
    }
}

