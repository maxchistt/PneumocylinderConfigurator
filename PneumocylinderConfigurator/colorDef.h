#pragma once

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

#define BLACK        colorsDef[0]
#define BLUE         colorsDef[1]
#define GREEN        colorsDef[2]
#define CYAN         colorsDef[3]
#define RED          colorsDef[4]
#define MAGENTA      colorsDef[5]
#define BROWN        colorsDef[6]
#define LIGHTGRAY    colorsDef[7]
#define DARKGRAY     colorsDef[8]
#define LIGHTBLUE    colorsDef[9]
#define LIGHTGREEN   colorsDef[10]
#define LIGHTCYAN    colorsDef[11]
#define LIGHTRED     colorsDef[12]
#define LIGHTMAGENTA colorsDef[13]
#define YELLOW       colorsDef[14]
#define WHITE        colorsDef[15]
#define GOLDEN       colorsDef[16]

// Цвета для стилей
COLORREF colorsDef[] = {
  RGB(0,   0,   0),
  RGB(0,   0, 192),
  RGB(0, 192,   0),
  RGB(0, 128, 128),
  RGB(192,   0,   0),
  RGB(96,   0, 192),
  RGB(192, 128,   0),
  RGB(192, 192, 192),
  RGB(128, 158, 158),
  RGB(0,   0, 255),
  RGB(0, 255,   0),
  RGB(0, 125, 255),
  RGB(255,   0,   0),
  RGB(255,   0, 125),
  RGB(128, 128,   0),
  RGB(255, 255, 255),
  RGB(222, 222, 125),
};