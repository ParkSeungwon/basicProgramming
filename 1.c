#include <stdio.h>
int main(void) {
	int x = 0x12345678;
	unsigned char *xp = (char *)&x;//정수의 주소 전달
	printf("바이트순서: %x %x %x %x\n", xp[0], xp[1], xp[2], xp[3]);//1바이트씩 프린트
	return 0;
}
