// ДАННЫЙ ПРИМЕР ВЫВОДИТ СТРОКУ ПОШАГОВО ЕЁ СДВИГАЯ:             // 
// Требуется установить библиотеку <iarduino_I2C_Software.h>     // https://iarduino.ru/file/627.html
                                                                 //
// LED Матрица 8x8, красная - i2c (Trema-модуль):                // https://iarduino.ru/shop/Expansion-payments/led-matrica-8x8---i2c-trema-modul.html
// LED Матрица 8x8, зеленая - i2c (Trema-модуль):                // https://iarduino.ru/shop/displays/led-matrica-8x8-zelenaya---i2c-trema-modul.html
// Информация о подключении модулей к шине I2C:                  // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                    // https://wiki.iarduino.ru/page/trema-matrix-led/
                                                                 //
    char ticker[] = "Hello World";                               // Определяем текст для бегущей строки.
    int  i=0;                                                    // Определяем счётчик количества совершённых сдвигов.
    int  j;                                                      // Объявляем переменную для хранения количества пикселей в бегущей строке.
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
    disp.print(ticker);                                          // Загружаем текст бегущей строки. Текст только загрузится в модуль, но не начнёт выводиться!
    disp.scrollPos(0);                                           // Выводим бегущую строку на дисплей в позиции 0 (начало бегущей строки).
    delay(500);                                                  // Ждём 500 мс (задержка на первом символе строки).
    j = disp.getCharWidth()+disp.getCharInterval();              // Определяем ширину одного символа и межсимвольного интеравала бегущей строки (в пикселях).
    j*= (strlen(ticker)-1);                                      // Определяем ширину бегущей строки (в пикселях), умножив рассчитанное ранее значение на количество символов в строке.
}                                                                //
                                                                 //
void loop(){                                                     //
    disp.scrollStep();                                           // Сдвигаем строку на один шаг. (для автосдвига воспользуйтесь функцией autoScroll, а для сдвига в указанную позицию - функцией scrollPos).
    i++;                                                         // Увеличиваем счётчик совершённых сдвигов.
    if( i >= j ){                                                // Если строка прокручена полностью (количество сдвигов равно или превысило количество пикселей в строке), то ...
        i = 0;                                                   // Сбрасываем счётчик совершённых сдвигов.
        delay(1000);                                             // Ждём 1 сек (задержка на последнем символе строки).
        disp.clrScr();                                           // Чистим дисплей.
        delay(1000);                                             // Ждём 1 сек (пауза между прокрутками бегущих строк).
        disp.scrollPos(0);                                       // Выводим бегущую строку на дисплей в позиции 0 (начало бегущей строки).
        delay(1000);                                             // Ждём 1 сек (задержка на первом символе строки).
    }                                                            //
    delay(100);                                                  // Приостанавливаем выполнение кода на 0.1 сек (чем больше задержка, тем медленнее скорость бегущей строки).
}                                                                //