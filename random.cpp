// vector::push_back
#include <iostream>
#include "parcel.cpp"
#include <vector>

using namespace std;



int main ()
{ 
  clock_t t;
    

    Parcels parcels;
    Parcels path;
    
    float d1;
    float d2;

    
    
    //start execution time
    t = clock();
    
    // char *s;
    // gen_random(&s , 10);
    // printf("%c" , s);
    parcels = initializeList(&parcels);
    
    Parcel parcel0; parcel0.latitude = 2; parcel0.longitude = 3;
    Parcel parcel1; parcel1.latitude = 1; parcel1.longitude = 6; 
    Parcel parcel2; parcel2.latitude = -3; parcel2.longitude = 8; 
    Parcel parcel3; parcel3.latitude = 9; parcel3.longitude = 2; 
    Parcel parcel4; parcel4.latitude = 4; parcel4.longitude = 5; 
    
    // parcels = generateParcels(&parcels);
    parcels = addParcelAtEnd(&parcels , parcel0);
    parcels = addParcelAtEnd(&parcels , parcel1);
    parcels = addParcelAtEnd(&parcels , parcel2);
    parcels = addParcelAtEnd(&parcels , parcel3);
    parcels = addParcelAtEnd(&parcels , parcel4);
    
    cout << "########CONSTRUCTION PHASE #######################";
    path = constructionPhase(&parcels , &path);
   
    for(int i = 0 ; i < (int)path.parcels.size();i++ ){
      cout << "point " << i << "with latitude " << path.parcels[i].latitude << " with longitude " << path.parcels[i].longitude << "\n";
    }

    path = randomSearch(&parcels , &path);
   
    for(int i = 0 ; i < (int)path.parcels.size();i++ ){
      cout << "point " << i << "with latitude " << path.parcels[i].latitude << " with longitude " << path.parcels[i].longitude << "\n";
    }
    

    t = clock() - 1;
    //end execution time
    double execution_time = ((double)t);
    printf("it takes %f ms to execute", execution_time);
    return 0;
  

  

  
}