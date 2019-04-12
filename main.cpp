// vector::push_back
#include <iostream>
#include "parcel.cpp"
#include <vector>

using namespace std;



int main ()
{
  std::vector<Parcel> parcels;

  

  do {
    Parcel parcel;
    std::cout << "################ Please add your parcels infos ##############\n";
    std::cout << "Parcel latitude :";
    std::cin >> parcel.latitude;
    std::cout << "Parcel longitude :";
    std::cin >> parcel.longitude;
    
    parcels.push_back (parcel);
  } while (parcels.size() < 1 );


    //delete parcel 
    // parcels.erase(parcels.begin());

    
    std::cout << "Parcels list stores " << int(parcels.size()) << " numbers.\n";

  return 0;
}