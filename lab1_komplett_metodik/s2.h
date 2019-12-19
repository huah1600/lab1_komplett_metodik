#ifndef s_h //INCLUDE GUARDS
#define s_h
#include "b.h"
#include <stdio.h>

#include <cstdlib>



class int_sorted {

public:

	int_sorted();   //Defaultkonstruktor, skapar ett objekt med storlek 0 och nullptr

	int_sorted(const int* source, size_t size); //Konstruerare som skapar en int_source med storleken size och sorterar v�rdena i source

	size_t size() const;       //Retunerar storleken p� int_sorted (antal element)

	int* insert(int value);   //Retunerar platsen d�r v�rdet sattes in

	const int* begin() const;  //Retunerar adressen till det f�rsta elementet

	const int* end() const;    //Retunerar adressen till det sista elementet

	int_sorted merge(const int_sorted& merge_with) const;    //Sammanfogar tv� int_sorted merge_with med this. Retunerar en sorterad int_sorted

	bool checkIfSorted(); //Retunerar true om en int_sorted �r sorterad



private:

	int_buffer sorted_buffer; //Medlemsvariabel av typen int_buffer

	int_sorted sort(const int* begin, const int* end); //Given sorteringsalgotim. Retunerar int_sorted. Privat eftersom endast anv�nds inom klassen



};
#endif //int_sorted