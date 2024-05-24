// ДАННЫЙ ПРИМЕР ВЫВОДИТ СИМВОЛЫ НА РУССКОМ ЯЗЫКЕ:               //
// Требуется установить библиотеку <iarduino_I2C_Software.h>     // https://iarduino.ru/file/627.html
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
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