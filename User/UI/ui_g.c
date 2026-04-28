//
// Created by RM UI Designer
// Static Edition
//

#include <string.h>

#include "ui_interface.h"

ui_5_frame_t ui_g_Ungroup_0;

ui_interface_rect_t *ui_g_Ungroup_NewRect = (ui_interface_rect_t*)&(ui_g_Ungroup_0.data[0]);
ui_interface_line_t *ui_g_Ungroup_NewLine = (ui_interface_line_t*)&(ui_g_Ungroup_0.data[1]);
ui_interface_number_t *ui_g_Ungroup_NewFloat5 = (ui_interface_number_t*)&(ui_g_Ungroup_0.data[2]);
ui_interface_ellipse_t *ui_g_Ungroup_NewEllipse = (ui_interface_ellipse_t*)&(ui_g_Ungroup_0.data[3]);
ui_interface_arc_t *ui_g_Ungroup_NewArc = (ui_interface_arc_t*)&(ui_g_Ungroup_0.data[4]);

void _ui_init_g_Ungroup_0() {
    for (int i = 0; i < 5; i++) {
        ui_g_Ungroup_0.data[i].figure_name[0] = 0;
        ui_g_Ungroup_0.data[i].figure_name[1] = 0;
        ui_g_Ungroup_0.data[i].figure_name[2] = i + 0;
        ui_g_Ungroup_0.data[i].operate_type = 1;
    }
    for (int i = 5; i < 5; i++) {
        ui_g_Ungroup_0.data[i].operate_type = 0;
    }

    ui_g_Ungroup_NewRect->figure_type = 1;
    ui_g_Ungroup_NewRect->operate_type = 1;
    ui_g_Ungroup_NewRect->layer = 0;
    ui_g_Ungroup_NewRect->color = 6;
    ui_g_Ungroup_NewRect->start_x = 702;
    ui_g_Ungroup_NewRect->start_y = 269;
    ui_g_Ungroup_NewRect->width = 10;
    ui_g_Ungroup_NewRect->end_x = 1221;
    ui_g_Ungroup_NewRect->end_y = 788;

    ui_g_Ungroup_NewLine->figure_type = 0;
    ui_g_Ungroup_NewLine->operate_type = 1;
    ui_g_Ungroup_NewLine->layer = 0;
    ui_g_Ungroup_NewLine->color = 4;
    ui_g_Ungroup_NewLine->start_x = 710;
    ui_g_Ungroup_NewLine->start_y = 278;
    ui_g_Ungroup_NewLine->width = 10;
    ui_g_Ungroup_NewLine->end_x = 1214;
    ui_g_Ungroup_NewLine->end_y = 784;

    ui_g_Ungroup_NewFloat5->figure_type = 5;
    ui_g_Ungroup_NewFloat5->operate_type = 1;
    ui_g_Ungroup_NewFloat5->layer = 0;
    ui_g_Ungroup_NewFloat5->color = 0;
    ui_g_Ungroup_NewFloat5->start_x = 50;
    ui_g_Ungroup_NewFloat5->start_y = 50;
    ui_g_Ungroup_NewFloat5->width = 2;
    ui_g_Ungroup_NewFloat5->font_size = 20;
    ui_g_Ungroup_NewFloat5->number = 12345;

    ui_g_Ungroup_NewEllipse->figure_type = 3;
    ui_g_Ungroup_NewEllipse->operate_type = 1;
    ui_g_Ungroup_NewEllipse->layer = 0;
    ui_g_Ungroup_NewEllipse->color = 1;
    ui_g_Ungroup_NewEllipse->start_x = 200;
    ui_g_Ungroup_NewEllipse->start_y = 370;
    ui_g_Ungroup_NewEllipse->width = 1;
    ui_g_Ungroup_NewEllipse->rx = 74;
    ui_g_Ungroup_NewEllipse->ry = 74;

    ui_g_Ungroup_NewArc->figure_type = 4;
    ui_g_Ungroup_NewArc->operate_type = 1;
    ui_g_Ungroup_NewArc->layer = 0;
    ui_g_Ungroup_NewArc->color = 0;
    ui_g_Ungroup_NewArc->start_x = 135;
    ui_g_Ungroup_NewArc->start_y = 577;
    ui_g_Ungroup_NewArc->width = 1;
    ui_g_Ungroup_NewArc->start_angle = 0;
    ui_g_Ungroup_NewArc->end_angle = 90;
    ui_g_Ungroup_NewArc->rx = 57;
    ui_g_Ungroup_NewArc->ry = 57;


    ui_proc_5_frame(&ui_g_Ungroup_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_0, sizeof(ui_g_Ungroup_0));
}

void _ui_update_g_Ungroup_0() {
    for (int i = 0; i < 5; i++) {
        ui_g_Ungroup_0.data[i].operate_type = 2;
    }

    ui_proc_5_frame(&ui_g_Ungroup_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_0, sizeof(ui_g_Ungroup_0));
}

