#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>

char* Hex( BYTE In );

void AddString( char* pBaseString , char* ToAdd )
{
	int len = strlen(pBaseString);
	int len2 = strlen(ToAdd);
	memcpy(&pBaseString[len],ToAdd,  len2);
}

int _tmain(int argc, char* argv[])
{
	
	puts("=> Reading the input file ...");
	
	HANDLE hFile = CreateFileA(argv[1], GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
	if (hFile == NULL || hFile == INVALID_HANDLE_VALUE)
	{
		printf("=> failed to access file: \"%s\"\n",argv[1]);
		return 0;
	}
	DWORD64 dwFileSize = GetFileSize(hFile, 0);
	BYTE* pFileContent=(BYTE*)VirtualAlloc(NULL,dwFileSize+20,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);DWORD bytes;
	BOOL bReadFile = ReadFile(hFile, pFileContent, dwFileSize, &bytes, 0);
	Sleep(500);
	
	printf("=> Output buffer size [%llu] ...\n",dwFileSize*10);
	char* pHeaderFile=(char*)VirtualAlloc(NULL,dwFileSize*10,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
	CloseHandle( hFile );
	
	puts("=> writing the output ...");
	
	sprintf(pHeaderFile,"#pragma once\r\n//Converted by the \"FileToHex\" tool from Speedi13\r\n\r\nunsigned char rawData[%d] =\r\n{\r\n    ",dwFileSize);
	int lineCounter = 0;
	DWORD64 i = 0, iOut = strlen(pHeaderFile);
	while (true)
	{
		char space[5];
		
		char* pHexString = Hex(pFileContent[i]);
			   pHeaderFile[iOut] = pHexString[0];//0
		iOut++;pHeaderFile[iOut] = pHexString[1];//x
		iOut++;pHeaderFile[iOut] = pHexString[2];//0
		iOut++;pHeaderFile[iOut] = pHexString[3];//0
		iOut++;pHeaderFile[iOut] = ',';
		iOut++;pHeaderFile[iOut] = ' ';
		lineCounter++;

		if (lineCounter > 15)
		{
			lineCounter = 0;
			iOut++;pHeaderFile[iOut] = '\r';
			iOut++;pHeaderFile[iOut] = '\n';
			iOut++;pHeaderFile[iOut] = ' ';
			iOut++;pHeaderFile[iOut] = ' ';
			iOut++;pHeaderFile[iOut] = ' ';
			iOut++;pHeaderFile[iOut] = ' ';
		}
		iOut++;
		i++;
		if (i >= dwFileSize) break;

	}
	
	AddString( pHeaderFile, "\n} ;" );

	VirtualFree(pFileContent, 0, MEM_RELEASE );

	puts("=> saveing the output to file ...");

	//save header:
	char* pFileName=(char*)VirtualAlloc(NULL,strlen(argv[1])+50,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
	sprintf(pFileName,"%s.h",argv[1]);

	HANDLE hFile2 = CreateFileA(pFileName, GENERIC_ALL, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
	WriteFile(hFile2, pHeaderFile, strlen(pHeaderFile), &bytes, 0);
	CloseHandle(hFile2);

	return 0;
}

char* Hex( BYTE In )
{
	switch (In)
	{
		case 0x0:
			return "0x00";
		case 0x1:
			return "0x01";
		case 0x2:
			return "0x02";
		case 0x3:
			return "0x03";
		case 0x4:
			return "0x04";
		case 0x5:
			return "0x05";
		case 0x6:
			return "0x06";
		case 0x7:
			return "0x07";
		case 0x8:
			return "0x08";
		case 0x9:
			return "0x09";
		case 0xA:
			return "0x0A";
		case 0xB:
			return "0x0B";
		case 0xC:
			return "0x0C";
		case 0xD:
			return "0x0D";
		case 0xE:
			return "0x0E";
		case 0xF:
			return "0x0F";
		case 0x10:
			return "0x10";
		case 0x11:
			return "0x11";
		case 0x12:
			return "0x12";
		case 0x13:
			return "0x13";
		case 0x14:
			return "0x14";
		case 0x15:
			return "0x15";
		case 0x16:
			return "0x16";
		case 0x17:
			return "0x17";
		case 0x18:
			return "0x18";
		case 0x19:
			return "0x19";
		case 0x1A:
			return "0x1A";
		case 0x1B:
			return "0x1B";
		case 0x1C:
			return "0x1C";
		case 0x1D:
			return "0x1D";
		case 0x1E:
			return "0x1E";
		case 0x1F:
			return "0x1F";
		case 0x20:
			return "0x20";
		case 0x21:
			return "0x21";
		case 0x22:
			return "0x22";
		case 0x23:
			return "0x23";
		case 0x24:
			return "0x24";
		case 0x25:
			return "0x25";
		case 0x26:
			return "0x26";
		case 0x27:
			return "0x27";
		case 0x28:
			return "0x28";
		case 0x29:
			return "0x29";
		case 0x2A:
			return "0x2A";
		case 0x2B:
			return "0x2B";
		case 0x2C:
			return "0x2C";
		case 0x2D:
			return "0x2D";
		case 0x2E:
			return "0x2E";
		case 0x2F:
			return "0x2F";
		case 0x30:
			return "0x30";
		case 0x31:
			return "0x31";
		case 0x32:
			return "0x32";
		case 0x33:
			return "0x33";
		case 0x34:
			return "0x34";
		case 0x35:
			return "0x35";
		case 0x36:
			return "0x36";
		case 0x37:
			return "0x37";
		case 0x38:
			return "0x38";
		case 0x39:
			return "0x39";
		case 0x3A:
			return "0x3A";
		case 0x3B:
			return "0x3B";
		case 0x3C:
			return "0x3C";
		case 0x3D:
			return "0x3D";
		case 0x3E:
			return "0x3E";
		case 0x3F:
			return "0x3F";
		case 0x40:
			return "0x40";
		case 0x41:
			return "0x41";
		case 0x42:
			return "0x42";
		case 0x43:
			return "0x43";
		case 0x44:
			return "0x44";
		case 0x45:
			return "0x45";
		case 0x46:
			return "0x46";
		case 0x47:
			return "0x47";
		case 0x48:
			return "0x48";
		case 0x49:
			return "0x49";
		case 0x4A:
			return "0x4A";
		case 0x4B:
			return "0x4B";
		case 0x4C:
			return "0x4C";
		case 0x4D:
			return "0x4D";
		case 0x4E:
			return "0x4E";
		case 0x4F:
			return "0x4F";
		case 0x50:
			return "0x50";
		case 0x51:
			return "0x51";
		case 0x52:
			return "0x52";
		case 0x53:
			return "0x53";
		case 0x54:
			return "0x54";
		case 0x55:
			return "0x55";
		case 0x56:
			return "0x56";
		case 0x57:
			return "0x57";
		case 0x58:
			return "0x58";
		case 0x59:
			return "0x59";
		case 0x5A:
			return "0x5A";
		case 0x5B:
			return "0x5B";
		case 0x5C:
			return "0x5C";
		case 0x5D:
			return "0x5D";
		case 0x5E:
			return "0x5E";
		case 0x5F:
			return "0x5F";
		case 0x60:
			return "0x60";
		case 0x61:
			return "0x61";
		case 0x62:
			return "0x62";
		case 0x63:
			return "0x63";
		case 0x64:
			return "0x64";
		case 0x65:
			return "0x65";
		case 0x66:
			return "0x66";
		case 0x67:
			return "0x67";
		case 0x68:
			return "0x68";
		case 0x69:
			return "0x69";
		case 0x6A:
			return "0x6A";
		case 0x6B:
			return "0x6B";
		case 0x6C:
			return "0x6C";
		case 0x6D:
			return "0x6D";
		case 0x6E:
			return "0x6E";
		case 0x6F:
			return "0x6F";
		case 0x70:
			return "0x70";
		case 0x71:
			return "0x71";
		case 0x72:
			return "0x72";
		case 0x73:
			return "0x73";
		case 0x74:
			return "0x74";
		case 0x75:
			return "0x75";
		case 0x76:
			return "0x76";
		case 0x77:
			return "0x77";
		case 0x78:
			return "0x78";
		case 0x79:
			return "0x79";
		case 0x7A:
			return "0x7A";
		case 0x7B:
			return "0x7B";
		case 0x7C:
			return "0x7C";
		case 0x7D:
			return "0x7D";
		case 0x7E:
			return "0x7E";
		case 0x7F:
			return "0x7F";
		case 0x80:
			return "0x80";
		case 0x81:
			return "0x81";
		case 0x82:
			return "0x82";
		case 0x83:
			return "0x83";
		case 0x84:
			return "0x84";
		case 0x85:
			return "0x85";
		case 0x86:
			return "0x86";
		case 0x87:
			return "0x87";
		case 0x88:
			return "0x88";
		case 0x89:
			return "0x89";
		case 0x8A:
			return "0x8A";
		case 0x8B:
			return "0x8B";
		case 0x8C:
			return "0x8C";
		case 0x8D:
			return "0x8D";
		case 0x8E:
			return "0x8E";
		case 0x8F:
			return "0x8F";
		case 0x90:
			return "0x90";
		case 0x91:
			return "0x91";
		case 0x92:
			return "0x92";
		case 0x93:
			return "0x93";
		case 0x94:
			return "0x94";
		case 0x95:
			return "0x95";
		case 0x96:
			return "0x96";
		case 0x97:
			return "0x97";
		case 0x98:
			return "0x98";
		case 0x99:
			return "0x99";
		case 0x9A:
			return "0x9A";
		case 0x9B:
			return "0x9B";
		case 0x9C:
			return "0x9C";
		case 0x9D:
			return "0x9D";
		case 0x9E:
			return "0x9E";
		case 0x9F:
			return "0x9F";
		case 0xA0:
			return "0xA0";
		case 0xA1:
			return "0xA1";
		case 0xA2:
			return "0xA2";
		case 0xA3:
			return "0xA3";
		case 0xA4:
			return "0xA4";
		case 0xA5:
			return "0xA5";
		case 0xA6:
			return "0xA6";
		case 0xA7:
			return "0xA7";
		case 0xA8:
			return "0xA8";
		case 0xA9:
			return "0xA9";
		case 0xAA:
			return "0xAA";
		case 0xAB:
			return "0xAB";
		case 0xAC:
			return "0xAC";
		case 0xAD:
			return "0xAD";
		case 0xAE:
			return "0xAE";
		case 0xAF:
			return "0xAF";
		case 0xB0:
			return "0xB0";
		case 0xB1:
			return "0xB1";
		case 0xB2:
			return "0xB2";
		case 0xB3:
			return "0xB3";
		case 0xB4:
			return "0xB4";
		case 0xB5:
			return "0xB5";
		case 0xB6:
			return "0xB6";
		case 0xB7:
			return "0xB7";
		case 0xB8:
			return "0xB8";
		case 0xB9:
			return "0xB9";
		case 0xBA:
			return "0xBA";
		case 0xBB:
			return "0xBB";
		case 0xBC:
			return "0xBC";
		case 0xBD:
			return "0xBD";
		case 0xBE:
			return "0xBE";
		case 0xBF:
			return "0xBF";
		case 0xC0:
			return "0xC0";
		case 0xC1:
			return "0xC1";
		case 0xC2:
			return "0xC2";
		case 0xC3:
			return "0xC3";
		case 0xC4:
			return "0xC4";
		case 0xC5:
			return "0xC5";
		case 0xC6:
			return "0xC6";
		case 0xC7:
			return "0xC7";
		case 0xC8:
			return "0xC8";
		case 0xC9:
			return "0xC9";
		case 0xCA:
			return "0xCA";
		case 0xCB:
			return "0xCB";
		case 0xCC:
			return "0xCC";
		case 0xCD:
			return "0xCD";
		case 0xCE:
			return "0xCE";
		case 0xCF:
			return "0xCF";
		case 0xD0:
			return "0xD0";
		case 0xD1:
			return "0xD1";
		case 0xD2:
			return "0xD2";
		case 0xD3:
			return "0xD3";
		case 0xD4:
			return "0xD4";
		case 0xD5:
			return "0xD5";
		case 0xD6:
			return "0xD6";
		case 0xD7:
			return "0xD7";
		case 0xD8:
			return "0xD8";
		case 0xD9:
			return "0xD9";
		case 0xDA:
			return "0xDA";
		case 0xDB:
			return "0xDB";
		case 0xDC:
			return "0xDC";
		case 0xDD:
			return "0xDD";
		case 0xDE:
			return "0xDE";
		case 0xDF:
			return "0xDF";
		case 0xE0:
			return "0xE0";
		case 0xE1:
			return "0xE1";
		case 0xE2:
			return "0xE2";
		case 0xE3:
			return "0xE3";
		case 0xE4:
			return "0xE4";
		case 0xE5:
			return "0xE5";
		case 0xE6:
			return "0xE6";
		case 0xE7:
			return "0xE7";
		case 0xE8:
			return "0xE8";
		case 0xE9:
			return "0xE9";
		case 0xEA:
			return "0xEA";
		case 0xEB:
			return "0xEB";
		case 0xEC:
			return "0xEC";
		case 0xED:
			return "0xED";
		case 0xEE:
			return "0xEE";
		case 0xEF:
			return "0xEF";
		case 0xF0:
			return "0xF0";
		case 0xF1:
			return "0xF1";
		case 0xF2:
			return "0xF2";
		case 0xF3:
			return "0xF3";
		case 0xF4:
			return "0xF4";
		case 0xF5:
			return "0xF5";
		case 0xF6:
			return "0xF6";
		case 0xF7:
			return "0xF7";
		case 0xF8:
			return "0xF8";
		case 0xF9:
			return "0xF9";
		case 0xFA:
			return "0xFA";
		case 0xFB:
			return "0xFB";
		case 0xFC:
			return "0xFC";
		case 0xFD:
			return "0xFD";
		case 0xFE:
			return "0xFE";
		case 0xFF:
			return "0xFF";
	};

	return "0x??";
}
