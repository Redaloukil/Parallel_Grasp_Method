#include<iostream>
#include<vector>
#include<math.h>
#include<time.h>


#define STARTPOINT 0
#define WORKERS_NUM 4 
#define ALPHA 0.3
#define CURRENTLAT 0
#define CURRENTLON 0
#define PARCELSNUMBER 20

typedef struct Cordinate {
    float latitude;
    float longitude;
}Cordinate;

typedef struct Parcel {
    int recovered;
    char  *key;
    float longitude;
    float latitude;
}Parcel;

//Array list representation
typedef struct Parcels {   
    std::vector<Parcel> parcels;
}Parcels;

float square(float number){
    float a = number*number; 
    return a;
}

//Array list 
Parcel initializeParcel(float latitude , float longitude , char *id){
    Parcel parcel;
    
    parcel.latitude = latitude;
    parcel.longitude = longitude;
    return parcel;
}

Parcels initializeList(Parcels *parcels){
    parcels->parcels.clear();
    return *parcels;
}

Parcels addParcelAtEnd(Parcels *parcels , Parcel parcel) {
    parcels->parcels.push_back(parcel);
    return *parcels;
}

Parcels deleteParcelAtEnd(Parcels *parcels) {
    parcels->parcels.erase(parcels->parcels.cbegin());
    return *parcels;
}

int randBetweenInt(int min , int max ) {
    srand (time(NULL));
    return ((int)rand()/RAND_MAX) * (max - min) + min;
}

//rand between float 
float randBetweenFloat(int min , int max ) {
    srand (time(NULL));
    return ((float)rand()/RAND_MAX) * (max - min) + min;
}

//calculate the cost between current and next point 
float calculateCost(Parcel nextPoint , Cordinate startPoint){
    float b = (square(nextPoint.longitude - startPoint.longitude)) + (square(nextPoint.latitude - startPoint.latitude));
    return sqrt(b);
}

void rand_string(char *str){
    srand (time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU";
    int num;
    for (size_t n = 0; n < 6; n++){
        num = (rand() % (sizeof(charset)));
        str[n] = charset[num];
    }
    str[6] = '\0';
}


//generate random parcels in specific geo area 
Parcels generateParcels(Parcels *parcels){
     for(int i=0;i<PARCELSNUMBER;i++){
        Parcel parcel;
        // rand_string(parcel.key);
        parcel.latitude = randBetweenFloat(1 , 3);
        parcel.longitude = randBetweenFloat(2 , 8);
        *parcels = addParcelAtEnd(parcels , parcel);
    }
    return *parcels; 
}


//calculate Min
float calculateMin(Cordinate startPoint , Parcels *parcels){
    float min = calculateCost(parcels->parcels[0],startPoint);
    
    
    for(unsigned int i=1; i<parcels->parcels.size();i++){
        if(calculateCost(parcels->parcels[i],startPoint) < min){
            min = calculateCost(parcels->parcels[i] ,startPoint);
            
        } 
    }
    return min;
}


float calculateMax(Cordinate startPoint , Parcels *parcels){
    float max = calculateCost(parcels->parcels[0],startPoint);
    
    
    for(unsigned int i=1; i<parcels->parcels.size();i++){
        if(calculateCost(parcels->parcels[i], startPoint) > max){
            max = calculateCost(parcels->parcels[i] , startPoint );
           
        } 
    }   
    return max;
}

//this procedure is KERNEL
Parcels selectParcel(Parcels *parcels , Parcels *rcl ,Cordinate position){
    float min = calculateMin(position , parcels);
    float max = calculateMax(position , parcels);

    float item = min + ALPHA*(max - min);
    std::cout << "the constant is " << item << "\n";
    for(unsigned int i=0; i<parcels->parcels.size();i++){
        
            float cost = calculateCost(parcels->parcels[i],position);
            printf("%f" , cost);
            if(cost < item){
                printf(" selected\n");
                addParcelAtEnd(rcl , parcels->parcels[i]);
            }
            
        }
    
    return *rcl;
}
