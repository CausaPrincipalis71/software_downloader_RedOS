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

    chemistryPackagesVector.push_back(vipster);
    chemistryPackagesVector.push_back(elements);
    сhemistryPackagesVector.push_back(libertem);

    return chemistryPackagesVector;
}



inline QVector<DLPackage*> createOtherPackagesVector()
{
    QVector<DLPackage*> otherPackagesVector;

    DLPackage * texmacs = new DLPackage(AppImage, OTHER, "texmacs", "GNU TeXmacs — это бесплатная платформа для научного редактирования, предназначенная для создания красивых технических документов с использованием интерфейса wysiwyg. Он предоставляет унифицированную и удобную среду для редактирования структурированных документов с различными типами контента.", "https://clck.ru/cAPcz");

    otherPackagesVector.append(texmacs);

    return otherPackagesVector;
}

inline QVector<QVector<DLPackage*>> createAllPackagesVectors()
{
    QVector<QVector<DLPackage*>> allPackagesVector;

    // Adiing all vectors to one
    allPackagesVector.append(createMathPackagesVector());
    allPackagesVector.append(createOtherPackagesVector());

    return allPackagesVector;
}


#endif //CREATEPACKAGES_H