void _ui_remove_g_Ungroup_0() {
    for (int i = 0; i < 5; i++) {
        ui_g_Ungroup_0.data[i].operate_type = 3;
    }

    ui_proc_5_frame(&ui_g_Ungroup_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_0, sizeof(ui_g_Ungroup_0));
}

ui_string_frame_t ui_g_Ungroup_1;
ui_interface_string_t* ui_g_Ungroup_NewText8 = &(ui_g_Ungroup_1.option);

void _ui_init_g_Ungroup_1() {
    ui_g_Ungroup_1.option.figure_name[0] = 0;
    ui_g_Ungroup_1.option.figure_name[1] = 0;
    ui_g_Ungroup_1.option.figure_name[2] = 5;
    ui_g_Ungroup_1.option.operate_type = 1;

    ui_g_Ungroup_NewText8->figure_type = 7;
    ui_g_Ungroup_NewText8->operate_type = 1;
    ui_g_Ungroup_NewText8->layer = 0;
    ui_g_Ungroup_NewText8->color = 0;
    ui_g_Ungroup_NewText8->start_x = 50;
    ui_g_Ungroup_NewText8->start_y = 50;
    ui_g_Ungroup_NewText8->width = 2;
    ui_g_Ungroup_NewText8->font_size = 20;
    ui_g_Ungroup_NewText8->str_length = 4;
    strcpy(ui_g_Ungroup_NewText8->string, "Text");


    ui_proc_string_frame(&ui_g_Ungroup_1);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_1, sizeof(ui_g_Ungroup_1));
}

void _ui_update_g_Ungroup_1() {
    ui_g_Ungroup_1.option.operate_type = 2;

    ui_proc_string_frame(&ui_g_Ungroup_1);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_1, sizeof(ui_g_Ungroup_1));
}

void _ui_remove_g_Ungroup_1() {
    ui_g_Ungroup_1.option.operate_type = 3;

    ui_proc_string_frame(&ui_g_Ungroup_1);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_1, sizeof(ui_g_Ungroup_1));
}
ui_string_frame_t ui_g_Ungroup_2;
ui_interface_string_t* ui_g_Ungroup_NewText = &(ui_g_Ungroup_2.option);

void _ui_init_g_Ungroup_2() {
    ui_g_Ungroup_2.option.figure_name[0] = 0;
    ui_g_Ungroup_2.option.figure_name[1] = 0;
    ui_g_Ungroup_2.option.figure_name[2] = 6;
    ui_g_Ungroup_2.option.operate_type = 1;

    ui_g_Ungroup_NewText->figure_type = 7;
    ui_g_Ungroup_NewText->operate_type = 1;
    ui_g_Ungroup_NewText->layer = 0;
    ui_g_Ungroup_NewText->color = 2;
    ui_g_Ungroup_NewText->start_x = 70;
    ui_g_Ungroup_NewText->start_y = 888;
    ui_g_Ungroup_NewText->width = 4;
    ui_g_Ungroup_NewText->font_size = 40;
    ui_g_Ungroup_NewText->str_length = 17;
    strcpy(ui_g_Ungroup_NewText->string, "What can i say?  ");


    ui_proc_string_frame(&ui_g_Ungroup_2);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_2, sizeof(ui_g_Ungroup_2));
}

void _ui_update_g_Ungroup_2() {
    ui_g_Ungroup_2.option.operate_type = 2;

    ui_proc_string_frame(&ui_g_Ungroup_2);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_2, sizeof(ui_g_Ungroup_2));
}

void _ui_remove_g_Ungroup_2() {
    ui_g_Ungroup_2.option.operate_type = 3;

    ui_proc_string_frame(&ui_g_Ungroup_2);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_2, sizeof(ui_g_Ungroup_2));
}
ui_string_frame_t ui_g_Ungroup_3;
ui_interface_string_t* ui_g_Ungroup_NewText1 = &(ui_g_Ungroup_3.option);

void _ui_init_g_Ungroup_3() {
    ui_g_Ungroup_3.option.figure_name[0] = 0;
    ui_g_Ungroup_3.option.figure_name[1] = 0;
    ui_g_Ungroup_3.option.figure_name[2] = 7;
    ui_g_Ungroup_3.option.operate_type = 1;

    ui_g_Ungroup_NewText1->figure_type = 7;
    ui_g_Ungroup_NewText1->operate_type = 1;
    ui_g_Ungroup_NewText1->layer = 0;
    ui_g_Ungroup_NewText1->color = 1;
    ui_g_Ungroup_NewText1->start_x = 184;
    ui_g_Ungroup_NewText1->start_y = 787;
    ui_g_Ungroup_NewText1->width = 3;
    ui_g_Ungroup_NewText1->font_size = 25;
    ui_g_Ungroup_NewText1->str_length = 20;
    strcpy(ui_g_Ungroup_NewText1->string, "d\\(  > _ <  )//b ");


    ui_proc_string_frame(&ui_g_Ungroup_3);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_3, sizeof(ui_g_Ungroup_3));
}

