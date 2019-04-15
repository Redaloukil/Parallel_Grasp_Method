#include"parcels.cpp"

float square(float number)

Parcel initializeParcel(float latitude , float longitude , char *id)

Parcels initializeList(Parcels *parcels)

Rcl initializeRCList(Rcl *rcl)

Parcels addParcelAtEnd(Parcels *parcels , Parcel parcel)

Parcels deleteParcelAtEnd(Parcels *parcels)

int randBetweenInt(int min , int max)

float randBetweenFloat(int min , int max)

float calculateCost(Parcel nextPoint , Cordinate startPoint)

void rand_string(char *str)

Parcels generateParcels(Parcels *parcels)

float calculateMin(Cordinate startPoint , Parcels *parcels)

float calculateMax(Cordinate startPoint , Parcels *parcels)

Parcels removeParcel(Parcels *parcels , int index)

Rcl selectParcel(Parcels *parcels , Rcl *rcl ,Cordinate position)

Parcels constructionPhase(Parcels *parcels ,Parcels *path , float *distance)