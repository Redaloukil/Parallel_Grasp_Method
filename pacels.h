#include"parcels.c"


Parcels addParcelAtEnd(Parcels *parcels,Parcel parcel);

Parcels deleteParcelAtEnd(Parcels *parcels);

Parcels initializeList(Parcels *parcels);

List addParcelAtBegChained(List liste, Parcel parcel);

List addParcelAtBegChained(List list, Parcel parcel);

int randBetweenInt(int min , int max );

float randBetweenFloat(float min, float max);

float calculateCost(Parcel nextPoint , Cordinate startPoint);

float generateCordinates(Cordinate c1 , Cordinate c2 , Cordinate c3 , Cordinate c4);

float square(float number);

Parcels generateParcels(Parcels *parcels);

float calculateMin(Cordinate startPoint , Parcels parcels);

float calculateMax(Cordinate startPoint , Parcels parcels);

Parcels selectParcel(Parcels parcels ,Cordinate position);

void constructionPhase(Parcels parcels ,Parcels path);

Parcel randomSelect(Parcels rcl);

char *rand_string();


