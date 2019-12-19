#include "b.h"
#include "s2.h"
/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <array>

#include <algorithm>

void f(int_buffer buf);         //Printar en int_buffer
void print(int_buffer& buff) {
	for (size_t i = 0; i < buff.size(); i++) {
		std::cout << buff[i] << std::endl;
	}

}



int_buffer generatetorRandom(size_t size) {

	int_buffer buffer(size);

	for (int& e : buffer) {

		e = std::rand();

	}



	return buffer;

}
void selectionSort(int_buffer& buffer) {
	int i, j, min_idx;
	for (int i = 0; i < buffer.size() - 1; i++) {

		for (int j = i + 1; j < buffer.size(); j++) {
			min_idx = i;
			if (buffer[j] < buffer[i]) {
				min_idx = j;


			}
			std::swap(buffer[min_idx], buffer[i]);
		}

	}

}
void print_sorted(int_sorted src);
int main()

{

	srand(time(NULL));

	//int_buffer buffer = generatetorRandom(10);

	int list[4] = { 5,6,2,1 };
	//int liste[4] = { 3,2, 1, 3 };
	int_buffer buffer(list, 4);


	// buffer1 = std::move(buffer);//move
	//print(buffer);
		//print(buffer);
	int_sorted sorted(buffer.begin(), buffer.size());
	//sorted.insert(3);
	print_sorted(sorted);




	//selectionSort(buffer);




	system("pause");


	return 0;




}
void print_sorted(int_sorted src)
{

	for (const int* i = src.begin(); i != src.end(); i++)
		std::cout << *i << std::endl;
}



void f(int_buffer buf) {
	int val = 1;
	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		*i = val;
		++val;
	}
	for (const int* i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << *i << std::endl;
	}
}
