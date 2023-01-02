// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: clock

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void showNotification_Animation( lv_obj_t *TargetObject, int delay);
lv_obj_t *ui_homeScreen;
lv_obj_t *ui_minuteArc;
lv_obj_t *ui_hourArc;
lv_obj_t *ui_timeLabel;
lv_obj_t *ui_dateLabel;
lv_obj_t *ui_notificationPanel;
lv_obj_t *ui_notificationTitle;
lv_obj_t *ui_notificationText;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void showNotification_Animation( lv_obj_t *TargetObject, int delay)
{
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 500);
lv_anim_set_user_data(&PropertyAnimation_0,TargetObject);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x );
lv_anim_set_values(&PropertyAnimation_0, 150, -20 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_start(&PropertyAnimation_0);
lv_anim_t PropertyAnimation_1;
lv_anim_init(&PropertyAnimation_1);
lv_anim_set_time(&PropertyAnimation_1, 500);
lv_anim_set_user_data(&PropertyAnimation_1,TargetObject);
lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x );
lv_anim_set_values(&PropertyAnimation_1, -20, 150 );
lv_anim_set_path_cb( &PropertyAnimation_1, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_1, delay + 2000 );
lv_anim_set_playback_time(&PropertyAnimation_1, 0);
lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
lv_anim_set_early_apply( &PropertyAnimation_1, false );
lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_homeScreen_screen_init(void)
{
ui_homeScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_homeScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_img_src( ui_homeScreen, &ui_img_1_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_img_recolor(ui_homeScreen, lv_color_hex(0x0CB3C6), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_img_recolor_opa(ui_homeScreen, 50, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_minuteArc = lv_arc_create(ui_homeScreen);
lv_obj_set_width( ui_minuteArc, 220);
lv_obj_set_height( ui_minuteArc, 220);
lv_obj_set_align( ui_minuteArc, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_minuteArc, LV_OBJ_FLAG_CLICKABLE );    /// Flags
lv_arc_set_range(ui_minuteArc, 0,60);
lv_arc_set_value(ui_minuteArc, 43);
lv_arc_set_bg_angles(ui_minuteArc,270,269);
lv_obj_set_style_radius(ui_minuteArc, 110, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_minuteArc, lv_color_hex(0x024E56), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_minuteArc, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_color(ui_minuteArc, lv_color_hex(0x024E56), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_minuteArc, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_minuteArc, 5, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_minuteArc, lv_color_hex(0x00E1FA), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_minuteArc, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_minuteArc, 5, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_minuteArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_minuteArc, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_hourArc = lv_arc_create(ui_homeScreen);
lv_obj_set_width( ui_hourArc, 200);
lv_obj_set_height( ui_hourArc, 200);
lv_obj_set_align( ui_hourArc, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_hourArc, LV_OBJ_FLAG_CLICKABLE );    /// Flags
lv_arc_set_range(ui_hourArc, 0,12);
lv_arc_set_value(ui_hourArc, 10);
lv_arc_set_bg_angles(ui_hourArc,270,269);
lv_obj_set_style_arc_color(ui_hourArc, lv_color_hex(0x024E56), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_hourArc, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_hourArc, 7, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_hourArc, lv_color_hex(0x00E1FA), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_hourArc, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_hourArc, 7, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_hourArc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_hourArc, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_timeLabel = lv_label_create(ui_homeScreen);
lv_obj_set_width( ui_timeLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_timeLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_timeLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_timeLabel,"10:43");
lv_obj_set_style_text_color(ui_timeLabel, lv_color_hex(0x00E1FA), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_timeLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_timeLabel, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_timeLabel, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_dateLabel = lv_label_create(ui_homeScreen);
lv_obj_set_width( ui_dateLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_dateLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_dateLabel, 20 );
lv_obj_set_y( ui_dateLabel, -20 );
lv_obj_set_align( ui_dateLabel, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_dateLabel,"Wednesday\nJanuary 04");
lv_obj_set_style_text_color(ui_dateLabel, lv_color_hex(0x00E1FA), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_dateLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_radius(ui_dateLabel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_dateLabel, lv_color_hex(0x003232), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_dateLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_dateLabel, lv_color_hex(0x00E1FA), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_dateLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_dateLabel, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_dateLabel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_dateLabel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_dateLabel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_dateLabel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationPanel = lv_obj_create(ui_homeScreen);
lv_obj_set_width( ui_notificationPanel, 150);
lv_obj_set_height( ui_notificationPanel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_notificationPanel, 150 );
lv_obj_set_y( ui_notificationPanel, 20 );
lv_obj_set_align( ui_notificationPanel, LV_ALIGN_TOP_RIGHT );
lv_obj_clear_flag( ui_notificationPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_notificationPanel, lv_color_hex(0x003232), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_notificationPanel, 200, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_notificationPanel, lv_color_hex(0x00FFFA), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_notificationPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_notificationPanel, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_notificationPanel, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_notificationPanel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_notificationPanel, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_notificationPanel, 10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationTitle = lv_label_create(ui_notificationPanel);
lv_obj_set_width( ui_notificationTitle, 120);
lv_obj_set_height( ui_notificationTitle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_style_text_color(ui_notificationTitle, lv_color_hex(0x00E1FA), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_notificationTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_notificationTitle, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationText = lv_label_create(ui_notificationPanel);
lv_obj_set_width( ui_notificationText, 120);
lv_obj_set_height( ui_notificationText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_notificationText, 2 );
lv_obj_set_y( ui_notificationText, 25 );
lv_obj_set_style_text_color(ui_notificationText, lv_color_hex(0x00E1FA), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_notificationText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_homeScreen_screen_init();
lv_disp_load_scr( ui_homeScreen);
}
