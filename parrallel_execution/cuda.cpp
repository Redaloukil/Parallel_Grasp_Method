#include<iostream>

#include<math.h>
#include<parcels.cpp>

#define NUMBEROFWORKERS 3
#define NUMBER_THREADS 8
#define NUMBER_BLOCKS 1


// std::mutex rcl_mutex;
// void pushGlobalRcl(Parcel parcel , int thread_index , Rcl *rcl){
//     rcl->parcels[thread_index] = parcel;
// }


void parellelConstructionPhase(thrust::host_vector<Parcel> parcels , thrust::host_vector<Parcel> path){
    Cordinate *d_position , *h_position;
    
    Cordinate position;


    //Memory copy candidate list to device
    thrust::device_parcels<Parcel> d_parcels = parcels;
    
    Cordinate *h_position , *d_position;

    
    
    
    h_position->latitude = 31074.4444; 
    h_position->longitude = 31706.3889;

    d_position  = (Cordinate*)malloc(sizeof(Cordinate));

    d_position->latitude = 31074.4444;
    h_position->longitude = 31706.3889;
    
    cudaMemcpy(p_hgpu->pass, p->pass, sizeof(int) * 5, cudaMemcpyHostToDevice);

    thrust::host_rcl<SelectParcel> HostRcl(NUMBER_THREADS) = parcels;
    thrust::device_rcl<SelectParcel> DeviceRcl(NUMBER_THREADS) = HostRcl;

    
    
    //MALLOC DEVICE MEMORY SPACE    
    
    
    // cudaMalloc(&h_parcels, sizeof(parcels));
    
    
    //Cuda malloc list Rcl
    while(parcels.size() > 0){
        float min = calculateMin(position , parcels);
        float max = calculateMax(position , parcels);
        float item = min + ALPHA*(max - min);
        
        // Copy list memory to Device 
        
        //host to device 

        //start Kernels
        SelectionPhase<<< NUMBER_THREADS , NUMBER_BLOCKS >>>(&d_parcels , &dgrcl , position);
        
        //wait Kernel end
        cudaDeviceSychronize();

        //Cuda memory copy from device to host
        cudaMemcpy(d_parcels, h_parcels, h_parcels.size() * sizeof(Parcel), cudaMemcpyHostToDevice);
        cudaMemcpy(dgrcl, hgrcl, NUMBER_THREADS * sizeof(SelectParcel), cudaMemcpyHostToDevice);
        
        int elem = randBetweenInt(0 , hgrcl->parcels.size());

        Parcel selectedParcel = h_g_rcl[elem];
        path[path.size()] = selectParcel;
        *parcels = removeParcel(parcels , selectParcel.index); 
        printf("the length of path %d\n" , (int )path->parcels.size());
        printf("the length of parcels %d\n" , (int )parcels->parcels.size());
        
        position.latitude = selectedParcel.parcel.latitude;
        position.longitude = selectedParcel.parcel.longitude;

        hgrcl.clear();

    }
}



