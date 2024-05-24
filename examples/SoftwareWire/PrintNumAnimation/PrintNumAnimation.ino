// ДАННЫЙ ПРИМЕР ВЫВОДИТ ЦИФРЫ 0-9 С АНИМАЦИЕЙ:                  //
// Требуется установить библиотеку <iarduino_I2C_Software.h>     // https://iarduino.ru/file/627.html
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
int i=9;                                                         // Переменная цифру которой мы будем выводить.
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
    i++;                                                         // Увеличиваем значение переменной i.
    if(i>9){i=0;}                                                // Но не даём значению i выйти за пределы 9.
    disp.fillScr(X8_DOWN);                                       // Заливаем дисплей сверху-вниз.
    disp.print(i, X8_FILLED_DOWN);                               // Выводим значение i на дисплей с анимацией появления из залитого фона сверху-вниз.
    delay(1000);                                                 //
}                                                                //