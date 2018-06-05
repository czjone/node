// #ifndef ENCRYPTION_H
// #define ENCRYPTION_H 1



// #include <string>

// class Encryption{
// public:
// 	enum MODEL{
// 		XOR,
// 		DES,
// 	};

// private:
// 	std::string _key;
// 	std::string _msg;
// 	int keylen;

// public:
// 	///**tools**/
// 	//template<typename T>
// 	//static Bool EncryptionTool<T>(IO::Stream& instream, IO::Stream&ostream, const char* key){ T t; t->setkey(key); return t->EncryptionBytes(instream, ostream); };
// 	//template<typename T>
// 	//static Bool DecryptionTool<T>(IO::Stream& instream, IO::Stream&ostream, const char* key){ T t; t->setkey(key); return t->DecryptionBytes(instream, ostream); };
// 	//template<typename T>
// 	//static Bool EncryptionTool<T>(std::string& instr, std::string &outstr, const char* key){ T t; t->setkey(key); return t->EncryptionBytes(instr, outstr); };
// 	//template<typename T>
// 	//static Bool DecryptionTool<T>(std::string& instr, std::string &outstr, const char* key){ T t; t->setkey(key); return t->DecryptionBytes(instr, outstr); };

// public:
// 	Encryption(){};
// 	virtual ~Encryption(void){};
// 	inline void SetKey(const char* key, int len){ this->_key = std::string(key); keylen = len; };
// 	inline int getkeylen(){ return this->keylen; };
// 	virtual Bool EncryptionBytes(IO::Stream& instream, IO::Stream&ostream) = 0;
// 	virtual Bool DecryptionBytes(IO::Stream& instream, IO::Stream&ostream) = 0;

// 	inline std::string &getMsg(){ return this->_msg; };
// 	inline void setMsg(std::string& msg){ _msg = std::string(msg.c_str()); };
// protected:
// 	inline std::string& getKey(void){ return this->_key; };

// //public:
// 	//template<typename T> inline Encryption* Create<T>(){ return new T(); };
// };

// #endif