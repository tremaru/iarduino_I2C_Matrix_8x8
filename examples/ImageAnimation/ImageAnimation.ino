// Данный пример выводит и стирает изображение с анимацией.      //
                                                                 // Создаём изображение "смайлик".
byte myImage[8] = { 0b00111100,                                  //                        ####
                    0b01000010,   /* Посмотрите, изображение */  //                       #    #
                    0b10100101,   /* можно увидеть прямо в   */  //                      # #  # #
                    0b10000001,   /* коде!!!                 */  //                      #      #
                    0b10100101,                                  //                      # #  # #
                    0b10011001,                                  //                      #  ##  #
                    0b01000010,                                  //                       #    #
                    0b00111100 };                                //                        ####
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
    disp.fillScr(X8_RIPPLES);                                    // Заливаем экран рябью.
    disp.drawImage(myImage, X8_FILLED_RIPPLES);                  // Выводим на дисплей изображение массива myImage с функцией появления рябью из закрашенного фона.
    delay(1000);                                                 // Ждём 1 секуну.
                                                                 //
    disp.clrScr (X8_RIPPLES);                                    // Чистим экран рябью.
    disp.drawImage(myImage, X8_RIPPLES);                         // Выводим на дисплей изображение массива myImage с функцией появления рябью из пустого фона.
    delay(1000);                                                 // Ждём 1 секуну.
}                                                                //
