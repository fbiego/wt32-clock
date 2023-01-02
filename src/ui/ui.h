// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: clock

#ifndef _CLOCK_UI_H
#define _CLOCK_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

void showNotification_Animation( lv_obj_t *TargetObject, int delay);
extern lv_obj_t *ui_homeScreen;
extern lv_obj_t *ui_minuteArc;
extern lv_obj_t *ui_hourArc;
extern lv_obj_t *ui_timeLabel;
extern lv_obj_t *ui_dateLabel;
extern lv_obj_t *ui_notificationPanel;
extern lv_obj_t *ui_notificationTitle;
extern lv_obj_t *ui_notificationText;


LV_IMG_DECLARE( ui_img_1_png);   // assets/1.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
