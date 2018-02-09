ArrayByte
======
Flexible data type for unsigned types with array accessors for bit manipulation
------------------------------------------------------------------------------

The ArrayByte library for Arduino is a very flexible way to manipulate bits in unsigned data types.  It allows all the normal operations plus the array operator to manipulate individual bits.

### Inspiration

The need for more than 8 bits for a bank of shift registers.  Yes, you can use an array of bytes, but is becomes tedious to manage having to calculate banks and bits.

### Basic Usage

	An ArrayByte can be of types:
		8 bits  - unsigned char, byte, uint8_t
		16 bits - unsigned short
		16 or 32 bits - unsigned int  (depending on implementation)
		32 bits - unsigned long
		
	Declaration:
		ArrayByte<unsigned char> ucArrayByte   = ArrayByte<unsigned char>(0x00);
		ArrayByte<byte> byArrayByte            = ArrayByte<byte>(0x00);
		ArrayByte<uint8_t> u8tArrayByte        = ArrayByte<uint8_t>(0x00);
		ArrayByte<unsigned short> usArrayByte  = ArrayByte<unsigned short>(0x00);
		ArrayByte<unsigned int> uiArrayByte    = ArrayByte<unsigned int>(0x4EA);
		ArrayByte<unsigned long> ulArrayByte   = ArrayByte<unsigned long>(0x00);
		
		Can be declared unassigned:
			ArrayByte<unsigned char> ab = ArrayByte<unsigned char>();
			
	Assignment:
		ucArrayByte  = 0x55;
		u8tArrayByte = 0xAA;
		bytArrayByte = 0x80;
		usArrayByte  = 0x5500
		ulArrayByte  = 0x55000000;
		
	Assigning:  ArrayByte acts like its data type
		ArrayByte<unsigned short> ui = ArrayByte<unsigned short>(0x8080);
		unsigned short tmp = ui;	// tmp = 0x8080
	
	Array access is boolean
		ucArrayByte[3] = true;	// set bit 3
		ucArrayByte[3] = false;	// clear bit 3
		
### Operators
    
	Assignment        =
	Arithmetic        +, +=, - , -=, *, *=, /, /=
	Bitwise		      &, |, ^, !
	Logical           &&, ||, %
	Unary		      ++, --  pre and post
	Comparison        ==, <, <=, >, >=, !=
	Shift             <<, <<=, >>, >>=
	Array subscript   []
	Ones complement   ~