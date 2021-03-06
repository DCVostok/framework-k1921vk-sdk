## Описание

*PLIB028 (Peripheral Library for K1921VK028)* - это библиотека периферии на языке C, предназначеная для
ускорения и упрощения работы со внутренними периферийными устройствами микроконтроллера К1921ВК028 производства АО "НИИЭТ".
Библиотека является низкоуровневой и требует понимания функциональных особенностей периферии.

Ключевые особенности:

- наличие функций для инициализации основных возможностей периферии согласно параметрам, собранным в структуры
- наличие функций для заполнения структур значениями по умолчанию
- наличие функций для деинициализации периферии
- наличие компактных inline функций, осуществляющих прямой доступ к регистрам
- минимальное количество связей между модулями внутри бибилотеки
- полностью покрывает возможности использования периферии

Поддерживаемая периферия:

- ADC
- BFLASH
- DMA
- ECAP
- ETMR
- EXTMEM
- GPIO
- I2C
- MFLASH
- OWI
- PMU
- PWM
- RCU
- RTC
- SDFM
- SPI
- TMR
- TUART
- UART
- WDT

## Принципы наименования функций

*{PERIPH}* - блок периферии: GPIO, UART, SPI и т.д.
*{_SUBMODULE}* (опционально) - подмодуль внутри периферии, который можно выделить в отдельную структурную единицу: ADC*{_SEQ}*, PWM*{_HD}* и т.д.
*{ITEM}* - объект или регистр внутри блока
*{FUNC}* (опционально) - периферийная функция, если опущена - то действие относится к блоку в целом

**Инциализация, деинициализация**

|  Шаблон                             | Пример            | Описание                               |
|:------------------------------------|:------------------|:---------------------------------------|
| *{PERIPH}{_SUBMODULE}*_Init()       | UART_Init()       | Инциализация периферии через структуру |
| *{PERIPH}{_SUBMODULE}*_DeInit()     | UART_DeInit()     | Возврат к исходному состоянию          |
| *{PERIPH}{_SUBMODULE}*_StructInit() | UART_StructInit() | Первичная инициализация структуры      |

** Контроль значений, ввод-вывод**

|  Шаблон                                 | Пример             | Описание                                |
|:----------------------------------------|:-------------------|:----------------------------------------|
| *{PERIPH}{_SUBMODULE}*_Set*{ITEM}*()    | TMR_SetCounter()   | Установка значения                      |
| *{PERIPH}{_SUBMODULE}*_Get*{ITEM}*()    | TMR_GetCounter()   | Получение значения                      |
| *{PERIPH}{_SUBMODULE}*_Read*{ITEM}*()   | GPIO_ReadPort()    | Чтение значения                         |
| *{PERIPH}{_SUBMODULE}*_Write*{ITEM}*()  | UART_WriteData()   | Запись значения                         |
| *{PERIPH}{_SUBMODULE}*_Toggle*{ITEM}*() | GPIO_ToggleBits()  | Переключение значения на противопложное |
| *{PERIPH}{_SUBMODULE}*_Erase*{ITEM}*()  | MFLASH_ErasePage() | Очистка значения                        |

** Команды и конфигурация **

|  Шаблон                                 | Пример               | Описание                                         |
|:----------------------------------------|:---------------------|:-------------------------------------------------|
| *{PERIPH}{_SUBMODULE}*_*{FUNC}*Cmd()    | GPIO_AltFuncCmd()    | Выполнение операции, обычно включение/выключение |
| *{PERIPH}{_SUBMODULE}*_*{FUNC}*Config() | TMR_ExtInputConfig() | Конфигурация функциональной возможности          |

** Флаги и статусы **

|  Шаблон                                      | Пример               | Описание                  |
|:---------------------------------------------|:---------------------|:--------------------------|
| *{PERIPH}{_SUBMODULE}*_*{FUNC}*Status()      | RCU_PLL_LockStatus() | Чтение флага или статуса  |
| *{PERIPH}{_SUBMODULE}*_*{FUNC}*StatusClear() | RCU_RstStatusClear() | Сброс флагов или статусов |

** Прерывания **

|  Шаблон                                        | Пример              | Описание                                   |
|:-----------------------------------------------|:--------------------|:-------------------------------------------|
| *{PERIPH}{_SUBMODULE}*_IT*{FUNC}*Cmd()         | GPIO_ITCmd()        | Включение/выключение прерываний            |
| *{PERIPH}{_SUBMODULE}*_IT*{FUNC}*Config()      | GPIO_ITTypeConfig() | Настройка особенности генерации прерываний |
| *{PERIPH}{_SUBMODULE}*_IT*{FUNC}*Status()      | TMR_ITStatus()      | Чтение флага прерывания                    |
| *{PERIPH}{_SUBMODULE}*_IT*{FUNC}*StatusClear() | TMR_ITStatusClear() | Сброс флагов прерываний                    |
