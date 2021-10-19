#include <iostream>
#include "Units.h"
#include <chrono>

using namespace std;
using namespace units;


int main()
{
    Town c_london{ "London" };
    Capital c_capital{ &c_london }; // when creating a capital object, we only specify what town to make into it
     cout << "Capital name: " << c_capital.name << "\n\n"; // we didn't specify the name of the capital, it took one from the town object

    County c_suffolk_county;
    Region& c_suffolk_region = c_suffolk_county; // c_suffolk_county gets a new name - c_suffolk_region (as a region)
     cout << "Normal method result: " << c_suffolk_region.get_level_name() << endl << // the result is from the Region class (superclass)
         "Virtual method result: " << c_suffolk_region.get_level_name_virtual() << "\n\n"; // the result is from the County class (child class)

    Unitary_authority c_derby{ Unitary_authority("Derby") };
    Rural_shire c_cheshire_east{ Rural_shire("Cheshire East") }; // rural shire is a child of shire, which inherits "name" via protected inheritance
    Metropolitan_county c_merseyside{ Metropolitan_county("Merseyside") };

     cout << "Unitary authority (public inheritance) name: " << c_derby.name << endl; // we can access the name directly
     cout << "Shire (protected inheritance) name through the child: " << c_cheshire_east.get_name() << endl; // we can access the name through a child, but not directly
     cout << "Metropolitan county (private inheritance) name through a public getter: " << c_merseyside.get_name() << endl; // we can only access the name via a public getter
}
