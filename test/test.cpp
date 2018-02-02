


#include <base64.h>
#include <httphelper.h>
#include <iostream>

using namespace std;

using namespace HUIBASE;

using namespace HUIBASE::CRYPTO;

using namespace HUIBASE::HTTP;

int test_crypto() {
	static HCSTR str("333hello tom666");

	HSTR s64, src;

	(void)Base64Encode(str, s64);

	cout << s64 << endl;

	(void)Base64Decode(s64, src);

	cout << "[" << src << "]" << endl;

	return 0;
	
}

void test_http() {

	HSTR str;
	HttpGet("www.baidu.com", str);

	cout << str << endl;
	
}

int main() {

	test_crypto();

	test_http();

	return 0;
}

