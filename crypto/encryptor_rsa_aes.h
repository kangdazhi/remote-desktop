//
// PROJECT:         Aspia Remote Desktop
// FILE:            crypto/encryptor_rsa_aes.h
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CRYPTO__ENCRYPTOR_RSA_AES_H
#define _ASPIA_CRYPTO__ENCRYPTOR_RSA_AES_H

#include <wincrypt.h>

#include "base/macros.h"
#include "crypto/encryptor.h"

namespace aspia {

class EncryptorRsaAes : public Encryptor
{
public:
    ~EncryptorRsaAes();

    static std::unique_ptr<EncryptorRsaAes> Create();

    IOBuffer GetSessionKey();
    bool SetPublicKey(const IOBuffer& public_key);

    IOBuffer Encrypt(const IOBuffer& source_buffer) override;

private:
    EncryptorRsaAes(HCRYPTPROV prov, HCRYPTKEY aes_key, DWORD block_size);

    HCRYPTPROV prov_ = NULL;
    HCRYPTKEY aes_key_ = NULL;
    HCRYPTKEY rsa_key_ = NULL;

    DWORD block_size_;

    DISALLOW_COPY_AND_ASSIGN(EncryptorRsaAes);
};

} // namespace aspia

#endif // _ASPIA_CRYPTO__ENCRYPTOR_RSA_AES_H
