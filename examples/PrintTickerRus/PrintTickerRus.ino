// Данный пример выводит бегущую строку на Русском языке.        //
                                                                 //
#include <Wire.h>                                                // Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin();                                                // Инициируем работу с LED матрицей 8x8.
    disp.codingDetect("п");                                      // Выполняем автоопределение кодировки скетча.
    disp.print("Unknown coding");                                // Загружаем текст "Unknown coding" для бегущей строки.
    if (disp.getCoding() == X8_TXT_CP866){                       // Если данный скетч использует кодировку CP866, то ...
        disp.print("Данный скетч использует кодировку CP866");   // Меняем текст для бегущей строки.
    }                                                            //
    if (disp.getCoding() == X8_TXT_UTF8){                        // Если данный скетч использует кодировку UTF8, то ...
        disp.print("Данный скетч использует кодировку UTF-8");   // Меняем текст для бегущей строки.
    }                                                            //
    if (disp.getCoding() == X8_TXT_WIN1251){                     // Если данный скетч использует кодировку WIN1251, то ...
        disp.print("Данный скетч использует кодировку WIN1251"); // Меняем текст для бегущей строки.
    }                                                            //
//  Запускаем бегущую строку:                                    // До этого мы только загрузили текст бегущей строки, но не выводили её!
    disp.autoScroll(240);                                        // Вывести (прокрутить) бегущую строку однократно со скоростью 240. Скорость указывается от 0 (стоп), до 255 (макс).
//  disp.autoScroll(240, 1000);                                  // А так, та же бегущая строка будет постоянно прокручиваться, выдерживая паузу между прокрутками в 1 секунду.
}                                                                //
                                                                 //
void loop(){                                                     //
}                                                                //