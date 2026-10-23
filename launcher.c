#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int result = system("cmd.exe /d /c \"cd /d \"%USERPROFILE%\\Documents\" && cd NPC-Gen-main && py -m npc_gen\"");
    if (result != 0) {
        fprintf(stderr, "\nNPC-Gen could not complete (exit code %d).\n"
                        "Check that Python's py launcher is installed and NPC-Gen is in\n"
                        "%%USERPROFILE%%\\Documents\\NPC-Gen-main.\n", result);
        (void)system("pause");
    }
    return result;
}
