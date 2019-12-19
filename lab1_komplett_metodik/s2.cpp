#include "s2.h"
#include "b.h"
#include <algorithm>
#include <iostream>
#include <vector>




int_sorted::int_sorted() :sorted_buffer(int_buffer(nullptr, 0)) {}





int_sorted::int_sorted(const int* source, size_t size) :sorted_buffer(int_buffer(source, size)) {       //Konstruerare som skapar en int_source med storleken size och sorterar värdena i source

	if (size > 1) {   //Om storleken större än 1 finns fortfarande element att sortera

		auto newSortedBuffer = sort(sorted_buffer.begin(), sorted_buffer.end());

		//std::copy(newSortedBuffer.begin(), newSortedBuffer.end(), sorted_buffer.begin());
		sorted_buffer = std::move(newSortedBuffer.sorted_buffer); //ta bort osorterad
	}

}





//Retunerar storleken på en int_sorted 

size_t int_sorted::size() const {

	return sorted_buffer.size();

}





//Lägger in ett värde i buffern på rätt plats enligt sortering

int* int_sorted::insert(int value) {

	int_sorted tmp(&value, 1);// skapa en int_sorted lista med värde och size

	sorted_buffer = std::move(merge(tmp).sorted_buffer); //använder merge sort för sortera int_sort listan temp

	return std::find(sorted_buffer.begin(), sorted_buffer.end(), value);

}





//Retunerar det första värdet i buffern 

const int* int_sorted::begin() const {

	return sorted_buffer.begin();

}





//Retunerar det sista värdet i buffern

const int* int_sorted::end() const {

	return sorted_buffer.end();

}





int_sorted int_sorted::merge(const int_sorted& merge_with) const {



	int_buffer newBuf(this->size() + merge_with.size()); //skapa lista med size bara 



	const int* p1 = sorted_buffer.begin();//adressen till det första elementet

	const int* p2 = merge_with.begin();

	int* pNewBuf = newBuf.begin();



	//for(;p1 != end() && p2 != merge_with.end(); i++){

	while (p1 != sorted_buffer.end() && p2 != merge_with.end()) {

		if (*p1 < *p2)

		{
			*pNewBuf = *p1;

			p1++;

			pNewBuf++;
		}

		else

		{

			*pNewBuf = *p2;

			p2++;

			pNewBuf++;

		}

	}

	//Om det finns något kvar i en buffer så skriv över de värdena till den nya bufern

	while (p1 != sorted_buffer.end()) {

		*pNewBuf = *p1;

		p1++;

		pNewBuf++;

	}



	while (p2 != merge_with.sorted_buffer.end()) {

		*pNewBuf = *p2;

		p2++;

		pNewBuf++;

	}


	//sorted_buffer = (newSortedBuffer.sorted_buffer);
	int_sorted merged_buffer;// int_sorted lista skapa merge buffer värde innehåller noll

	merged_buffer.sorted_buffer = std::move(newBuf);



	return merged_buffer;

}





//Given funktion. Sorterar en buffer

int_sorted int_sorted::sort(const int* begin, const int* end) {

	if (begin == end) { return int_sorted(); }              //En tom buffer

	if (begin == end - 1) { return int_sorted(begin, 1); }  //En buffer med en plats skapas

	ptrdiff_t half = (end - begin) / 2;                     //Pekar på mitten av buffer

	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(mid, end));

}





//Retunerar sant om buffern är sorterad

bool int_sorted::checkIfSorted() {

	for (int* i = sorted_buffer.begin(); i < (sorted_buffer.begin() + sorted_buffer.size() - 1); i++) { //Stegar igenom alla element i buffern

		if (*i > * (i + 1)) {   //Om något element större än det nästkommande så är buffern inte sorterad

			return false;

		}

	}

	return true;

}