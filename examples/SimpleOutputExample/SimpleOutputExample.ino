#include <ArrayByte.h>

ArrayByte<uint8_t> ab8 = ArrayByte<uint8_t>(0xAA);
ArrayByte<byte> abyte = ArrayByte<byte>(0x55);
ArrayByte<unsigned int> abUInt = ArrayByte<unsigned int>(0x2010);
ArrayByte<unsigned long> abULong = ArrayByte<unsigned long>(0x80402010);

ArrayByte ab8Result;
ArrayByte abUIntResult;
ArrayByte abULongResult;

void setup() {
  
	Serial.begin(9600);

	// Byte = uint8_t  Both can be used
	Serial.print(F("ab8:"));  Serial.print(ab8, HEX);
	Serial.print(F("  sizeof:"));  Serial.println(sizeof(ab8));


	Serial.print(F("abbyte:"));  Serial.print(abbyte, HEX);
	Serial.print(F("  sizeof:"));  Serial.println(sizeof(abbyte));

	Serial.print(F("abUInt:"));  Serial.print(abUInt, HEX);
	Serial.print(F("  sizeof:"));  Serial.println(sizeof(abUInt));


	Serial.print(F("abULong:"));  Serial.print(abULong, HEX);
	Serial.print(F("  sizeof:"));  Serial.println(sizeof(abULong));


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
		abResult = ab8 | 0xC0;
		abUIntResult = abUInt | 0xC000;
		abULongResult = abULong | 0xC00000;

		ab8 |= 0xC0;
		abUInt |= 0xC000;
		abULong |= 0xC00000;

			printResults(F("logical OR assigned"), true);
			printResults(F("logical OR inplace"),false);

	//logical AND

		abResult = ab8 | 0xF0;
		abUIntResult = abUInt | 0xF000;
		abULongResult = abULong | 0xF00000;

		ab8 |= 0xF0;
		abUInt |= 0xF000;
		abULong |= 0xF00000;

			printResults(F("logical AND assigned"), true);
			printResults(F("logical AND inplace"), false);

		//increment

		abResult = ab8++;
		abUIntResult = abUInt++;
		abULongResult = abULong++;

		ab8++;
		abUInt++;
		abULong++;

			printResults(F("increment assigned"), true);
			printResults(F("increment inplace"), false);

		//decrement

		abResult = ab8--;
		abUIntResult = abUInt--;
		abULongResult = abULong--;

		ab8--;
		abUInt--;
		abULong--;

			printResults(F("decrement assigned"), true);
			printResults(F("decrement inplace"), false);

		//shift right

		abResult = ab8 >> 1;
		abUIntResult = abUInt >> 1;
		abULongResult = abULong >> 1;

		ab8 >>= 1;
		abUInt >>= 1;
		abULong >>= 1;

			printResults(F("shift right assigned"), true);
			printResults(F("shift right inplace"), false);


		//shift left

		abResult = ab8 << 2;
		abUIntResult = abUInt << 2;
		abULongResult = abULong << 2;

		ab8 <<= 1;
		abUInt <<= 1;
		abULong <<= 1;

			printResults(F("shift left assigned"), true);
			printResults(F("shift left inplace"), false);
}

void loop() {
  
}

void printResults(char* header, bool orig)
{
	Serial.println(F(""));
	Serial.println(header);

	if (orig)
	{
		Serial.print(F("  ab8:"));  Serial.println(ab8, HEX);
		Serial.print(F("  abUInt:"));  Serial.println(abUInt HEX);
		Serial.print(F("  abULong:"));  Serial.println(abULong HEX);
	}
	else
	{
		Serial.print(F("  ab8Result:"));  Serial.println(abResult, HEX);
		Serial.print(F("  abUIntResult:"));  Serial.println(abUIntResult HEX);
		Serial.print(F("  abULongResult:"));  Serial.println(abULongResult HEX);
	}
}
