typedef struct Parcel {
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


//Array list 
Parcel initializeParcel(Parcel parcel){
    Cordinate cordinate;
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

List removeWithIndex(List list , int i){
    int j;
    Pnode *temp = list;
    while(j<i){
        temp = temp->nextParcel;
        j++;
    }
    
    

    return list;
}