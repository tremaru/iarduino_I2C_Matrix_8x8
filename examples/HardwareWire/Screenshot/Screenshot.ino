// Данный пример сохраняет изображение из матрицы в массив.      //
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
uint8_t myImage[8];                                              // Объявляем массив в который нужно сохранить изображение.
                                                                 //
#include <Wire.h>                                                // Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_Matrix_8x8.
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    Serial.begin(9600);                                          //
    while(!Serial){;}                                            //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin(&Wire); // &Wire1, &Wire2 ...                     // Инициируем работу с LED матрицей 8x8, указав ссылку на объект для работы с шиной I2C на которой находится LED матрица (по умолчанию &Wire).
    disp.print("Hello World");                                   // Загружаем текст для бегущей строки (но не выводим её).
    disp.autoScroll(250, 500);                                   // Выводим текст бегущей строки. Указываем постоянно прокручивать бегущую строку со скоростью 250 и паузой между прокрутками в 500 мс.
}                                                                //
                                                                 //
void loop(){                                                                  //
//  Каждые 5 секунд копируем изображение из матрицы в массив myImage:         //
    delay(5000);                                                              // Ждём 5 секунд.
    disp.getImage(myImage);                                                   // Получаем изображение из матрицы в массив myImage.
//  Выводим полученное изображение в монитор последовательного порта:         //
                             Serial.print(" ---------------- \r\n"         ); //
    for(int i=0; i<8; i++) { Serial.print("|"                              ); //
    for(int j=7; j>=0; j--){ Serial.print( bitRead(myImage[i],j)?"##":"  " ); //
    }                        Serial.print("|\r\n"                          ); //
    }                        Serial.print(" ---------------- \r\n"         ); //
}                                                                             //