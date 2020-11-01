// listDriver.cpp
#include <iostream>
#include "SCLL.h"

using std::cout, std::endl;

int main()
{
   // Define a SortedCircularList object.
   SortedCircularList<int> list;

   // Store the integer objects in the list.
   list.insertValue(25);  
   list.insertValue(52); 
   list.insertValue(17); 
   list.insertValue(75);

   // Display the values in the list.
   cout << "Here is the initial list:\n";
   list.print();
   cout << endl;

   // insert 45
   list.insertValue(45);
   cout << "Here is the list after inserting 45:\n";
   list.print();
   cout << endl;

   return 0;
}
