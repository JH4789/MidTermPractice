 #include "clist.h"
#include <iostream>


int main()
{
    clist object;
    object.build();		//builds a circular LL
    object.display();	//displays the list
    clist copied;    
    //PLEASE PUT YOUR CODE HERE to call the function assigned
    copied.copy(object.returnRear(), object.returnRear()->next);
    copied.display();
     //resulting list after your function call!
    
    return 0;
}
