#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

/* تعريف معلومات الوحدة */
PSP_MODULE_INFO("Mario_Jasser", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main() {
    pspDebugScreenInit();
    SceCtrlData pad;
    int x = 20, y = 10; // إحداثيات ماريو البدائية

    while(1) {
        pspDebugScreenClear();
        pspDebugScreenSetXY(0, 0);
        pspDebugScreenPrintf("Mario PSP by Jasser\n");
        pspDebugScreenPrintf("Use D-Pad to Move. Press Start to Exit.");

        // رسم ماريو (حرف M) في الإحداثيات
        pspDebugScreenSetXY(x, y);
        pspDebugScreenPrintf("M");

        // قراءة الأزرار من جهاز PSP
        sceCtrlReadBufferPositive(&pad, 1);
        
        if (pad.Buttons & PSP_CTRL_UP) y--;
        if (pad.Buttons & PSP_CTRL_DOWN) y++;
        if (pad.Buttons & PSP_CTRL_LEFT) x--;
        if (pad.Buttons & PSP_CTRL_RIGHT) x++;
        
        // الخروج من اللعبة عند الضغط على Start
        if (pad.Buttons & PSP_CTRL_START) break;

        // تأخير بسيط (20 ملي ثانية) لجعل الحركة سلسة ولا يختفي الحرف
        sceKernelDelayThread(20000); 
    }

    sceKernelExitGame();
    return 0;
}
