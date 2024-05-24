// ДАННЫЙ ПРИМЕР ВЫВОДИТ БЕГУЩУЮ СТРОКУ, МЕНЯЯ НАПРАВЛЕНИЕ СДВИГА//
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
    disp.print("http://iarduino.ru");                            // Загружаем текст "http://iarduino.ru" для бегущей строки.
//  Запускаем бегущую строку:                                    // До этого мы только загрузили текст бегущей строки, но не выводили её!
    disp.autoScroll(250, 500);                                   // Вывести (постоянно прокручивать) бегущую строку со скоростью 250 и паузой между прокрутками в 500 мс.
}                                                                //
                                                                 //
void loop(){                                                     //
    disp.scrollDir(false); delay(10000);                         // Обычное  направление бегущей строки (справа налево)
    disp.scrollDir(true ); delay(10000);                         // Обратное направление бегущей строки (слева направо)
}                                                                //