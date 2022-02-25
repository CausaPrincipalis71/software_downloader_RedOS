#ifndef CREATEPACKAGES_H
#define CREATEPACKAGES_H

#include "dlpackage.h"
#include <QVector>

inline QVector<DLPackage*>  createMathPackagesVector()
{
    QVector<DLPackage*> mathPackagesVector;

    DLPackage * infinitex = new DLPackage(AppImage, MATH, "infinitex", "Продвинутый редактор для LaTeX и WYSIWYG с функционалом академического поиска.", "https://clck.ru/bnQGJ");
    DLPackage * matrixCalculator = new DLPackage(AppImage, MATH, "matrix-calculator", "Приложение Python для расчета определителя матрицы, которое работает на Android, Windows и Linux. Создан с использованием GUI-фреймворка kivy/kivymd.", "https://clck.ru/bnSJh");
    DLPackage * octave = new DLPackage(RPM, MATH, "Octave", "GNU Octave — свободная программная система для математических вычислений, использующая совместимый с MATLAB язык высокого уровня.", "octave");
    DLPackage * maxima = new DLPackage(AppImage, MATH, "maxima", "Maxima - одна из старейших систем компьютерной алгебры Linux. Система предназначена для работы с символическими и числовыми выражениями, включая дифференцирование, интегрирование, ряды Тейлора, преобразования Лапласа и дифференциальные уравнения.", "https://clck.ru/cAMw8");

    mathPackagesVector.push_back(infinitex);
    mathPackagesVector.push_back(matrixCalculator);
    mathPackagesVector.push_back(octave);
    mathPackagesVector.push_back(maxima);

    return mathPackagesVector;
}

inline QVector<DLPackage*> createChemistryPackagesVector()
{
    QVector<DLPackage*> chemistryPackagesVector;

    DLPackage * vipster = new DLPackage(AppImage, CHEMISTRY, "vipster", "Vipster — мощный редактор молекулярных структур. Он разработан с нуля для периодических симуляций и поддерживает скрипты на Python!", "https://clck.ru/cAuFb");
    DLPackage * elements = new DLPackage(AppImage, CHEMISTRY, "elements", "Настольное приложение, которое отображает периодическую таблицу Менделеева.", "https://clck.ru/cAxoU");
    DLPackage * libertem = new DLPackage(AppImage, CHEMISTRY, "libertem", "Проект LiberTEM разрабатывает открытую программную платформу для пиксельной/4D сканирующей просвечивающей электронной микроскопии.", "https://clck.ru/cB6A2");
    DLPackage * bioanimation = new DLPackage(AppImage, CHEMISTRY, "bioanimation", "Этот проект предназначен для студентов, чтобы лучше понять уравнение Нернста и Голдьмана.", "https://clck.ru/cU9fE");
    DLPackage * qppcad = new DLPackage(AppImage, CHEMISTRY, "qppcad", "qpp::cad — редактор молекул и кристаллов, написанный на C++", "https://clck.ru/cUb89");

    chemistryPackagesVector.push_back(vipster);
    chemistryPackagesVector.push_back(elements);
    chemistryPackagesVector.push_back(libertem);
    chemistryPackagesVector.push_back(bioanimation);
    chemistryPackagesVector.push_back(qppcad);

    return chemistryPackagesVector;
}

inline QVector<DLPackage*> createAstronomyPackagesVector()
{
    QVector<DLPackage*> astronomyPackagesVector;

    DLPackage * siril = new DLPackage(AppImage, ASTRONOMY, "siril", "Программа предназначения для уменьшения шума и улучшения соотношения сигналов и шумов изображения из нескольких снимков, как это требуется в астрономии.", "https://clck.ru/cUUD7");
    DLPackage * stellarium = new DLPackage(AppImage, ASTRONOMY, "stellarium", "Stellarium — свободный виртуальный планетарий с открытым исходным кодом", "https://clck.ru/cUnyk");
    DLPackage * gpredict = new DLPackage(AppImage, ASTRONOMY, "gpredict", "Gpredict — программа для слежения за спутниками и прогнозирования орбиты в режиме реального времени", "https://clck.ru/cUthr");

    astronomyPackagesVector.push_back(siril);
    astronomyPackagesVector.push_back(stellarium);
    astronomyPackagesVector.push_back(gpredict);

    return astronomyPackagesVector;
}

