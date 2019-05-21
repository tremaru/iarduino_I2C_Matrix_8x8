// Данный пример заливает и стирает весь дисплей.                //
                                                                 //
#include <Wire.h>                                                // Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin();                                                // Инициируем работу с LED матрицей 8x8.
}                                                                //
                                                                 //
void loop(){                                                     //
    disp.fillScr(); delay(1000);                                 // Заливаем экран (включаем  все светодиоды).
    disp.clrScr();  delay(1000);                                 // Чистим   экран (выключаем все светодиоды).
}                                                                //