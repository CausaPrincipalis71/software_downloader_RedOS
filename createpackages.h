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

    mathPackagesVector.push_back(infinitex);
    mathPackagesVector.push_back(matrixCalculator);
    mathPackagesVector.push_back(octave);

    return mathPackagesVector;
}

inline QVector<QVector<DLPackage*>> createAllPackagesVectors()
{
    QVector<QVector<DLPackage*>> allPackagesVector;

    // Adiing all vectors to one
    allPackagesVector.append(createMathPackagesVector());

    return allPackagesVector;
}


#endif //CREATEPACKAGES_H
