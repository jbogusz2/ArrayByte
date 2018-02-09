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

#ifndef ARRAYBYTE_h
#define ARRAYBYTE_h


template <class T> class ArrayByte
{
	typedef T valueType;
	valueType   bits;
	
	struct Twiddler
	{
		Twiddler(valueType& value, size_t bitIndex)
			: value(value), mask( ((T)1) << bitIndex)
		{
			Serial.print("mask "); Serial.println(mask, HEX);
		}

		Twiddler& operator=(const Twiddler&) = delete;
		Twiddler& operator=(bool bit)
		{
			value = value & ~mask | static_cast<valueType>(bit ? mask : ((T)0) );
			return *this;
		}

		operator bool() { return (value & mask) != ((T)0); }

	  private:

		valueType& value;
		valueType mask;
	};

	struct ConstTwiddler
	{
		ConstTwiddler(const valueType& value, size_t bitIndex)
			: value(value), mask( ((T)1) << bitIndex)
		{
			Serial.print("mask "); Serial.println(mask, HEX);
		}
		ConstTwiddler& operator=(const ConstTwiddler&) = delete;
		operator bool() { return (value & mask) != ((T)0); }

	  private:

		const valueType& value;
		valueType mask;
	};

public:

	// ------------------------------------------------
	// ASSIGNMENT

	ArrayByte<T>& operator=(T val)
	{
		bits = val;
		return *this;
	}


	ArrayByte<T>& operator=(ArrayByte<T> val)
	{
		bits = val.bits;
		return *this;
	}


	// ------------------------------------------------
	// INCREMENT

	ArrayByte<T>& operator++()	// prefix ++
	{
		bits++;
		return *this;
	}


	ArrayByte<T> operator++(int)	// postfix ++
	{
		ArrayByte<T> tmp(*this);
		++(*this);
		return tmp;
	}


	// ------------------------------------------------
	// DECREMENT

	ArrayByte<T>& operator--()	// prefix --
	{
		bits--;
		return *this;
	}


	ArrayByte<T> operator--(int)	// postfix -
	{
		ArrayByte<T> tmp(*this);
		--(*this);
		return tmp;
	}

	// ------------------------------------------------
	// BITWISE AND

	ArrayByte<T> operator&(T val) const
	{
		ArrayByte<T> tmp(*this);
		tmp.bits = tmp.bits & val;
		return tmp;

	}

	ArrayByte<T>& operator&=(T val)
	{
		bits = bits & val;
		return *this;
	}



	// ------------------------------------------------
	// BITWISE OR

	ArrayByte<T> operator|(T val) const
	{
		ArrayByte<T> tmp(*this);
		tmp.bits = tmp.bits | val;
		return tmp;
	}

	ArrayByte<T>& operator|=(T val)
	{
		bits = bits | val;
		return *this;
	}

	// ------------------------------------------------
	// BITWISE XOR

	ArrayByte<T> operator^(T val) const
	{
		ArrayByte<T> tmp(*this);
		tmp.bits ^= val;
		return tmp;

	}

	ArrayByte<T>& operator^=(T val)
	{
		bits ^= val;
		return *this;
	}

	// ------------------------------------------------
	// MODULUS

	ArrayByte<T> operator%(T val) const
	{
		ArrayByte<T> tmp(*this);
		tmp.bits = tmp.bits % val;
		return tmp;
	}

	ArrayByte<T>& operator%=(T val)
	{
		bits = bits % val;
		return *this;
	}

	// ------------------------------------------------
	// SHIFT RIGHT

	T operator>>(int shift)
	{
		T tmp = bits;

		tmp >>= shift;

		return tmp;
	}


	ArrayByte<T>& operator>>=(int shift)
	{
		bits >>= shift;
		return *this;
	}


	// ------------------------------------------------
	// SHIFT LEFT

	T operator<<(int shift)
	{
		T tmp = bits;

		tmp <<= shift;

		return tmp;
	}

	ArrayByte<T>& operator<<=(int shift)
	{
		bits <<= shift;
		return *this;
	}


	// ------------------------------------------------
	// ADDITION

	/*ArrayByte<T>& operator+=(const T val)
	{
		bits += val;
		return *this;
	}*/

	/*ArrayByte<T>& operator+=(const ArrayByte<T> &val)
	{
		bits += val;
		return *this;
	}*/

	T operator+(T val);
	
	T operator+(ArrayByte<T> &val)
	{
		T tmp = bits;

		tmp += val;

		return tmp;
	}

	// ------------------------------------------------
	// SUBTRACTION

	/*ArrayByte<T>& operator-(const ArrayByte<T> &val)
	{
		ArrayByte<T> tmp = val;

		tmp -= val;

		return tmp;
	}*/

	T operator-(T val)
	{
		T tmp = bits;

		tmp -= val;

		return tmp;
	}

	/*ArrayByte<T>& operator-=(const ArrayByte<T> &val)
	{
		bits -= val;
		return *this;
	}*/

	ArrayByte<T>& operator-=(T val)
	{
		bits -= val;
		return *this;
	}

	// ------------------------------------------------
	// MULTIPLICATION


	T operator*(T val)
	{
		T tmp = bits;

		tmp *= val;

		return tmp;
	}

	ArrayByte<T>& operator*=(T val)
	{
		bits *= val;
		return *this;
	}


	// ------------------------------------------------
	// DIVISION


	T operator/(T val)
	{
		T tmp = bits;

		tmp /= val;

		return tmp;
	}

	ArrayByte<T>& operator/=(T val)
	{
		bits /= val;
		return *this;
	}
	// ------------------------------------------------
	// RETURN VALUE

	operator T() const
	{
		return bits;
	}

	// ------------------------------------------------
	// CONSTRUCTORS

	ArrayByte<T>();

	ArrayByte<T>(valueType bits);


	// ------------------------------------------------
	// INFO

	//	returns number of bits
	size_t size() const;


	// ------------------------------------------------
	// ARRAY ACCESSOR

	Twiddler operator[](size_t index)
	{
		Serial.print("index "); Serial.println(index, HEX);
		return Twiddler(bits, index);
	}

	const ConstTwiddler operator[](size_t index) const
	{
		Serial.print("index "); Serial.println(index, HEX);
		return ConstTwiddler(bits, index);
	}
};

// DEFINED AVAILABLE TEMPLATES

template class ArrayByte<uint8_t>;
template class ArrayByte<unsigned char>;
template class ArrayByte<unsigned short>;
template class ArrayByte<unsigned int>;
template class ArrayByte<unsigned long>;

#endif

