
#include <Arduino.h>
#include <ArrayByte.h>



template <class T>
ArrayByte<T>::ArrayByte() : bits() {}


template <class T>
ArrayByte<T>::ArrayByte(valueType bits) : bits(bits) {}

template <class T>
size_t ArrayByte<T>::size() const { return sizeof(bits) * 8; }




