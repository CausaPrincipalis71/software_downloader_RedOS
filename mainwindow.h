#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include "dlpackage.h"
#include "createpackages.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum packageInstallOperation {DOWNLOAD = 0, INSTALL, FINISH};     // What to do with package

private slots:
    // Switching of pages

    void on_mathButton_clicked();

    void on_chemistryButton_clicked();

    void on_astronomyButton_clicked();

    void on_geographyButton_clicked();

    void on_engeneeringButton_clicked();

    void on_csButton_clicked();

    void on_downloadButton_clicked();

    // Installation of packages function
    void installPackages(packageInstallOperation operation, int packageUpdate = 0); // packageUpdate=0 by default

    void onProcessReadyRead(DLPackage * package);

    void onProcessFinished();

    // Function for work with package description
    void onCheckBoxHover(DLPackage * package);

    void on_returnButton_clicked();

    void on_otherKitButton_clicked();

private:
    Ui::MainWindow *ui;

    // Vectors of packages
    QVector<QVector<DLPackage*>> allPackagesVector;

    void initAllPackagesVector();
    void clearAllPackagesVector();
};
#endif // MAINWINDOW_H
