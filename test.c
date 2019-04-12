#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <math.h>
#include<time.h>
#include<regex.h>

#include"parcel.c"

#define ALPHA 0.3

// void *rand_string(char *str)
// {
//     srand(time(NULL));
//     const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU";
//     int num;
//     for (int n = 0; n < 6; n++)
//     {
//         num = (rand() % (sizeof(charset)));
//         printf("num : %d\n", num);
//         str[n] = charset[num];
//     }
//     str[6] = '\0';
// }

int main()
{
    // List parcels;
    Parcels parcels;

    parcels = initializeList(&parcels);

    
    
    Parcel parcel0;parcel0.recovered =0; parcel0.latitude = 2; parcel0.longitude = 3; parcel0.key="abcdea";
    Parcel parcel1;parcel1.recovered =0; parcel1.latitude = 1; parcel1.longitude = 6; parcel1.key="edcbzf";
    Parcel parcel2;parcel2.recovered =0; parcel2.latitude = -3; parcel2.longitude = 8; parcel2.key="kjfsqh";
    Parcel parcel3;parcel3.recovered =0; parcel3.latitude = 9; parcel3.longitude = 2; parcel3.key="pkmkza";
    Parcel parcel4;parcel4.recovered =0; parcel4.latitude = 4; parcel4.longitude = 5; parcel4.key="pfdgga";
    
    // parcels = generateParcels(&parcels);
    parcels = addParcelAtEnd(&parcels , parcel0);
    parcels = addParcelAtEnd(&parcels , parcel1);
    parcels = addParcelAtEnd(&parcels , parcel2);
    parcels = addParcelAtEnd(&parcels , parcel3);
    parcels = addParcelAtEnd(&parcels , parcel4);

    
    Cordinate cordinate;
    cordinate.latitude = CURRENTLAT;
    cordinate.longitude = CURRENTLON;

    float a = calculateMin(cordinate , parcels);
    float b = calculateMax(cordinate , parcels);

    float d0 = calculateCost(parcel0 , cordinate);
    float d1 = calculateCost(parcel1 , cordinate);
    float d2 = calculateCost(parcel2 , cordinate);
    float d3 = calculateCost(parcel3 , cordinate);
    float d4 = calculateCost(parcel4 , cordinate);

    float cost = a + ALPHA*(b-a);

    printf("the const %f\n",cost);
    printf("mix cost %f\n",a);
    printf("Max cost %f\n"  ,b);

    printf("parcel0 cost %f\n"  ,d0);
    printf("parcel1 cost %f\n"  ,d1);
    printf("parcel2 cost %f\n"  ,d2);
    printf("parcel3 cost %f\n"  ,d3);
    printf("parcel4 cost %f\n"  ,d4);
    


    parcels = removeParcel(&parcels , parcel0.key);

    cordinate.longitude = parcel0.longitude;
    cordinate.latitude = parcel0.latitude;

    float aa = calculateMin(cordinate , parcels);
    float ba = calculateMax(cordinate , parcels);

    
    float d1a = calculateCost(parcel1 , cordinate);
    float d2a = calculateCost(parcel2 , cordinate);
    float d3a = calculateCost(parcel3 , cordinate);
    float d4a = calculateCost(parcel4 , cordinate);

    float costa = aa + (ALPHA*(ba-aa));

    printf("the const %f\n",costa);
    printf("mix cost %f\n",aa);
    printf("Max cost %f\n"  ,ba);

    
    printf("parcel1 cost %f\n"  ,d1a);
    printf("parcel2 cost %f\n"  ,d2a);
    printf("parcel3 cost %f\n"  ,d3a);
    printf("parcel4 cost %f\n"  ,d4a);
    
    // parcels = removeParcel(&parcels , parce );
    // List node;
    // node = parcels;

    

    // deleteParcel(parcels , parcel3.key);
    
    // node = parcels;

    // while(node !=NULL){
    //     printf("%s\n",node->parcel.key);
    //     node = node->nextParcel;
    // }


    


    return 0;
}