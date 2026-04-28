//
// Created by RM UI Designer
// Static Edition
//

#ifndef UI_g_H
#define UI_g_H

#include "ui_interface.h"

extern ui_interface_rect_t *ui_g_Ungroup_NewRect;
extern ui_interface_line_t *ui_g_Ungroup_NewLine;
extern ui_interface_number_t *ui_g_Ungroup_NewFloat5;
extern ui_interface_ellipse_t *ui_g_Ungroup_NewEllipse;
extern ui_interface_arc_t *ui_g_Ungroup_NewArc;
extern ui_interface_string_t *ui_g_Ungroup_NewText8;
extern ui_interface_string_t *ui_g_Ungroup_NewText;
extern ui_interface_string_t *ui_g_Ungroup_NewText1;

void ui_init_g_Ungroup();
void ui_update_g_Ungroup();
void ui_remove_g_Ungroup();

extern ui_interface_number_t *ui_g_UngroupNUM_NewNumber1;
extern ui_interface_number_t *ui_g_UngroupNUM_NewFloat1;

void ui_init_g_UngroupNUM();
void ui_update_g_UngroupNUM();
void ui_remove_g_UngroupNUM();


#endif // UI_g_H
