#ifndef b_h //INCLUDE GUARDS
#define b_h
#include<iostream>
#include<algorithm>
#include <string>

//using namespace std;



class int_buffer {

public:

	explicit int_buffer(size_t size); // size_t   k�rs f(int_buffer(10));

	//is defined in cstdlib

	int_buffer(const int* source, size_t size);

	int_buffer(const int_buffer& rhs); // copy

	//construct

	int_buffer(int_buffer&& rhs); // move

	//construct

	int_buffer& operator =(const int_buffer& rhs); // copy assign

	int_buffer& operator =(int_buffer&& rhs);// move assign
	int& operator [](size_t index);
	const int& operator [](size_t index) const;


	size_t size() const;

	int* begin();

	int* end();

	const int* begin() const;

	const int* end() const;

	~int_buffer();

private:
	size_t length;
	int* buffer;

};
#endif //b.h