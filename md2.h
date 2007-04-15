#ifndef CRYPTOPP_MD2_H
#define CRYPTOPP_MD2_H

#include "cryptlib.h"
#include "secblock.h"

NAMESPACE_BEGIN(CryptoPP)

namespace Weak {

/// <a href="http://www.cryptolounge.org/wiki/MD2">MD2</a>
class MD2 : public HashTransformation
{
public:
	MD2();
	void Update(const byte *input, size_t length);
	void TruncatedFinal(byte *hash, size_t size);
	unsigned int DigestSize() const {return DIGESTSIZE;}
	unsigned int BlockSize() const {return BLOCKSIZE;}
	static const char * StaticAlgorithmName() {return "MD2";}

	CRYPTOPP_CONSTANT(DIGESTSIZE = 16)
	CRYPTOPP_CONSTANT(BLOCKSIZE = 16)

private:
	void Transform();
	void Init();
	SecByteBlock m_X, m_C, m_buf;
	unsigned int m_count;
};

}
#ifndef CRYPTOPP_ENABLE_NAMESPACE_WEAK
using namespace Weak;
#ifdef __GNUC__
#warning "You may be using a weak algorithm that has been retained for backwards compatibility. Please define CRYPTOPP_ENABLE_NAMESPACE_WEAK and prepend the class name with 'Weak::' to remove this warning."
#else
#pragma message("You may be using a weak algorithm that has been retained for backwards compatibility. Please define CRYPTOPP_ENABLE_NAMESPACE_WEAK and prepend the class name with 'Weak::' to remove this warning.")
#endif
#endif

NAMESPACE_END

#endif
