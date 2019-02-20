#ifndef KEYMAP_H
#define KEYMAP_H

#endif // KEYMAP_H
#include <QMap>

static QMap<int, int> keycode;
static QMap<int, QString>QKeyToStr;

void keyCodeMapInit(){
    // 英文字母 a-z
    for(int i = 0; i<26;i++)
    {
        keycode[i+65] = 0x04+i;
    }
    // 键盘上方数字键 0-9
    keycode [48] = 0x27;
    for(int i = 0; i<9;i++)
    {
        keycode[i+49] = 0x1e + i;
    }
    // F1 - F12
    for(int i = 0; i<12; i++)
    {
        keycode[16777264+i] = 0x3A+i;
    }
    keycode[16777220] = 0x28;// Return
    keycode[16777219] = 0x2A; // Backspace
    keycode[16777217] = 0X2B; // Tab
    keycode[32] = 0x2C; // Space
    keycode[45] = 0x2D; // -_
    keycode[61] = 0x2E; // =+
    keycode[91] = 0x2F; // [{
    keycode[93] = 0x30; // ]}
    keycode[92] = 0x31; // \|
    keycode[59] = 0x33; // ;:
    keycode[39] = 0x34; // '"
    keycode[96] = 0x35; // `~
    keycode[44] = 0x36; // ,<
    keycode[46] = 0X37; // .>
    keycode[47] = 0x38; // /?
    keycode[16777252] = 0x39; // CapsLock
    keycode[16777254] = 0x47; // ScrLk
    keycode[16777224] = 0x48; // Pause
    keycode[16777222] = 0x49; // Insert
    keycode[16777232] = 0x4A; // Home
    keycode[16777238] = 0x4B; // PgUp
    keycode[16777223] = 0x4C; // Delete
    keycode[16777233] = 0x4D; // End
    keycode[16777239] = 0x4E; // PgDn
    keycode[16777236] = 0x4F; // Right Arrow
    keycode[16777234] = 0x50; // Left Arrow
    keycode[16777237] = 0x51; // Down Arrow
    keycode[16777235] = 0x52; // Up Arrow
    keycode[16777253] = 0x53; // Num Lock
//    keycode[47] = 0x54; // keypad / 和按键上的 /? 重复了
    keycode[42] = 0x55; // keypad *
//    keycode[45] = 0x56; // keypad - 和按键上的 -— 重复了
    keycode[43] = 0x57; // keypad +
    keycode[16777221] = 0x58; // keypad Enter
    keycode[16777249] = 0xE0; // left control
    keycode[16777248] = 0xE1; // left shift
    keycode[16777251] = 0xE2; // left alt
    keycode[16777250] = 0xE3; // win  left Gui
}

void QKeyToStrMapInit(){
    // 英文字母 a-z
    for(int i = 0; i<26;i++)
    {
        QKeyToStr[i+65] = 65 + i;
    }
    // 数字 0-9
    for(int i = 0; i<10; i++)
    {
        QKeyToStr[48+i] = 48+i;
    }
    QKeyToStr[16777264] = "F1";
    QKeyToStr[16777265] = "F2";
    QKeyToStr[16777266] = "F3";
    QKeyToStr[16777267] = "F4";
    QKeyToStr[16777268] = "F5";
    QKeyToStr[16777269] = "F6";
    QKeyToStr[16777270] = "F7";
    QKeyToStr[16777271] = "F8";
    QKeyToStr[16777272] = "F9";
    QKeyToStr[16777273] = "F10";
    QKeyToStr[16777274] = "F11";
    QKeyToStr[16777275] = "F12";
    QKeyToStr[16777220] = "Return";// Return
    QKeyToStr[16777219] = "Backspace"; // Backspace
    QKeyToStr[16777217] = "Tab"; // Tab
    QKeyToStr[32] = "Space"; // Space
    QKeyToStr[45] = "-"; // -_
    QKeyToStr[61] = "="; // =+
    QKeyToStr[91] = "["; // [{
    QKeyToStr[93] = "]"; // ]}
    QKeyToStr[92] = "'\'"; // \|
    QKeyToStr[59] = ";"; // ;:
    QKeyToStr[39] = "'"; // '"
    QKeyToStr[96] = "`"; // `~
    QKeyToStr[44] = ","; // ,<
    QKeyToStr[46] = "."; // .>
    QKeyToStr[47] = "/"; // /?
    QKeyToStr[16777252] = "CapsLock"; // CapsLock
    QKeyToStr[16777254] = "ScrLk"; // ScrLk
    QKeyToStr[16777224] = "Pause"; // Pause
    QKeyToStr[16777222] = "Insert"; // Insert
    QKeyToStr[16777232] = "Home"; // Home
    QKeyToStr[16777238] = "PgUp"; // PgUp
    QKeyToStr[16777223] = "Delete"; // Delete
    QKeyToStr[16777233] = "End"; // End
    QKeyToStr[16777239] = "PgDn"; // PgDn
    QKeyToStr[16777236] = "Right"; // Right Arrow
    QKeyToStr[16777234] = "Left"; // Left Arrow
    QKeyToStr[16777237] = "Down"; // Down Arrow
    QKeyToStr[16777235] = "Up"; // Up Arrow
    QKeyToStr[16777253] = "Num Lcok"; // Num Lock
//    QKeyToStr[47] = 0x54; // keypad / 和按键上的 /? 重复了
    QKeyToStr[42] = "*"; // keypad *
//    QKeyToStr[45] = 0x56; // keypad - 和按键上的 -— 重复了
    QKeyToStr[43] = "+"; // keypad +
    QKeyToStr[16777221] = "KeyPad Enter"; // keypad Enter
    QKeyToStr[16777249] = "Ctrl"; // left control
    QKeyToStr[16777248] = "Shift"; // left shift
    QKeyToStr[16777251] = "Alt"; // left alt
    QKeyToStr[16777250] = "Win"; // win  left Gui
}

