# NPC-Gen launcher

Double-click `launcher.exe` on Windows 64-bit. It opens your Windows Documents folder (including redirected OneDrive Documents), enters `NPC-Gen-main`, and runs Python in a visible console. This is equivalent to these commands for a standard Documents location:

```cmd
cd /d "%USERPROFILE%\Documents"
cd NPC-Gen-main
py -m npc_gen
```

Python's `py` launcher and NPC-Gen's dependencies must already be installed on Windows. The NPC-Gen folder must be at the path shown above. The launcher stops if either directory change fails, waits for NPC-Gen to finish, and pauses on an error so you can read it. It does not require administrator privileges.

Build on Linux with MinGW-w64:

```sh
x86_64-w64-mingw32-gcc -Os -s -municode -Wall -Wextra -Werror launcher.c -o launcher.exe -lshell32
```

Build on Windows in a Visual Studio Developer Command Prompt:

```cmd
cl /W4 /O2 launcher.c /Fe:launcher.exe shell32.lib
```

If startup fails, the launcher prints the actual folder or Python error and waits for Enter. NPC-Gen must be an extracted project folder containing the `npc_gen` Python module, not a ZIP file.
