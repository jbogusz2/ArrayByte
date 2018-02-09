#include <ArrayByte.h>

// unsigned char = byte = uint8_t  can be used

ArrayByte<unsigned char> auc8 = ArrayByte<unsigned char>(0xBB);
ArrayByte<uint8_t> ab8 = ArrayByte<uint8_t>(0xAA);
ArrayByte<byte> abyte = ArrayByte<byte>(0x55);

ArrayByte<unsigned int> abUInt = ArrayByte<unsigned int>(0x2010);
ArrayByte<unsigned long> abULong = ArrayByte<unsigned long>(0x80402010);

ArrayByte<byte> abResult = ArrayByte<byte>();
ArrayByte<unsigned int> abUIntResult = ArrayByte<unsigned int>();
ArrayByte<unsigned long> abULongResult = ArrayByte<unsigned long>();

void setup() {
  
	Serial.begin(9600);

	Serial.print(F("ab8:"));  Serial.print(ab8, HEX);
	Serial.print(F("  sizeof():"));  Serial.print(sizeof(ab8));
	Serial.print(F("  ab8.size():"));  Serial.println(ab8.size());


	Serial.print(F("abyte:"));  Serial.print(abyte, HEX);
	Serial.print(F("  sizeof():"));  Serial.print(sizeof(abyte));
	Serial.print(F("  abyte.size():"));  Serial.println( abyte.size() );

	Serial.print(F("abUInt:"));  Serial.print(abUInt, HEX);
	Serial.print(F("  sizeof():"));  Serial.print(sizeof(abUInt));
	Serial.print(F("  abUInt.size():"));  Serial.println(abUInt.size());


	Serial.print(F("abULong:"));  Serial.print(abULong, HEX);
	Serial.print(F("  sizeof():"));  Serial.print(sizeof(abULong));
	Serial.print(F("  abULong.size():"));  Serial.println(abULong.size());


	// assignment
	ab8 = 0x00;
	abUInt = 0x00;
	abULong = 0x00;
	
		printResults(F("assignment"), true);

	//bit access as array inplace
	ab8[0] = true;
	abUInt[8] = true;
	abULong[16] = true;

		printResults(F("bit access as array"), true);

	//logical OR

			printResults(F("pre-logical OR assigned"), true);
			printResults(F("pre-logical OR inplace"), false);

		abResult = ab8 | (uint8_t)0xC0;
		abUIntResult = abUInt | (unsigned int)0xC000;
		abULongResult = abULong | (unsigned long)0xC00000;

		ab8 |= (uint8_t)0xC0;
		abUInt |= (unsigned int)0xC000;
		abULong |= (unsigned long)0xC00000;

			printResults(F("post-logical OR assigned"), true);
			printResults(F("post-logical OR inplace"), false);

	//logical AND

			printResults(F("pre-logical AND assigned"), true);
			printResults(F("pre-logical AND inplace"), false);

		abResult = ab8 & (uint8_t)0xF0;
		abUIntResult = abUInt & (unsigned int)0xF000;
		abULongResult = abULong & (unsigned long)0xF00000;

		ab8 &= (uint8_t)0xF0;
		abUInt &= (unsigned int)0xF000;
		abULong &= (unsigned long)0xF00000;

			printResults(F("post-logical AND assigned"), true);
			printResults(F("post-logical AND inplace"), false);

		//increment

			printResults(F("pre-increment assigned"), true);
			printResults(F("pre-increment inplace"), false);

		abResult = ++ab8;	// should be ....1
		abUIntResult = ++abUInt;
		abULongResult = ++abULong;

		ab8++;				// should be ....2
		abUInt++;
		abULong++;

			printResults(F("post-increment inplace"), false);
			printResults(F("post-increment assigned"), true);

		//decrement

			printResults(F("pre-decrement inplace"), false);
			printResults(F("pre-decrement assigned"), true);


		abResult = --ab8;	// should be ....1
		abUIntResult = --abUInt;
		abULongResult = --abULong;

		ab8--;				// should be ....0
		abUInt--;
		abULong--;

			printResults(F("post-decrement inplace"), false);
			printResults(F("post-decrement assigned"), true);

		//shift right

			printResults(F("pre-shift right assigned"), true);
			printResults(F("pre-shift right inplace"), false);

		abResult = ab8 >> 1;
		abUIntResult = abUInt >> 1;
		abULongResult = abULong >> 1;

		ab8 >>= 1;
		abUInt >>= 1;
		abULong >>= 1;

			printResults(F("post-shift right assigned"), true);
			printResults(F("post-shift right inplace"), false);


		//shift left

			printResults(F("pre-shift left assigned"), true);
			printResults(F("pre-shift left inplace"), false);

		abResult = abResult << 1;
		abUIntResult = abUIntResult << 1;
		abULongResult = abULongResult << 1;

		ab8 <<= 1;
		abUInt <<= 1;
		abULong <<= 1;

			printResults(F("post-shift left assigned"), true);
			printResults(F("post-shift left inplace"), false);

		//shift left

			printResults(F("pre-shift left assigned"), true);
			printResults(F("pre-shift left inplace"), false);

		abResult = abResult << 1;
		abUIntResult = abUIntResult << 1;
		abULongResult = abULongResult << 1;

		ab8 <<= 1;
		abUInt <<= 1;
		abULong <<= 1;

			printResults(F("post-shift left assigned"), true);
			printResults(F("post-shift left inplace"), false);


		// addition

			printResults(F("pre-addition assigned"), true);
			printResults(F("pre-addition inplace"), false);

		abResult = ab8+4;
		abUIntResult = abUInt + 4;
		abULongResult = abULong + 4;

		ab8 += 4;
		abUInt += 4;
		abULong += 4;

		ArrayByte<byte> tba = 0x06;
		abResult += tba;

			printResults(F("post-addition assigned"), true);
			printResults(F("post-addition inplace"), false);


		// subtraction

			printResults(F("pre-subtraction assigned"), true);
			printResults(F("pre-subtraction inplace"), false);

		abResult = ab8 - 4;
		abUIntResult = abUInt - 4;
		abULongResult = abULong - 4;

		ab8 -= 4;
		abUInt -= 4;
		abULong -= 4;

		ArrayByte<byte> tb = 0x06;
		abResult -= tb;

			printResults(F("post-subtraction assigned"), true);
			printResults(F("post-subtraction inplace"), false);


		// multiplication

			ab8 = 0x08;
			abUInt = 0x0800;
			abULong = 0x080000;
			abResult = 0x08;
			abULongResult = 0x0800;
			abResult = 0x080000;

			printResults(F("pre-multiplication assigned"), true);
			printResults(F("pre-multiplication inplace"), false);

		abResult = ab8 * 4;
		abUIntResult = abUInt * 4;
		abULongResult = abULong * 4;

		ab8 *= 4;
		abUInt *= 4;
		abULong *= 4;

		ArrayByte<byte> tbm = 0x02;
		abResult *= tbm;

			printResults(F("post-multiplication assigned"), true);
			printResults(F("post-multiplication inplace"), false);

		// division


			printResults(F("pre-division assigned"), true);
			printResults(F("pre-division inplace"), false);

		abResult = ab8 / 4;
		abUIntResult = abUInt / 4;
		abULongResult = abULong / 4;

		ab8 /= 4;
		abUInt /= 4;
		abULong /= 4;

			printResults(F("post-division assigned"), true);
			printResults(F("post-division inplace"), false);


		// XOR


			printResultsBIN(F("pre-XOR assigned"), true);
			printResultsBIN(F("pre-XOR inplace"), false);

		abResult = abResult ^ ab8;
		abUIntResult = abUIntResult ^ abUInt;
		abULongResult = abULongResult ^ abULong;

		ab8 ^= !ab8;
		abUInt ^= !abUInt;
		abULong ^= !abULong;

			printResultsBIN(F("post-XOR assigned"), true);
			printResultsBIN(F("post-XOR inplace"), false);


		// MODULUS


		ab8 = 0x03;
		abUInt = 0x0300;
		abULong = 0x030000;

			printResultsBIN(F("pre-MOD assigned"), true);
			printResultsBIN(F("pre-MOD inplace"), false);

		abResult = ab8 % 2;
		abUIntResult = abUInt % 0x200;
		abULongResult = abULong % 0x20000;

		ab8 = ab8 % 3;
		abUInt = abUInt % 3;
		abULong = abULong % 3;

			printResultsBIN(F("post-MOD assigned"), true);
			printResultsBIN(F("post-MOD inplace"), false);

		// COMPARISON


		ab8 = 0x03;

			Serial.println(F("Comparison"));
			Serial.print(F("ab8: ")); Serial.println(ab8);

			Serial.print(F("ab8 = 3  :: ")); Serial.println(ab8 == 3);
			Serial.print(F("ab8 < 3  :: ")); Serial.println(ab8 < 3);
			Serial.print(F("ab8 > 3  :: ")); Serial.println(ab8 > 3);
			Serial.print(F("ab8 <= 4  :: ")); Serial.println(ab8 <= 4);
			Serial.print(F("ab8 >= 3  :: ")); Serial.println(ab8 >= 3);
			Serial.print(F("ab8 != 4  :: ")); Serial.println(ab8 != 4);
			
		// ones complement

			ab8 = 0x55;
			abUInt = 0x5555;
			abULong = 0x55555555;
		
				printResults(F("pre-ones complement assigned"), true);

			ab8 = ~ab8;
			abUInt = ~abUInt;
			abULong = ~abULong;

				printResults(F("post-ones complement assigned"), true);

}


