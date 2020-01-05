/*******************************************************************************

    Driver for RGB
    引脚连接：
        G0    26
        R0    27
        B0    25

        G1    12
        R1    13
        B1    14
*******************************************************************************/

#ifndef __RGB_H__
#define __RGB_H__

// The color of LED
typedef enum {
    GRB_NONE = 0,
    GRB_GREEN,
    GRB_RED,
    GRB_BLUE,
    GRB_YELLOW,
    GRB_PURPLE,
    GRB_CYAN,
    GRB_WHITE,
    GRB_COLOR_MAX,
}grb_color_t;

void grb_init(void);
int grb_color_set(int num, grb_color_t color);

#endif