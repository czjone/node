#ifndef ENCRYPTIONXOR_H
#define ENCRYPTIONXOR_H 1
#include "encryption.h"

class EncryptionXOR : public Encryption{
public:
	EncryptionXOR();
	virtual ~EncryptionXOR(void);
public:
	virtual Bool EncryptionBytes(IO::Stream &instream, IO::Stream &ostream) override;
	virtual Bool DecryptionBytes(IO::Stream &instream, IO::Stream &ostream) override;
};
#endif