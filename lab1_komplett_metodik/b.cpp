#include "b.h"




int_buffer::int_buffer(size_t size) :buffer(new int[size]), length(size)
{}


int_buffer::int_buffer(const int* source, size_t size) : int_buffer(size)
{



	std::copy(source, source + length, buffer);

}

int_buffer::int_buffer(const int_buffer& rhs) :int_buffer(rhs.buffer, rhs.size()) // copy
{




}

int_buffer::int_buffer(int_buffer&& rhs) :length(0), buffer(nullptr)// move 

{

	//Kopiera pekare och längd på pekare till rhs, swap används för att inte förlora instanser

	std::swap(rhs.buffer, buffer);          //Låter rhs.p_buffer peka där p_buffer pekar

	std::swap(rhs.length, length);    //Låter rhs.size_buffer vara av den storlek som size_buffer är.


}






int_buffer& int_buffer::operator=(const int_buffer& rhs)// copy assign

{

	int_buffer temp(rhs);

	std::swap(temp.buffer, buffer);

	std::swap(temp.length, length);

	return *this;

}



int_buffer& int_buffer::operator=(int_buffer&& rhs)// move assign
{



	std::swap(rhs.buffer, buffer);
	std::swap(rhs.length, length);
	return *this;


}

int& int_buffer::operator[](size_t index)
{
	return buffer[index];


}

const int& int_buffer::operator[](size_t index) const
{
	return buffer[index];
}

size_t int_buffer::size() const

{

	return length;

}



int* int_buffer::begin()


{

	return buffer;
}



int* int_buffer::end()


{

	return  buffer + length;

}

const int* int_buffer::begin() const

{

	return buffer;
}


const int* int_buffer::end() const

{

	return  buffer + length;
}


int_buffer::~int_buffer()
{

	delete[] buffer;


}