/*
 * src/lcd.h
 *
 *  Copyleft (C) 2015  IliaUni Robotics TeaM  
 * 
 * Simple program to drive LCD device
 */


/* For include header in CPP code */
#ifdef __cplusplus
extern "C" {
#endif


/* LCD pins */
#define RS 11
#define STRB 10

/* Commands */
#define LCD_CLEAR 0x01
#define LCD_HOME  0x02
#define LCD_ENTRY 0x04
#define LCD_ON_OFF  0x08
#define LCD_CDSHIFT 0x10
#define LCD_FUNC  0x20
#define LCD_CGRAM 0x40
#define LCD_DGRAM 0x80
#define LCD_ENTRY_SH  0x01
#define LCD_ENTRY_ID  0x02
#define LCD_ON_OFF_B  0x01
#define LCD_ON_OFF_C  0x02
#define LCD_ON_OFF_D  0x04
#define LCD_FUNC_F  0x04
#define LCD_FUNC_N  0x08
#define LCD_FUNC_DL 0x10
#define LCD_CDSHIFT_RL  0x04


/* 
 * lcd_position - Function sets cursor position on 
 * lcd display. Arguments x and y are the cordinates.
 */
void lcd_position(int x, int y);

/*
 * lcd_puts - Function puts string on the display.
 * Argument string is string which we want to put.
 */
void lcd_puts(char *string);


/* 
 * clear_lcd - This function clears lcd 
 * display when there is printed something.
 */
void clear_lcd();


/* 
 * init_lcd - Function initializes lcd diplay and 
 * makes display ready to print something on it.
 */
void init_lcd(void);


/* For include header in CPP code */
#ifdef __cplusplus
}
#endif
