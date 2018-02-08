
#include <Arduino.h>
#include <ArrayByte.h>



template <class T>
ArrayByte<T>::ArrayByte() : bits() {}


template <class T>
ArrayByte<T>::ArrayByte(valueType bits) : bits(bits) {}

template <class T>
size_t ArrayByte<T>::size() const { return sizeof(bits) * 8; }

template <class T>
T ArrayByte<T>::operator+(T val)
{
	T tmp = bits;

	tmp += val;

	return tmp;
}

//
//T ArrayByte<T>::operator+(T val)
//{
//	T tmp = bits;
//
//	tmp += val.bits;
//
//	return tmp;
//}
//
//T ArrayByte<T>::operator+(ArrayByte<T> &val)
//{
//	T tmp = bits;
//
//	tmp += val;
//
//	return tmp;
//}

