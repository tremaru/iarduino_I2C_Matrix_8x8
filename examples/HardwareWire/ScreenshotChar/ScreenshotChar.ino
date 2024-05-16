// Данный пример сохраняет изображение из матрицы в массив.      //
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
uint8_t myImage[8];                                              // Объявляем массив в который нужно сохранить изображение.
void    myFunc(void);                                            // Объявляем функцию вывода массива myImage в монитор последовательного порта.
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
//  Проходим по всем заглавным буквам Русских символов:          //
    for(int i=128; i<=159; i++){                                 //
//      Выводим очередной символ (с кодом i) в матрицу:          //
        disp.print(char(i));                                     //
//      Получаем изображение из матрицы в массив myImage:        //
        disp.getImage(myImage);                                  //
//      Выводим массив myImage в монитор последовательного порта://
        Serial.print(" ---------------- \r\n"); for(int j=0; j<8; j++){Serial.print("|"); for(int k=7; k>=0; k--){Serial.print(bitRead(myImage[j],k)?"##":"  ");} Serial.print("|\r\n");} Serial.print(" ---------------- \r\n");
    }                                                            //
}                                                                //
                                                                 //
void loop(){                                                     //
}                                                                //