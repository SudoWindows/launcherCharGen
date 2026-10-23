# NPC-Gen launcher

Double-click `launcher.exe` on Windows 64-bit. It runs these commands in a visible console:

```cmd
cd /d "%USERPROFILE%\Documents"
cd NPC-Gen-main
py -m npc_gen
```

Python's `py` launcher and NPC-Gen's dependencies must already be installed on Windows. The NPC-Gen folder must be at the path shown above. The launcher stops if either directory change fails, waits for NPC-Gen to finish, and pauses on an error so you can read it. It does not require administrator privileges.

Build on Linux with MinGW-w64:

```sh
x86_64-w64-mingw32-gcc -O2 -Wall -Wextra -Werror launcher.c -o launcher.exe
```

Build on Windows in a Visual Studio Developer Command Prompt:

```cmd
cl /W4 /O2 launcher.c /Fe:launcher.exe
```
