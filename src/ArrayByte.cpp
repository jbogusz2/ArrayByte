/*
The C++ ArrayByte library for Arduino is a very flexible way to manipulate bits in unsigned data types.  It allows all the normal operations plus the array operator to manipulate individual bits.

Copyright (c) 2018 Jeff Bogusz, AardvarkLD.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/
 
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

