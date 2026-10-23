#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <shlobj.h>
#include <process.h>
#include <stdio.h>
#include <wchar.h>
#include <errno.h>

static int fail(void)
{
    fputws(L"\nPress Enter to close...", stderr);
    (void)getwchar();
    return 1;
}

int wmain(void)
{
    wchar_t folder[MAX_PATH];
    HRESULT result = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL,
                                     SHGFP_TYPE_CURRENT, folder);
    if (FAILED(result)) {
        fwprintf(stderr, L"Cannot locate your Documents folder (0x%08lx).\n",
                 (unsigned long)result);
        return fail();
    }
    if (wcslen(folder) + wcslen(L"\\NPC-Gen-main") >= MAX_PATH) {
        fputws(L"The NPC-Gen folder path is too long.\n", stderr);
        return fail();
    }
    wcscat(folder, L"\\NPC-Gen-main");
    if (!SetCurrentDirectoryW(folder)) {
        fwprintf(stderr, L"Cannot open folder:\n%ls\nWindows error: %lu\n"
                 L"Extract NPC-Gen into this folder first.\n", folder,
                 (unsigned long)GetLastError());
        return fail();
    }
    wprintf(L"Starting NPC-Gen in:\n%ls\n\n", folder);
    fflush(stdout);
    intptr_t status = _wspawnlp(_P_WAIT, L"py.exe", L"py.exe", L"-m",
                               L"npc_gen", (wchar_t *)NULL);
    if (status == -1) {
        fwprintf(stderr, L"Cannot start Python's py.exe launcher (errno %d).\n"
                 L"Install Python with its Windows launcher and ensure py works in CMD.\n",
                 errno);
        return fail();
    }
    if (status != 0) {
        fwprintf(stderr, L"\nNPC-Gen exited with code %lld. See the error above.\n",
                 (long long)status);
        (void)fail();
    }
    return (int)status;
}