inline QVector<DLPackage*> createGeographyPackagesVector()
{
    QVector<DLPackage*> geographyPackagesVector;

    DLPackage * mapton = new DLPackage(AppImage, GEOGRAPHY, "mapton", "Mapton — это простое в использовании картографическое приложение", "https://clck.ru/cUmND");
    DLPackage * qgis = new DLPackage(RPM, GEOGRAPHY, "Quantum GIS", "Quantum GIS — свободная кроссплатформенная геоинформационная система, состоящая из настольной и серверной части: QGIS Desktop — настольная ГИС для создания, редактирования, визуализации, анализа и публикации геопространственной информации", "qgis");

    geographyPackagesVector.push_back(mapton);
    geographyPackagesVector.push_back(qgis);

    return geographyPackagesVector;
}

inline QVector<DLPackage*> createEngeneeringPackagesVector()
{
    QVector<DLPackage*> engeneeringPackagesVector;

    DLPackage * simulide = new DLPackage(AppImage, ENGENEERING, "simulide", "SimulIDE — это простой симулятор электронных схем в режиме реального времени, предназначенный для студентов и студентов для обучения и экспериментов с простыми электронными схемами и микроконтроллерами, поддерживающими PIC, AVR и Arduino.", "https://clck.ru/cUQbi");
    DLPackage * kicad = new DLPackage(RPM, ENGENEERING, "Kicad", "KiCad — распространяемый по лицензии GNU GPL программный комплекс класса EDA с открытым исходным кодом, предназначенный для разработки электрических схем и печатных плат.", "kicad");
    DLPackage * opencascade = new DLPackage(RPM, ENGENEERING, "Open Cascade", "Open Cascade Technology — продукт, сочетающий в себе набор библиотек и средств разработки ПО, ориентированного на 3D-моделирование, в особенности систем автоматизированного проектирования.", "opencascade-draw");

    engeneeringPackagesVector.push_back(simulide);
    engeneeringPackagesVector.push_back(kicad);
    engeneeringPackagesVector.push_back(opencascade);

    return engeneeringPackagesVector;
}

inline QVector<DLPackage*> createCsPackagesVector()
{
    QVector<DLPackage*> csPackagesVector;

    DLPackage * evoplex = new DLPackage(AppImage, CS, "evoplex", "Evoplex — это быстрая, надежная и расширяемая платформа для разработки агентных моделей (ABM) и мультиагентных систем (MAS) в сетях. Каждый агент представлен как узел и взаимодействует со своими соседями, как это определено структурой сети.", "https://clck.ru/cUYjU");
    DLPackage * mazesolver = new DLPackage(AppImage, CS, "mazesolver", "Программа для создания и решения лабиринтов при помощи алгоритмов DFS и BFS", "https://clck.ru/cUjNJ");
    DLPackage * codeblocks = new DLPackage(RPM, CS, "Code::Blocks", "Code::Blocks — свободная кроссплатформенная среда разработки.", "codeblocks");
    DLPackage * atom = new DLPackage(AppImage, CS, "atom", "Atom — бесплатный текстовый редактор с открытым исходным кодом для Linux, macOS, Windows с поддержкой плагинов, написанных на JavaScript", "https://clck.ru/cWuoA");

    csPackagesVector.push_back(evoplex);
    csPackagesVector.push_back(mazesolver);
    csPackagesVector.push_back(codeblocks);
    csPackagesVector.push_back(atom);

    return csPackagesVector;
}

inline QVector<DLPackage*> createOtherPackagesVector()
{
    QVector<DLPackage*> otherPackagesVector;

    DLPackage * texmacs = new DLPackage(AppImage, OTHER, "texmacs", "GNU TeXmacs — это бесплатная платформа для научного редактирования, предназначенная для создания красивых технических документов с использованием интерфейса wysiwyg. Он предоставляет унифицированную и удобную среду для редактирования структурированных документов с различными типами контента.", "https://clck.ru/cAPcz");
    DLPackage * calculist = new DLPackage(AppImage, OTHER, "calculist", "Редактор заметок с функцией вычислений", "https://clck.ru/cUHH9");

    otherPackagesVector.append(texmacs);
    otherPackagesVector.append(calculist);

    return otherPackagesVector;
}

inline QVector<QVector<DLPackage*>> createAllPackagesVectors()
{
    QVector<QVector<DLPackage*>> allPackagesVector;

    // Adiing all vectors to one
    allPackagesVector.append(createMathPackagesVector());
    allPackagesVector.append(createChemistryPackagesVector());
    allPackagesVector.append(createAstronomyPackagesVector());
    allPackagesVector.append(createEngeneeringPackagesVector());
    allPackagesVector.append(createGeographyPackagesVector());
    allPackagesVector.append(createCsPackagesVector());
    allPackagesVector.append(createOtherPackagesVector());

    return allPackagesVector;
}


#endif //CREATEPACKAGES_H
