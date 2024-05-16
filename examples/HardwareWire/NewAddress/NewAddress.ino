// ПРИМЕР СМЕНЫ АДРЕСА МОДУЛЯ:                                   // * Строки со звёздочкой являются необязательными.
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
// Данный скетч демонстрирует не только возможность смены адреса //
// на указанный в переменной newAddress, но и обнаружение,       //
// и вывод текущего адреса модуля на шине I2C.                   //
                                                                 //
// Библиотека <iarduino_I2C_Matrix_8x8.h> предназначена для      //
// работы с LED матрицами 8x8 и меняет только их адреса.         //
// Но, в разделе Файл/Примеры/.../findSortDevices                //
// находятся примеры смены и сортировки адресов                  //
// любых модулей iarduino серии Flash I2C.                       //
                                                                 //
uint8_t newAddress = 0x10;                                       //   Назначаемый модулю адрес.
                                                                 //
#include <Wire.h>                                                //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_Matrix_8x8.
#include <iarduino_I2C_Matrix_8x8.h>                             //   Подключаем библиотеку для работы с LED матрицей 8x8.
iarduino_I2C_Matrix_8x8 disp;                                    //   Объявляем объект disp для работы с функциями и методами библиотеки iarduino_I2C_Matrix_8x8.
                                                                 //   Если при объявлении объекта указать адрес, например, disp(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
void setup(){                                                    //
    delay(500);                                                  // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                                          //   Инициируем передачу данных по шине UART на скорости 9600 бит/сек.
    while(!Serial){;}                                            // * Ждём завершения инициализации шины UART.
    if( disp.begin(&Wire) ){                                     //   Инициируем работу с LED матрицей 8x8, указав ссылку на объект для работы с шиной I2C на которой находится матрица (Wire, Wire1, Wire2 ...).
        Serial.print("На шине I2C найден модуль с адресом 0x");  //
        Serial.print( disp.getAddress(), HEX );                  //   Выводим текущий адрес модуля.
        Serial.print(" который является LED матрицей 8x8\r\n");  //
        if( disp.changeAddress(newAddress) ){                    //   Меняем адрес модуля на newAddress.
            Serial.print("Адрес модуля изменён на 0x");          //
            Serial.println( disp.getAddress(), HEX );            //   Выводим текущий адрес модуля.
        }else{                                                   //
            Serial.println("Адрес модуля изменить не удалось!"); //
        }                                                        //
    }else{                                                       //
        Serial.println("Модуль LED матрица 8x8 не найден!");     //
    }                                                            //
}                                                                //
                                                                 //
void loop(){                                                     //
}                                                                //
