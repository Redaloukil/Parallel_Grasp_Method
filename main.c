#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <math.h>
#include<time.h>
#include<regex.h>

#include"parcel.c"


#define STARTPOINT 0
#define WORKERS_NUM 4 
#define ALPHA 0.3
#define CURRENTLAT 0
#define CURRENTLON 0


int main(){
    clock_t t;
    
    int listSpot;

    Parcels parcels;
    Parcels path;
    
    //start execution time
    t = clock();
    
    // char *s;
    // gen_random(&s , 10);
    // printf("%c" , s);
    parcels = initializeList(&parcels);
    
    Parcel parcel0;parcel0.recovered =0; parcel0.latitude = 2; parcel0.longitude = 3; parcel0.key="abcdea";
    Parcel parcel1;parcel1.recovered =0; parcel1.latitude = 1; parcel1.longitude = 6; parcel1.key="edcbzf";
    Parcel parcel2;parcel2.recovered =0; parcel2.latitude = -3; parcel2.longitude = 8; parcel2.key="kjfsqh";
    Parcel parcel3;parcel3.recovered =0; parcel3.latitude = 9; parcel3.longitude = 2; parcel3.key="pkmkza";
    Parcel parcel4;parcel4.recovered =0; parcel4.latitude = 4; parcel4.longitude = 5; parcel4.key="pfdgga";
    
    // parcels = generateParcels(&parcels);
    parcels = addParcelAtEnd(&parcels , parcel0 );
    parcels = addParcelAtEnd(&parcels , parcel1 );
    parcels = addParcelAtEnd(&parcels , parcel2 );
    parcels = addParcelAtEnd(&parcels , parcel3 );
    parcels = addParcelAtEnd(&parcels , parcel4 );
    
    


    for(int i=0;i<parcels.numberParcels;i++){
        printf("%d" , i);
        printf("latitude : %f ,longitude : %f ,key : %s\n" ,parcels.parcels[i].latitude ,parcels.parcels[i].longitude , parcels.parcels[i].key );
    }
    
    path = constructionPhase(&parcels , &path);
    

    t = clock() - 1;
    //end execution time
    double execution_time = ((double)t);
    printf("it takes %f ms to execute", execution_time);
    return 0;
}