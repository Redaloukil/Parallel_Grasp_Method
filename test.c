#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <math.h>
#include<time.h>
#include<regex.h>

#include"parcel.c"

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
    List parcels;

    parcels = initializeChainedList(parcels);
    
    Parcel parcel0;parcel0.recovered =0; parcel0.latitude = 2; parcel0.longitude = 3; parcel0.key="abcdea";
    Parcel parcel1;parcel1.recovered =0; parcel1.latitude = 1; parcel1.longitude = 6; parcel1.key="edcbzf";
    Parcel parcel2;parcel2.recovered =0; parcel2.latitude = -3; parcel2.longitude = 8; parcel2.key="kjfsqh";
    Parcel parcel3;parcel3.recovered =0; parcel3.latitude = 9; parcel3.longitude = 2; parcel3.key="pkmkza";
    Parcel parcel4;parcel4.recovered =0; parcel4.latitude = 4; parcel4.longitude = 5; parcel4.key="pfdgga";
    
    // parcels = generateParcels(&parcels);
    parcels = addParcelAtEndChained(parcels , parcel0);
    parcels = addParcelAtEndChained(parcels , parcel1);
    parcels = addParcelAtEndChained(parcels , parcel2);
    parcels = addParcelAtEndChained(parcels , parcel3);
    parcels = addParcelAtEndChained(parcels , parcel4);

    List node;
    node = parcels;

    

    deleteParcel(parcels , parcel3.key);
    
    node = parcels;

    while(node !=NULL){
        printf("%s\n",node->parcel.key);
        node = node->nextParcel;
    }

    return 0;
}