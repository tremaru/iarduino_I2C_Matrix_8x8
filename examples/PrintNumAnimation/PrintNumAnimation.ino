// Данный пример выводит цифры 0-9 с анимацией.                  //
                                                                 //
int i=9;                                                         // Переменная цифру которой мы будем выводить.
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
    i++;                                                         // Увеличиваем значение переменной i.
    if(i>9){i=0;}                                                // Но не даём значению i выйти за пределы 9.
    disp.fillScr(X8_DOWN);                                       // Заливаем дисплей сверху-вниз.
    disp.print(i, X8_FILLED_DOWN);                               // Выводим значение i на дисплей с анимацией появления из залитого фона сверху-вниз.
    delay(1000);                                                 //
}                                                                //