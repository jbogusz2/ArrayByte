#include <ArrayByte.h>

ArrayByte<uint8_t> ab8 = ArrayByte<uint8_t>(0xAA);
ArrayByte<byte> abyte = ArrayByte<byte>(0x55);
ArrayByte<unsigned int> abUInt = ArrayByte<unsigned int>(0x2010);
ArrayByte<unsigned long> abULong = ArrayByte<unsigned long>(0x80402010);

ArrayByte<byte> abResult = ArrayByte<byte>();
ArrayByte<unsigned int> abUIntResult = ArrayByte<unsigned int>();
ArrayByte<unsigned long> abULongResult = ArrayByte<unsigned long>();

void setup() {
  
	Serial.begin(9600);

	// Byte = uint8_t  Both can be used
	Serial.print("ab8:");  Serial.print(ab8, HEX);
	Serial.print("  sizeof():");  Serial.print(sizeof(ab8));
	Serial.print("  ab8.size():");  Serial.println(ab8.size());


	Serial.print("abyte:");  Serial.print(abyte, HEX);
	Serial.print("  sizeof():");  Serial.print(sizeof(abyte));
	Serial.print("  abyte.size():");  Serial.println( abyte.size() );

	Serial.print("abUInt:");  Serial.print(abUInt, HEX);
	Serial.print("  sizeof():");  Serial.print(sizeof(abUInt));
	Serial.print("  abUInt.size():");  Serial.println(abUInt.size());


	Serial.print("abULong:");  Serial.print(abULong, HEX);
	Serial.print("  sizeof():");  Serial.print(sizeof(abULong));
	Serial.print("  abULong.size():");  Serial.println(abULong.size());


	// assignment
	ab8 = 0x00;
	abUInt = 0x00;
	abULong = 0x00;
	
		printResults("assignment", true);

	//bit access as array inplace
	ab8[0] = true;
	abUInt[8] = true;
	abULong[16] = true;

		printResults("bit access as array", true);

	//logical OR

			printResults("pre-logical OR assigned", true);
			printResults("pre-logical OR inplace", false);

		abResult = ab8 | (uint8_t)0xC0;
		abUIntResult = abUInt | (unsigned int)0xC000;
		abULongResult = abULong | (unsigned long)0xC00000;

		ab8 |= (uint8_t)0xC0;
		abUInt |= (unsigned int)0xC000;
		abULong |= (unsigned long)0xC00000;

			printResults("post-logical OR assigned", true);
			printResults("post-logical OR inplace",false);

	//logical AND

			printResults("pre-logical AND assigned", true);
			printResults("pre-logical AND inplace", false);

		abResult = ab8 & (uint8_t)0xF0;
		abUIntResult = abUInt & (unsigned int)0xF000;
		abULongResult = abULong & (unsigned long)0xF00000;

		ab8 &= (uint8_t)0xF0;
		abUInt &= (unsigned int)0xF000;
		abULong &= (unsigned long)0xF00000;

			printResults("post-logical AND assigned", true);
			printResults("post-logical AND inplace", false);

		//increment

			printResults("pre-increment assigned", true);
			printResults("pre-increment inplace", false);

		abResult = ++ab8;	// should be ....1
		abUIntResult = ++abUInt;
		abULongResult = ++abULong;

		ab8++;				// should be ....2
		abUInt++;
		abULong++;

			printResults("post-increment inplace", false);
			printResults("post-increment assigned", true);

		//decrement

			printResults("pre-decrement inplace", false);
			printResults("pre-decrement assigned", true);


		abResult = --ab8;	// should be ....1
		abUIntResult = --abUInt;
		abULongResult = --abULong;

		ab8--;				// should be ....0
		abUInt--;
		abULong--;

			printResults("post-decrement inplace", false);
			printResults("post-decrement assigned", true);

		//shift right

			printResults("pre-shift right assigned", true);
			printResults("pre-shift right inplace", false);

		abResult = ab8 >> 1;
		abUIntResult = abUInt >> 1;
		abULongResult = abULong >> 1;

		ab8 >>= 1;
		abUInt >>= 1;
		abULong >>= 1;

			printResults("post-shift right assigned", true);
			printResults("post-shift right inplace", false);


		//shift left

			printResults("pre-shift left assigned", true);
			printResults("pre-shift left inplace", false);

		abResult = abResult << 1;
		abUIntResult = abUIntResult << 1;
		abULongResult = abULongResult << 1;

		ab8 <<= 1;
		abUInt <<= 1;
		abULong <<= 1;

			printResults("post-shift left assigned", true);
			printResults("post-shift left inplace", false);

		//shift left

			printResults("pre-shift left assigned", true);
			printResults("pre-shift left inplace", false);

		abResult = abResult << 1;
		abUIntResult = abUIntResult << 1;
		abULongResult = abULongResult << 1;

		ab8 <<= 1;
		abUInt <<= 1;
		abULong <<= 1;

			printResults("post-shift left assigned", true);
			printResults("post-shift left inplace", false);


		// addition

			printResults("pre-addition assigned", true);
			printResults("pre-addition inplace", false);

		abResult = ab8+4;
		abUIntResult = abUInt + 4;
		abULongResult = abULong + 4;

		ab8 += 4;
		abUInt += 4;
		abULong += 4;

			printResults("post-addition assigned", true);
			printResults("post-addition inplace", false);


		// subtraction

			printResults("pre-subtraction assigned", true);
			printResults("pre-subtraction inplace", false);

		abResult = ab8 - 4;
		abUIntResult = abUInt - 4;
		abULongResult = abULong - 4;

		ab8 -= 4;
		abUInt -= 4;
		abULong -= 4;

			printResults("post-subtraction assigned", true);
			printResults("post-subtraction inplace", false);


		// multiplication

			ab8 = 0x08;
			abUInt = 0x0800;
			abULong = 0x080000;
			abResult = 0x08;
			abULongResult = 0x0800;
			abResult = 0x080000;

			printResults("pre-multiplication assigned", true);
			printResults("pre-multiplication inplace", false);

		abResult = ab8 * 4;
		abUIntResult = abUInt * 4;
		abULongResult = abULong * 4;

		ab8 *= 4;
		abUInt *= 4;
		abULong *= 4;

			printResults("post-multiplication assigned", true);
			printResults("post-multiplication inplace", false);

		// division


			printResults("pre-division assigned", true);
			printResults("pre-division inplace", false);

		abResult = ab8 / 4;
		abUIntResult = abUInt / 4;
		abULongResult = abULong / 4;

		ab8 /= 4;
		abUInt /= 4;
		abULong /= 4;

			printResults("post-division assigned", true);
			printResults("post-division inplace", false);


		// XOR


			printResultsBIN("pre-XOR assigned", true);
			printResultsBIN("pre-XOR inplace", false);

		abResult = abResult ^ ab8;
		abUIntResult = abUIntResult ^ abUInt;
		abULongResult = abULongResult ^ abULong;

		ab8 ^= !ab8;
		abUInt ^= !abUInt;
		abULong ^= !abULong;

			printResultsBIN("post-XOR assigned", true);
			printResultsBIN("post-XOR inplace", false);
}


void loop() {
  
}

void printResults(char* header, bool orig)
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
void printResultsBIN(char* header, bool orig)
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
