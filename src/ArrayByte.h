#ifndef ARRAYBYTE_h
#define ARRAYBYTE_h


template <class T> class ArrayByte
{
	typedef T valueType;

	valueType   bits;

	

	struct Twiddler
	{
		Twiddler(valueType& value, size_t bitIndex)
			: value(value), mask(1 << bitIndex)
		{}

		Twiddler& operator=(const Twiddler&) = delete;
		Twiddler& operator=(bool bit)
		{
			value = value & ~mask | static_cast<valueType>(bit ? mask : 0);
			return *this;
		}

		operator bool() { return (value & mask) != 0; }

	  private:

		valueType& value;
		valueType mask;
	};

	struct ConstTwiddler
	{
		ConstTwiddler(const valueType& value, size_t bitIndex)
			: value(value), mask(1 << bitIndex)
		{}
		ConstTwiddler& operator=(const ConstTwiddler&) = delete;
		operator bool() { return (value & mask) != 0; }

	  private:

		const valueType& value;
		valueType mask;
	};

public:

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


	ArrayByte<T>& operator++()
	{
		bits++;
		return *this;
	}


	ArrayByte<T> operator++(int)
	{
		ArrayByte<T> tmp(*this);
		operator++();
		return tmp;
	}



	ArrayByte<T>& operator--()
	{
		bits--;
		return *this;
	}

	ArrayByte<T> operator--(int)
	{
		ArrayByte<T> tmp(*this);
		operator--();
		return tmp;
	}


	ArrayByte<T>& operator<<=(int shift)
	{
		bits <<= shift;
		return *this;
	}


	ArrayByte<T>& operator>>=(int shift)
	{
		bits >>= shift;
		return *this;
	}

	T operator<<(int shift)
	{
		uint8_t tmp = bits;

		tmp <<= shift;

		return tmp;
	}


	T operator>>(int shift)
	{
		T tmp = bits;

		tmp >>= shift;

		return tmp;
	}


	operator T() const
	{
		return bits;
	}


	ArrayByte<T>();

	ArrayByte<T>(valueType bits);

	size_t size() const;

	Twiddler operator[](size_t index)
	{
		return Twiddler(bits, index);
	}

	const ConstTwiddler operator[](size_t index) const
	{
		return ConstTwiddler(bits, index);
	}
};


template class ArrayByte<uint8_t>;
template class ArrayByte<unsigned int>;
template class ArrayByte<unsigned long>;

#endif

