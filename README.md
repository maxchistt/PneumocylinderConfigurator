# PneumocylinderConfigurator

Конфигуратор параметрической модели пневмоцилиндра на базе [C3D Toolkit](https://c3dlabs.com/ru/products/c3d-toolkit/)

![Screenshot](https://i.postimg.cc/s27p5QSB/screenshot-cyl.png)

В решении используется проект статической библиотеки [QtVision](https://github.com/maxchistt/QtVision-Static-Class-Library)

### Сборка проекта

1. Если VS не настроена для работы с Qt, смотрим материал по [ссылке](http://wiki.mpu-cloud.ru/c3d-vision-getting-started)

1. Копируем в папку проекта "C3D" папки "Vision" и "Kernel" из дистрибутива C3DVision версии 2.6.4.6

1. Открываем проект одним из двух способов

   - Основной : Открываем файл проекта "PneumocylinderConfigurator.sln"
   - Альтернативный : Открываем, кликнув по папке решения 'ПКМ -> Открыть с помощью Visual Studio', затем жмем 'Переключиться между решениями и доступными представлениями -> Просмотр целевых объектов CMake'

### Особенности разработки

- Чтобы избежать некорректной работы некоторых функций геометрического ядра, нужно перевести проект в конфигурацию Release

---

Создано в рамках проектной деятельности [Центром САПР-разработки Московского Политеха](https://vk.com/mpu_cloud)
