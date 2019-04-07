#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define STARTPOINT 0
#define WORKERS_NUM 4 
#define ALPHA 0.3
#define CURRENTLAT 1.2
#define CURRENTLON 2.2
#define PARCELSNUMBER 20

typedef struct Parcel {
    char  *key;
    float longitude;
    float latitude;
}Parcel;

typedef struct Pnode Pnode;

struct Pnode {
    Parcel parcel;
    struct Pnode *nextParcel;
};
 
typedef struct Cordinate {
    float latitude;
    float longitude;
}Cordinate;

//Array list representation
typedef struct Parcels {   
    int numberParcels;
    Parcel parcels[1000];
}Parcels;

//chained list representation 
typedef struct Pnode *List;


float square(float number){
    return number*number;
}
//Array list 
Parcel initializeParcel(float latitude , float longitude , char *id){
    Parcel parcel;
    
    parcel.latitude = latitude;
    parcel.longitude = longitude;
    return parcel;
}

Parcels initializeList(Parcels parcels){
    parcels.numberParcels = 0;
    return parcels;
}

Parcels addParcelAtEnd(Parcels *parcels , Parcel parcel) {
    parcels->parcels[parcels->numberParcels] = parcel;
    parcels->numberParcels++;
    return *parcels;
}
Parcels deleteParcelAtEnd(Parcels *parcels) {
    parcels->numberParcels--;
    return *parcels;
}

List addParcelAtBegChained(List liste, Parcel parcel) {
    /* On crée un nouvel élément */
    Pnode* e = malloc(sizeof(Pnode));
    /* On assigne la valeur au nouvel élément */
    e->parcel = parcel;
    /* On assigne l'adresse de l'élément suivant au nouvel élément */
    e->nextParcel = NULL;
    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return e;
}

List addParcelAtEndChained(List list, Parcel parcel) {
    /* On crée un nouvel élément */
    Pnode* e = malloc(sizeof(Pnode));
    /* On assigne la valeur au nouvel élément */
    e->parcel = parcel;
    /* On ajoute en fin, donc aucun élément ne va suivre */
    e->nextParcel = NULL;
 
    if(list == NULL){
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return e;
    }else{
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        Pnode *temp= list;
        while(temp->nextParcel != NULL){
            temp = temp->nextParcel;   
        }
        temp->nextParcel = e;
        
        return list;
    }
}
//remove index from list 
List removeWithIndex(List list , int i){
    int j;
    Pnode *temp = list;
    while(j<i){
        temp = temp->nextParcel;
        j++;
    }
    
    return list;
}

//rand between integer
int randBetweenInt(int min , int max ) {
    return ((int)rand()/RAND_MAX) * (max - min) + min;
}

//rand between float 
float randBetweenFloat(int min , int max ) {
    return ((float)rand()/RAND_MAX) * (max - min) + min;
}

//calculate the cost between current and next point 
float calculateCost(Parcel nextPoint , Cordinate startPoint){
    return sqrtf(square(nextPoint.longitude - startPoint.longitude) + square(nextPoint.latitude - startPoint.latitude));
}

void *rand_string(char *str){
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU";
    int num;
    for (int n = 0; n < 6; n++)
    {
        printf("num : %d\n", num);
        str[n] = charset[num];
    }
    str[6] = '\0';
}

//generate random parcels in specific geo area 
Parcels generateParcels(Parcels *parcels){
     for(int i=0;i<PARCELSNUMBER;i++){
        char s[7];
        rand_string(s);
        Parcel parcel;
        parcel.key = s;
        parcel.latitude = randBetweenFloat(1 , 3);
        parcel.longitude = randBetweenFloat(2 , 8);
        *parcels = addParcelAtEnd(parcels , parcel);
    }
    return *parcels; 
}

//calculate Min
float calculateMin(Cordinate startPoint , Parcels parcels){
    float min = calculateCost(parcels.parcels[0],startPoint);
    int index = 0;
    for(int i=1; i<parcels.numberParcels;i++){
        if(calculateCost(parcels.parcels[i],startPoint) < min){
            min = calculateCost(parcels.parcels[i] ,startPoint );
            index = i;
        } 
    }
    return min;
}


float calculateMax(Cordinate startPoint , Parcels parcels){
    float max = calculateCost(parcels.parcels[0],startPoint);
    int index = 0;
    for(int i=1; i<parcels.numberParcels;i++){
        if(calculateCost(parcels.parcels[i], startPoint) > max){
            max = calculateCost(parcels.parcels[i] , startPoint );
            index = i;
        } 
    }   
    return max;
}

Parcels selectParcel(Parcels parcels ,Cordinate position){
    Parcels rcl;
    float min = calculateMin(position , parcels);
    float max = calculateMax(position , parcels);
    float item = min + ALPHA*(max - min);
    

    for(int i=0; i<parcels.numberParcels;i++){
        float cost = calculateCost(parcels.parcels[i],position);
        if(cost < item){
            rcl.parcels[rcl.numberParcels] = parcels.parcels[i];
        }
    }
    return rcl;
}

void constructionPhase(Parcels parcels ,Parcels path){
    Cordinate position;
    position.latitude = CURRENTLAT;
    position.longitude = CURRENTLON;
    while(parcels.numberParcels > 0){
        Parcels rcl;
        rcl = selectParcel(parcels , position);
        Parcel selectedParcel = rcl.parcels[0];
        path.parcels[path.numberParcels] = selectedParcel;
        path.numberParcels++;
        position.latitude = selectedParcel.latitude;
        position.longitude = selectedParcel.longitude;
    }
}




Parcel randomSelect(Parcels rcl){
    
}

