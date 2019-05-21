// Данный пример выводит бегущую строку.                         //
                                                                 //
#include <Wire.h>                                                // Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin();                                                // Инициируем работу с LED матрицей 8x8.
    disp.print("http://iarduino.ru");                            // Загружаем текст "http://iarduino.ru" для бегущей строки.
//  Запускаем бегущую строку:                                    // До этого мы только загрузили текст бегущей строки, но не выводили её!
    disp.autoScroll(240);                                        // Вывести (прокрутить) бегущую строку однократно со скоростью 240. Скорость указывается от 0 (стоп), до 255 (макс).
//  disp.autoScroll(240, 2000);                                  // А так, та же бегущая строка будет постоянно прокручиваться, выдерживая паузу между прокрутками в 2 секунды.
}                                                                //
                                                                 //
void loop(){                                                     //
}                                                                //