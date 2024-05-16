// Данный пример заливает и стирает весь дисплей с анимацией.    //
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
#include <Wire.h>                                                // Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_Matrix_8x8.
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin(&Wire); // &Wire1, &Wire2 ...                     // Инициируем работу с LED матрицей 8x8, указав ссылку на объект для работы с шиной I2C на которой находится LED матрица (по умолчанию &Wire).
}                                                                //
                                                                 //
void loop(){                                                     //
    disp.fillScr(X8_RIPPLES); delay(1000);                       // Заливаем экран рябью.
    disp.clrScr (X8_RIPPLES); delay(1000);                       // Чистим   экран рябью.
    disp.fillScr(X8_DOWN   ); delay(1000);                       // Заливаем экран сверху-вниз.
    disp.clrScr (X8_DOWN   ); delay(1000);                       // Чистим   экран сверху-вниз.
    disp.fillScr(X8_TOP    ); delay(1000);                       // Заливаем экран снизу-вверх.
    disp.clrScr (X8_TOP    ); delay(1000);                       // Чистим   экран снизу-вверх.
}                                                                //