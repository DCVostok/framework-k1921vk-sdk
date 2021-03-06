/*==============================================================================
 * Заголовочный файл класса HID USB Device.
 * Геймпад, имеющий 5 кнопок.
 *------------------------------------------------------------------------------
 * НИИЭТ, Дмитрий Сериков <lonie@niiet.ru>
 * НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HID_GAMEPAD_H
#define __USB_HID_GAMEPAD_H

/* Includes ------------------------------------------------------------------*/
#include "usb_dev.h"

/* Exported defines ----------------------------------------------------------*/
#define HID_DESCRIPTOR_TYPE 0x21
#define HID_CLASS_SPEC_RELEASE_NUMBER 0x0111

#define HID_REPORT_DESCRIPTOR 0x22

#define EP_DATA_IN 0x81
#define HID_IN_PACKET 4

#define HID_REQ_SET_IDLE 0x0A
#define HIR_REQ_GET_REPORT 0x01

/* Exported types ------------------------------------------------------------*/
typedef struct
{
    union {
        uint8_t byteval;
        struct {
            uint8_t b0 : 1;
            uint8_t b1 : 1;
            uint8_t b2 : 1;
            uint8_t b3 : 1;
            uint8_t b4 : 1;
        } bitval;
    } buttons;
} hid_report_t;

/* Exported variables --------------------------------------------------------*/
extern USBDev_ClassCB_TypeDef USBDEV_HID_cb;

/* Exported functions prototypes ---------------------------------------------*/
uint32_t HID_SendReport(hid_report_t* hid_report);

#endif /* __USB_HID_GAMEPAD_H */
