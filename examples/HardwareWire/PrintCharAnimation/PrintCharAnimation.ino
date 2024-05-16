// Данный пример выводит символы с анимацией до и после слова.   //
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
    disp.print('i', X8_FILLED_TOP);                              // Выводим символ 'i', с анимацией появления снизу-вверх из закрашенного фона.
    delay(300);                                                  //
    disp.print('A');                                             // Выводим символ 'A'.
    delay(300);                                                  //
    disp.print('r');                                             // Выводим символ 'r'.
    delay(300);                                                  //
    disp.print('d');                                             // Выводим символ 'd'.
    delay(300);                                                  //
    disp.print('u');                                             // Выводим символ 'u'.
    delay(300);                                                  //
    disp.print( char(105) );                                     // Выводим символ 'i', по коду этого символа.
    delay(300);                                                  //
    disp.print('n');                                             // Выводим символ 'n'.
    delay(300);                                                  //
    disp.print('o');                                             // Выводим символ 'o'.
    delay(300);                                                  //
    disp.fillScr(X8_TOP);                                        // Заливаем дисплей снизу-вверх.
}                                                                //