#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("\n--------------------\nChild Activated!\n--------------------\n");
	printf("You entered the following BOOT commands:\n");
	for (int i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	if (argv[1] != NULL) {
		int fib_len = atoi(argv[1]);
		printf("Calculating Fibbonacy Sequence in length: [%d]\n", fib_len);

		int num1 = 0, num2 = 1, nextTerm = 0;

		// displays the first two terms which is always 0 and 1
		printf("Fibonacci Series: %d, %d, ", num1, num2);
		nextTerm = num1 + num2;
		int x = 2;
		while (x++ < fib_len) {
			printf("%d, ", nextTerm);
			num1 = num2;
			num2 = nextTerm;
			nextTerm = num1 + num2;
		}
	}
}