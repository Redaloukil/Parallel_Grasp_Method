#include <stdio.h>

#include <cuda_runtime_api.h>
#include <cuda.h>
// vector::push_back
#include<iostream>
#include"parcel.cpp"
#include<vector>
#include<algorithm>

#define PARCELS_NUMBER 30

using namespace std;



int main ()
{ 

    //start execution time
    t = clock();
    
    // char *s;
    // gen_random(&s , 10);
    // printf("%c" , s);
    Parcels parcels;
    Parcels path;
   
    // Parcels *d_parcels;


    // read te file 



    parcels = initializeList(&parcels);
    
    Parcel parcel1 ;parcel1.latitude = 2216.6667 ;parcel1.longitude = 1516.6667;
    Parcel parcel2 ;parcel2.latitude = 2233.3333 ;parcel2.longitude = 1566.6667;
    Parcel parcel3 ;parcel3.latitude = 2366.6667 ;parcel3.longitude = 1633.3333;
    Parcel parcel4 ;parcel4.latitude = 2500.0000 ;parcel4.longitude = 1883.3333;
    Parcel parcel5 ;parcel5.latitude = 2516.6667 ;parcel5.longitude = 1866.6667;
    Parcel parcel6 ;parcel6.latitude = 2600.0000 ;parcel6.longitude = 2333.3333;
    Parcel parcel7 ;parcel7.latitude = 2616.6667 ;parcel7.longitude = 1950.0000;
    Parcel parcel8 ;parcel8.latitude = 2616.6667 ;parcel8.longitude = 2416.6667;
    Parcel parcel9 ;parcel9.latitude = 2633.3333 ;parcel9.longitude = 1950.0000;
    Parcel parcel10; parcel10.latitude = 22633.3333 ;parcel10.longitude = 32266.6667;
    Parcel parcel11; parcel11.latitude = 22650.0000 ;parcel11.longitude = 32016.6667;
    Parcel parcel12; parcel12.latitude = 22650.0000 ;parcel12.longitude = 32383.3333;
    Parcel parcel13; parcel13.latitude = 22716.6667 ;parcel13.longitude = 32066.6667;
    Parcel parcel14; parcel14.latitude = 22733.3333 ;parcel14.longitude = 32166.6667;
    Parcel parcel15; parcel15.latitude = 22750.0000 ;parcel15.longitude = 32133.3333;
    Parcel parcel16; parcel16.latitude = 22750.0000 ;parcel16.longitude = 32566.6667;
    Parcel parcel17; parcel17.latitude = 22766.6667 ;parcel17.longitude = 32516.6667;
    Parcel parcel18; parcel18.latitude = 22866.6667 ;parcel18.longitude = 32583.3333;
    Parcel parcel19; parcel19.latitude = 22983.3333 ;parcel19.longitude = 32650.0000;
    Parcel parcel20; parcel20.latitude = 23050.0000 ;parcel20.longitude = 32683.3333;
    Parcel parcel21; parcel21.latitude = 23050.0000 ;parcel21.longitude = 32733.3333;
    Parcel parcel22; parcel22.latitude = 23083.3333 ;parcel22.longitude = 32683.3333;
    Parcel parcel23; parcel23.latitude = 23133.3333 ;parcel23.longitude = 32750.0000;
    Parcel parcel24; parcel24.latitude = 23166.6667 ;parcel24.longitude = 32733.3333;
    Parcel parcel25; parcel25.latitude = 23166.6667 ;parcel25.longitude = 32766.6667;
    Parcel parcel26; parcel26.latitude = 23200.0000 ;parcel26.longitude = 32750.0000;
    Parcel parcel27; parcel27.latitude = 23200.0000 ;parcel27.longitude = 32833.3333;
    Parcel parcel28; parcel28.latitude = 23266.6667 ;parcel28.longitude = 32933.3333;
    Parcel parcel29; parcel29.latitude = 23283.3333 ;parcel29.longitude = 32866.6667;
    Parcel parcel30; parcel30.latitude = 23383.3333 ;parcel30.longitude = 32950.0000;
    Parcel parcel31; parcel31.latitude = 23400.0000 ;parcel31.longitude = 32933.3333;
    Parcel parcel32; parcel32.latitude = 23433.3333 ;parcel32.longitude = 32900.0000;
    Parcel parcel33; parcel33.latitude = 23483.3333 ;parcel33.longitude = 32883.3333;
    Parcel parcel34; parcel34.latitude = 23533.3333 ;parcel34.longitude = 32883.3333;
    Parcel parcel35; parcel35.latitude = 23550.0000 ;parcel35.longitude = 32866.6667;
    Parcel parcel36; parcel36.latitude = 23550.0000 ;parcel36.longitude = 32883.3333;
    Parcel parcel37; parcel37.latitude = 23666.6667 ;parcel37.longitude = 32883.3333;
    Parcel parcel38; parcel38.latitude = 23683.3333 ;parcel38.longitude = 32883.3333;
    Parcel parcel39; parcel39.latitude = 23783.3333 ;parcel39.longitude = 32916.6667;
    Parcel parcel40; parcel40.latitude = 23866.6667 ;parcel40.longitude = 32900.0000;
    // Parcel parcel0; parcel0.latitude = 2; parcel0.longitude = 3;
    // Parcel parcel1; parcel1.latitude = 1; parcel1.longitude = 6; 
    // Parcel parcel2; parcel2.latitude = -3; parcel2.longitude = 8; 
    // Parcel parcel3; parcel3.latitude = 9; parcel3.longitude = 2; 
    // Parcel parcel4; parcel4.latitude = 4; parcel4.longitude = 5; 
    // Parcel parcel5; parcel5.latitude = 3; parcel5.longitude = 5;
    // Parcel parcel6; parcel6.latitude = 1; parcel6.longitude = 7; 
    // Parcel parcel7; parcel7.latitude = -1; parcel7.longitude = 2; 
    // Parcel parcel8; parcel8.latitude = 3; parcel8.longitude = 2; 
    // Parcel parcel9; parcel9.latitude = 0; parcel9.longitude = 5; 
    // Parcel parcel10; parcel10.latitude = 10; parcel10.longitude = 2;
    // Parcel parcel11; parcel11.latitude = 4; parcel11.longitude = 6; 
    // Parcel parcel12; parcel12.latitude = -3; parcel12.longitude = 3; 
    // Parcel parcel13; parcel13.latitude = 9; parcel13.longitude = 2; 
    // Parcel parcel14; parcel14.latitude = 4; parcel14.longitude = 0; 
    // Parcel parcel15; parcel15.latitude = 3; parcel15.longitude = 0;
    // Parcel parcel16; parcel16.latitude = 4; parcel16.longitude = 8; 
    
    // parcels = generateParcels(&parcels);
    parcels = addParcelAtEnd(&parcels , parcel1);
    parcels = addParcelAtEnd(&parcels , parcel2);
    parcels = addParcelAtEnd(&parcels , parcel3);
    parcels = addParcelAtEnd(&parcels , parcel4);
    parcels = addParcelAtEnd(&parcels , parcel5);
    parcels = addParcelAtEnd(&parcels , parcel6);
    parcels = addParcelAtEnd(&parcels , parcel7);
    parcels = addParcelAtEnd(&parcels , parcel8);
    parcels = addParcelAtEnd(&parcels , parcel9);
    parcels = addParcelAtEnd(&parcels , parcel10);
    parcels = addParcelAtEnd(&parcels , parcel11);
    parcels = addParcelAtEnd(&parcels , parcel12);
    parcels = addParcelAtEnd(&parcels , parcel13);
    parcels = addParcelAtEnd(&parcels , parcel14);
    parcels = addParcelAtEnd(&parcels , parcel15);
    parcels = addParcelAtEnd(&parcels , parcel16);
    parcels = addParcelAtEnd(&parcels , parcel17);
    parcels = addParcelAtEnd(&parcels , parcel18);
    parcels = addParcelAtEnd(&parcels , parcel19);
    parcels = addParcelAtEnd(&parcels , parcel20);
    parcels = addParcelAtEnd(&parcels , parcel21);
    parcels = addParcelAtEnd(&parcels , parcel22);
    parcels = addParcelAtEnd(&parcels , parcel23);
    parcels = addParcelAtEnd(&parcels , parcel24);
    parcels = addParcelAtEnd(&parcels , parcel25);
    parcels = addParcelAtEnd(&parcels , parcel26);
    parcels = addParcelAtEnd(&parcels , parcel27);
    parcels = addParcelAtEnd(&parcels , parcel28);
    parcels = addParcelAtEnd(&parcels , parcel29);
    parcels = addParcelAtEnd(&parcels , parcel30);
    parcels = addParcelAtEnd(&parcels , parcel31);
    parcels = addParcelAtEnd(&parcels , parcel32);
    parcels = addParcelAtEnd(&parcels , parcel33);
    parcels = addParcelAtEnd(&parcels , parcel34);
    parcels = addParcelAtEnd(&parcels , parcel35);
    parcels = addParcelAtEnd(&parcels , parcel36);
    parcels = addParcelAtEnd(&parcels , parcel37);
    parcels = addParcelAtEnd(&parcels , parcel38);
    parcels = addParcelAtEnd(&parcels , parcel39);
    parcels = addParcelAtEnd(&parcels , parcel40);
    
    
    //parcels malloc 
    vector<Parcel> h_parcels = parcels.parcels;
    vector<Parcel> h_path;
    // Rcl global_rcl;
    
    // Parcel d_parcels = &parcels.parcels[0]
    // Parcel d_path = &parcels.parcels[0]
    // // h_parcels = (Parcels*)malloc(1*sizeof(Parcels));
    
    
    // cudaMalloc((void**)&d_parcels, parcels.parcels.size() * sizeof(Parcel));
    // cudaMalloc((void**)&d_path, parcels.parcels.size() * sizeof(Parcel)); 	
    // // cudaMalloc(&h_parcels, sizeof(parcels));
    // cudaMemcpy(d_parcels, h_parcels, h_parcels.size() * sizeof(Parcel), cudaMemcpyHostToDevice);
    // cudaMemcpy(d_path, h_parcels, h_parcels.size() * sizeof(Parcel), cudaMemcpyHostToDevice);
    

    printf("%d" , d_parcels.size());
    parellelConstructionPhase(&h_parcels , &h_path);
    
    


    // printf("%d" ,(int)h_path->parcels.size());
    
    // for (int i=0;i<(int)h_parcels->parcels.size();i++){
    //     printf("%f \n"  ,(float) h_parcels->parcels[i].latitude);
    // }
    // for (int i=0;i<(int)h_parcels.size();i++){
    //     printf("%f \n"  ,(float) h_parcels[i].latitude);
    // }
    
    return 0;

}