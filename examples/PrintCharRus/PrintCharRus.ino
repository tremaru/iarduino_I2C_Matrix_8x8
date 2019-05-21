// Данный пример выводит символы на Русском языке.               //
                                                                 //
#include <Wire.h>                                                // Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin();                                                // Инициируем работу с LED матрицей 8x8.
    disp.codingDetect("п");                                      // Выполняем автоопределение кодировки скетча.
}                                                                //
                                                                 //
void loop(){                                                     //
    disp.print("П");                                             // Выводим символ 'П'.
    delay(300);                                                  //
    disp.print("р");                                             // Выводим символ 'р'.
    delay(300);                                                  //
    disp.print("и");                                             // Выводим символ 'и'.
    delay(300);                                                  //
    disp.print("в");                                             // Выводим символ 'в'.
    delay(300);                                                  //
    disp.print("е");                                             // Выводим символ 'е'.
    delay(300);                                                  //
    disp.print("\321\202");                                      // Выводим символ 'т', по коду этого символа.
    delay(300);                                                  //
    disp.print(" ");                                             // Выводим символ пробела.
    delay(500);                                                  //
}                                                                //