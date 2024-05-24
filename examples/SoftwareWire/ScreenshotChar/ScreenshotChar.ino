// ДАННЫЙ ПРИМЕР СОХРАНЯЕТ ИЗОБРАЖЕНИЕ ИЗ МАТРИЦЫ В МАССИВ:      //
// Требуется установить библиотеку <iarduino_I2C_Software.h>     // https://iarduino.ru/file/627.html
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
uint8_t myImage[8];                                              // Объявляем массив в который нужно сохранить изображение.
void    myFunc(void);                                            // Объявляем функцию вывода массива myImage в монитор последовательного порта.
                                                                 //
#include <iarduino_I2C_Software.h>                               // Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_I2C_Matrix_8x8.
SoftTwoWire sWire(3,4);                                          // Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                                 //
#include <iarduino_I2C_Matrix_8x8.h>                             // Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp(0x09);                              // Объявляем объект disp для работы с LED матрицей 8x8, указывая её адрес на шине I2C.
                                                                 //
void setup(){                                                    //
    Serial.begin(9600);                                          //
    while(!Serial){;}                                            //
    delay(500);                                                  // Ждём завершение переходных процессов связанных с подачей питания.
    disp.begin(&sWire);                                          // Инициируем работу с LED матрицей 8x8, указав ссылку на объект для работы с шиной I2C на которой находится LED матрица (по умолчанию &Wire).
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