#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array(): asize(0), arr(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n): asize(n)
{
	arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T>& other): asize(other.asize)
{
	if (other.asize == 0)
	{
		arr = NULL;
		return ;
	}
	arr = new T[asize];
	for (unsigned int i = 0; i < asize; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	if (arr)
		delete [] arr;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		if (arr)
			delete [] arr;
		asize = other.asize;
		if (other.asize == 0)
		{
			arr = NULL;
			return (*this);
		}
		arr = new T[other.asize];
		for (unsigned int i = 0; i < other.asize; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= asize)
		throw std::out_of_range("Index out of bounds");
	return arr[index];
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= asize)
		throw std::out_of_range("Index out of bounds");
	return arr[index];
}

template <typename T>
unsigned int	Array<T>::size() const {return asize;}
