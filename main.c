#include <pspkernel.h>
#include <pspdebug.h>

PSP_MODULE_INFO("Mario_Jasser", 0, 1, 1);

int main() {
    pspDebugScreenInit();
    pspDebugScreenPrintf("Hello Jasser!\n");
    pspDebugScreenPrintf("Mario Game Logic goes here...\n");
    pspDebugScreenPrintf("Press START to Exit to XMB");

    while(1) {
        // حلقة اللعبة
    }
    return 0;
}
