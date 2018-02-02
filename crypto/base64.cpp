

#include "base64.h"

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>


namespace HUIBASE {

namespace CRYPTO {

	HRET Base64Encode (HCSTRR strIn, HSTRR strOut) {
	
		BIO *bio = NULL, *b64 = NULL;
		BUF_MEM *bufferPtr;

		b64 = BIO_new(BIO_f_base64());
		bio = BIO_new(BIO_s_mem());
		bio = BIO_push(b64, bio);

		BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line

		BIO_write(bio, (const unsigned char*)strIn.c_str(), strIn.length());
		(void)BIO_flush(bio);		
		BIO_get_mem_ptr(bio, &bufferPtr);

		char* outbuf = (char*)malloc(bufferPtr->length + 1);
		memset(outbuf, 0, bufferPtr->length + 1);
		memcpy(outbuf, bufferPtr->data, bufferPtr->length);

		strOut = outbuf;
		free(outbuf);

		//BIO_set_close(bio, BIO_NOCLOSE);
		BIO_free_all(bio);

		HRETURN_OK;

	}


	HRET Base64Decode (HCSTRR strIn, HSTRR strOut) {

		auto __f = [] (HCSTRR str) ->HSIZE {

			HSIZE len = str.length(), padding = 0;

			if (str[len - 1] == '=' && str[len-2] == '=') { //last two chars are =
				padding = 2;
			}
			else if (str[len-1] == '=') {//last char is =
				padding = 1;
			}
			
			return (len*3)/4 - padding;
		};

		BIO *bio = NULL, *b64 = NULL;

		HSIZE _len = __f(strIn);
		unsigned char* buf = (unsigned char*)malloc(_len + 1);
		memset(buf, 0, _len+1);

		bio = BIO_new_mem_buf(const_cast<char*>(strIn.c_str()), -1);
		b64 = BIO_new(BIO_f_base64());
		bio = BIO_push(b64, bio);

		BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer
		BIO_read(bio, buf, _len);

		strOut = HSTR(reinterpret_cast<char*>(buf));
		free(buf);
		
		BIO_free_all(bio);	

		HRETURN_OK;

	}

}

}