void _ui_update_g_Ungroup_3() {
    ui_g_Ungroup_3.option.operate_type = 2;

    ui_proc_string_frame(&ui_g_Ungroup_3);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_3, sizeof(ui_g_Ungroup_3));
}

void _ui_remove_g_Ungroup_3() {
    ui_g_Ungroup_3.option.operate_type = 3;

    ui_proc_string_frame(&ui_g_Ungroup_3);
    SEND_MESSAGE((uint8_t *) &ui_g_Ungroup_3, sizeof(ui_g_Ungroup_3));
}

void ui_init_g_Ungroup() {
    _ui_init_g_Ungroup_0();
    _ui_init_g_Ungroup_1();
    _ui_init_g_Ungroup_2();
    _ui_init_g_Ungroup_3();
}

void ui_update_g_Ungroup() {
    _ui_update_g_Ungroup_0();
    _ui_update_g_Ungroup_1();
    _ui_update_g_Ungroup_2();
    _ui_update_g_Ungroup_3();
}

void ui_remove_g_Ungroup() {
    _ui_remove_g_Ungroup_0();
    _ui_remove_g_Ungroup_1();
    _ui_remove_g_Ungroup_2();
    _ui_remove_g_Ungroup_3();
}

ui_2_frame_t ui_g_UngroupNUM_0;

ui_interface_number_t *ui_g_UngroupNUM_NewNumber1 = (ui_interface_number_t*)&(ui_g_UngroupNUM_0.data[0]);
ui_interface_number_t *ui_g_UngroupNUM_NewFloat1 = (ui_interface_number_t*)&(ui_g_UngroupNUM_0.data[1]);

void _ui_init_g_UngroupNUM_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_UngroupNUM_0.data[i].figure_name[0] = 0;
        ui_g_UngroupNUM_0.data[i].figure_name[1] = 1;
        ui_g_UngroupNUM_0.data[i].figure_name[2] = i + 0;
        ui_g_UngroupNUM_0.data[i].operate_type = 1;
    }
    for (int i = 2; i < 2; i++) {
        ui_g_UngroupNUM_0.data[i].operate_type = 0;
    }

    ui_g_UngroupNUM_NewNumber1->figure_type = 6;
    ui_g_UngroupNUM_NewNumber1->operate_type = 1;
    ui_g_UngroupNUM_NewNumber1->layer = 1;
    ui_g_UngroupNUM_NewNumber1->color = 0;
    ui_g_UngroupNUM_NewNumber1->start_x = 500;
    ui_g_UngroupNUM_NewNumber1->start_y = 700;
    ui_g_UngroupNUM_NewNumber1->width = 2;
    ui_g_UngroupNUM_NewNumber1->font_size = 20;
    ui_g_UngroupNUM_NewNumber1->number = 0;

    ui_g_UngroupNUM_NewFloat1->figure_type = 5;
    ui_g_UngroupNUM_NewFloat1->operate_type = 1;
    ui_g_UngroupNUM_NewFloat1->layer = 1;
    ui_g_UngroupNUM_NewFloat1->color = 0;
    ui_g_UngroupNUM_NewFloat1->start_x = 500;
    ui_g_UngroupNUM_NewFloat1->start_y = 619;
    ui_g_UngroupNUM_NewFloat1->width = 2;
    ui_g_UngroupNUM_NewFloat1->font_size = 20;
    ui_g_UngroupNUM_NewFloat1->number = IMU_Data.YawTotalAngle*1000;


    ui_proc_2_frame(&ui_g_UngroupNUM_0);
    SEND_MESSAGE((uint8_t *) &ui_g_UngroupNUM_0, sizeof(ui_g_UngroupNUM_0));
}

void _ui_update_g_UngroupNUM_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_UngroupNUM_0.data[i].operate_type = 2;
    }

    ui_proc_2_frame(&ui_g_UngroupNUM_0);
    SEND_MESSAGE((uint8_t *) &ui_g_UngroupNUM_0, sizeof(ui_g_UngroupNUM_0));
}

void _ui_remove_g_UngroupNUM_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_UngroupNUM_0.data[i].operate_type = 3;
    }

    ui_proc_2_frame(&ui_g_UngroupNUM_0);
    SEND_MESSAGE((uint8_t *) &ui_g_UngroupNUM_0, sizeof(ui_g_UngroupNUM_0));
}


void ui_init_g_UngroupNUM() {
    _ui_init_g_UngroupNUM_0();
}

void ui_update_g_UngroupNUM() {
    _ui_update_g_UngroupNUM_0();
}

void ui_remove_g_UngroupNUM() {
    _ui_remove_g_UngroupNUM_0();
}

