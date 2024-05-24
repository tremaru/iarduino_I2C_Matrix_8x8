// ДАННЫЙ ПРИМЕР ВЫВОДИТ И СТИРАЕТ ИЗОБРАЖЕНИЕ С АНИМАЦИЕЙ:      //
// Требуется установить библиотеку <iarduino_I2C_Software.h>     // https://iarduino.ru/file/627.html
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
                                                                 // Создаём изображение "смайлик".
byte myImage[8] = { 0b00111100,                                  //                        ####
                    0b01000010,   /* Посмотрите, изображение */  //                       #    #
                    0b10100101,   /* можно увидеть прямо в   */  //                      # #  # #
                    0b10000001,   /* коде!!!                 */  //                      #      #
                    0b10100101,                                  //                      # #  # #
                    0b10011001,                                  //                      #  ##  #
                    0b01000010,                                  //                       #    #
                    0b00111100 };                                //                        ####
                                                                 //
#include <iarduino_I2C_Software.h>                               // Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_I2C_Matrix_8x8.
SoftTwoWire sWire(3,4);                                          // Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                                 //
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin(&sWire);                                          // Инициируем работу с LED матрицей 8x8, указав ссылку на объект для работы с шиной I2C на которой находится LED матрица (по умолчанию &Wire).
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
