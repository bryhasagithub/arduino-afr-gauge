#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"

void setup()
{
  Config_Init();
  LCD_Init();
  LCD_SetBacklight(1000);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, BLACK);
  Paint_Clear(BLACK);
  Paint_DrawCircle(120,120, 120, WHITE ,DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
  Paint_DrawLine  (120, 120, 100, 210, RED ,DOT_PIXEL_2X2,LINE_STYLE_SOLID); 
  Paint_DrawLine  (120, 0, 120, 12, WHITE ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
  Paint_DrawLine  (120, 228, 120, 240, WHITE ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
  Paint_DrawLine  (0, 120, 12, 120, WHITE ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
  Paint_DrawLine  (228, 120, 240, 120, WHITE ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
  Paint_DrawString_EN(50, 50, "neat", &Font24, BLACK, WHITE);
  // Paint_DrawImage(gImage_70X70, 85, 25, 70, 70);
  // Paint_DrawLine  (120, 120, 70, 70,RED ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
  // Paint_DrawLine  (120, 120, 176, 64,RED ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
}
void loop()
{
  
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

