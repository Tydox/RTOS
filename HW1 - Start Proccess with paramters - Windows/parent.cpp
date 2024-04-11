#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>


int main(void) {
	printf("Enter FilePath & Fibbonacy Length: example: 'C:\child.exe 7' \n");
		char Pr_Data[256] = {};
		scanf("%[^\n]", Pr_Data);
		//printf("you entered: %s\n", Pr_Data);

		TCHAR ProcessName[256];
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		int i=0;
		while (ProcessName[i++] = (TCHAR)Pr_Data[i]);

		//char test[256] = {};
		//i = 0;
		//while (test[i++] = (char)Pr_Data[i]);
		//printf("Tchar Converstion: %s", test);


		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));

		// Start the child process.
		if (!CreateProcess(NULL,   // No module name (use command line).
			ProcessName, // Command line.
			NULL,             // Process handle not inheritable.
			NULL,             // Thread handle not inheritable.
			FALSE,            // Set handle inheritance to FALSE.
			0,                // No creation flags.
			NULL,             // Use parent's environment block.
			NULL,             // Use parent's starting directory.
			&si,              // Pointer to STARTUPINFO structure.
			&pi)             // Pointer to PROCESS_INFORMATION structure.
			) {
			printf("CreateProcess failed (%d).\n", GetLastError());
			return -1;
		}

		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);

		// Close process and thread handles.
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		printf("\n\n");
		return 0;
}
