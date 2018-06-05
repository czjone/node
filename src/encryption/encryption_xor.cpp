// #include "encryption_xor.h"

// EncryptionXOR::EncryptionXOR(){

// }

// EncryptionXOR::~EncryptionXOR(){

// }
// #define BLCOK_LEN 8

// Bool EncryptionXOR::EncryptionBytes(IO::Stream& instream, IO::Stream&ostream){
// 	instream.seek(0);
// 	ostream.seek(0);

// 		Int32 readlen;
// 		const char* key =static_cast<const char*>(this->getKey().c_str());
// 		UInt32 keylen = this->getkeylen();
// 		do{
// 			char c[BLCOK_LEN];
// 			int readBytesLen = instream.read(static_cast<char*>(c), BLCOK_LEN);
// 			for (int blcokIdx = 0; blcokIdx < readBytesLen; blcokIdx++){
// 				for (int i = 0; i < keylen; i++){
// 					c[blcokIdx] ^= key[i];
// 				}
// 			}
// 			ostream.wirte(static_cast<char*>(c), readBytesLen);
// 		} while (!instream.eof());

// 	return true;
// }

// Bool EncryptionXOR::DecryptionBytes(IO::Stream& instream, IO::Stream&ostream){
// 	/*const int len = 1;
// 	instream.seek(0);
// 	ostream.seek(0);

// 	 char bytes[len];
// 	Int32 readlen;
// 	const char* key = (const char*) this->getKey().c_str();
// 	UInt32 keylen = this->getKey().length();
// 	do
// 	{
// 		readlen = instream.read(bytes, len);
// 		for (Int32 i = 0; i < readlen; i++)
// 		{
// 			for (Int32 ii = keylen-1; ii >= 0; ii--)
// 			{
// 				bytes[i] ^= *(key + ii -1);
// 			}
// 		}
// 		ostream.wirte(bytes, readlen);
// 	} while (!instream.eof());
// */
// 	return true;
// }
