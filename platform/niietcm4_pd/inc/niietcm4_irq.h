/**
  ******************************************************************************
  * @file    niietcm4_irq.h
  *
  * @brief   Файл содержит все прототипы функций для назначения обработчиков
  *          прерываний во время выполнения программы
  *
  * @author  Виктор Коробковский, vitkorob@gmail.com
  *
  *          НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  *
  * @date    03.08.2016
  *
  ******************************************************************************
  * @attention
  *
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
  * <h2><center>&copy; 2016 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_IRQ_H
#define __NIIETCM4_IRQ_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Misc
  * @{
  */

/** @addtogroup IRQ
  * @{
  */

 /** @defgroup IRQ_Exported_Macros Макросы
   * @{
   */

 /**
   * @brief Получение системного порядкового номера прерывания, с учетом исключений
   */

 #define IRQ_NUM(IRQ)  ((int32_t)IRQ + 16)

/**
  * @}
  */

/** @defgroup IRQ_Exported_Constants Константы
  * @{
  */

#if defined (K1921VK01T)
    #define IRQ_TOTAL  150
#endif

/**
  * @brief Проверка значения номера прерывания в допустимый диапазон.
  */

#define IS_IRQ_NUM(IRQn) (IRQ_NUM(IRQn) < IRQ_TOTAL)

/**
  * @}
  */

/** @defgroup IRQ_Exported_Functions Функции
  * @{
  */

void IRQ_HandlerInit(IRQn_Type IRQn, void (*pfnHandler)(void));
void IRQ_HandlerDeInit(IRQn_Type IRQn);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __NIIETCM4_IRQ_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