void loop() {
  
}

void printResults(const __FlashStringHelper* header, bool orig)
{
	Serial.println("");
	Serial.println(header);

	if (orig)
	{
		Serial.print("  ab8:");  Serial.println(ab8, HEX);
		Serial.print("  abUInt:");  Serial.println(abUInt, HEX);
		Serial.print("  abULong:");  Serial.println(abULong, HEX);
	}
	else
	{
		Serial.print("  ab8Result:");  Serial.println(abResult, HEX);
		Serial.print("  abUIntResult:");  Serial.println(abUIntResult, HEX);
		Serial.print("  abULongResult:");  Serial.println(abULongResult, HEX);
	}
}
void printResultsBIN(const __FlashStringHelper* header, bool orig)
{
	Serial.println("");
	Serial.println(header);

	if (orig)
	{
		Serial.print("  ab8:");  Serial.println(ab8, BIN);
		Serial.print("  abUInt:");  Serial.println(abUInt, BIN);
		Serial.print("  abULong:");  Serial.println(abULong, BIN);
	}
	else
	{
		Serial.print("  ab8Result:");  Serial.println(abResult, BIN);
		Serial.print("  abUIntResult:");  Serial.println(abUIntResult, BIN);
		Serial.print("  abULongResult:");  Serial.println(abULongResult, BIN);
	}
}
