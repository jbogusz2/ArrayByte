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

	ArrayByte<T>& operator+=(const T val)
	{
		bits += val;
		return *this;
	}

	ArrayByte<T>& operator+=(const ArrayByte<T> &val)
	{
		bits += val;
		return *this;
	}

	T operator+(T val);
	
	T operator+(ArrayByte<T> &val)
	{
		T tmp = bits;

		tmp += val;

		return tmp;
	}

	// ------------------------------------------------
	// SUBTRACTION


	T operator-(T val)
	{
		T tmp = bits;

		tmp -= val;

		return tmp;
	}

	ArrayByte<T>& operator-=(const ArrayByte<T> &val)
	{
		bits -= val;
		return *this;
	}

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

// DEFINED REQUIRED TEMPLATES

template class ArrayByte<uint8_t>;
template class ArrayByte<unsigned char>;
template class ArrayByte<unsigned int>;
template class ArrayByte<unsigned long>;

#endif

