typedef struct Parcel {
    float longitude;
    float latitude;
}Parcel;

typedef struct Cordinate {
    float latitude;
    float longitude;
}Cordinate;

typedef struct Parcels
{   
    int numberParcels;
    Parcel parcels[1000];
}Parcels;


Parcel initializeParcel(Parcel parcel){
    Cordinate cordinate;
    return parcel;
}

Parcels initializeList(Parcels parcels){
    parcels.numberParcels = 0;
    return parcels;
}

Parcels addParcelAtEnd(Parcels parcels , Parcel parcel){
    parcels.parcels[parcels.numberParcels] = parcel;
    parcels.numberParcels++;
    return parcels;
}
Parcels deleteParcelAtEnd(Parcels *parcels){
    parcels->numberParcels--;
    return *parcels;
}

