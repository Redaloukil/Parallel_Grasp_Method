#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define STARTPOINT 0
#define WORKERS_NUM 4 
#define ALPHA 0.3
#define CURRENTLAT 0
#define CURRENTLON 0
#define PARCELSNUMBER 20

typedef struct Parcel {
    int recovered;
    char  *key;
    float longitude;
    float latitude;
}Parcel;