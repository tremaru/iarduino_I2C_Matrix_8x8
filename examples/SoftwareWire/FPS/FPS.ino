// ДАННЫЙ ПРИМЕР ПОСТОЯННО МЕНЯЕТ ЧАСТОТУ ОБНОВЛЕНИЯ ЭКРАНА:     // Частоту обновления полезно менять при съёмке дисплея на камеру.
// Требуется установить библиотеку <iarduino_I2C_Software.h>     // https://iarduino.ru/file/627.html
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
uint8_t i=10;                                                    // Определяем переменную для хранения fps - частоты обновления экрана (кадров в секунду).
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
                                                                 // Далее поворачиваем дисплей, значит будут повёрнуты не только имеющиеся, но и вновь выводимые данные.
void loop(){                                                     //
    i-=10; if(i<10){i=90;}                                       // Уменьшаем частоту обновления экрана на 10 кадров в секунду.
    disp.fps(i);                                                 // Применяем новое значение частоты обновления экрана (допускаются значения от 10 до 255).
    disp.print(i/10);                                            // Выводим число: 1 (при 10 fps), 2 (при 20 fps), ..., 9 (при 90 fps).
    disp.invScr();                                               // Инвертируем цвета (теперь число будет темным на светлом фоне).
    delay(1000);                                                 // Ждём 1 секунду, чтоб увидеть разницу на каждом шаге выполнения скетча.
}                                                                // При значениях ниже 5 (50 fps) будет заметно мерцание изображения.