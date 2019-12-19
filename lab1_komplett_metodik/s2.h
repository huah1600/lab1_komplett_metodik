#ifndef s_h //INCLUDE GUARDS
#define s_h
#include "b.h"
#include <stdio.h>

#include <cstdlib>



class int_sorted {

public:

	int_sorted();   //Defaultkonstruktor, skapar ett objekt med storlek 0 och nullptr

	int_sorted(const int* source, size_t size); //Konstruerare som skapar en int_source med storleken size och sorterar värdena i source

	size_t size() const;       //Retunerar storleken på int_sorted (antal element)

	int* insert(int value);   //Retunerar platsen där värdet sattes in

	const int* begin() const;  //Retunerar adressen till det första elementet

	const int* end() const;    //Retunerar adressen till det sista elementet

	int_sorted merge(const int_sorted& merge_with) const;    //Sammanfogar två int_sorted merge_with med this. Retunerar en sorterad int_sorted

	bool checkIfSorted(); //Retunerar true om en int_sorted är sorterad



private:

	int_buffer sorted_buffer; //Medlemsvariabel av typen int_buffer

	int_sorted sort(const int* begin, const int* end); //Given sorteringsalgotim. Retunerar int_sorted. Privat eftersom endast används inom klassen



};
#endif //int_sorted