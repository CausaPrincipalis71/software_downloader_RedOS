#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initAllPackagesVector();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_downloadButton_clicked()
{
    // Switching on download page
    ui->mainStackedWidget->setCurrentWidget(ui->downloadPage);

    // Start logging
    ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tr(" Начинается загрузка"));

    QTimer::singleShot(10, this, [=]()->void{installPackages(DOWNLOAD);});
}

void MainWindow::installPackages(packageInstallOperation operation, int packageUpdate)
{
    // Static variables for vector iterarion
    static int vectorNumber = 0;
    static int packageNumber = 0;

    if (operation == FINISH)
    {
        vectorNumber = 0;
        packageNumber = 0;

        clearAllPackagesVector();
        initAllPackagesVector();
        return;
    }

    //Next step in packages, if packageUpdate set to 1
    packageNumber += packageUpdate;

    while (packageNumber >= allPackagesVector.at(vectorNumber).size())  // If we went to border of vector
    {
        // set packageNumber to 0 and make one step inside allPackagesVector
        packageNumber = 0;
        vectorNumber += 1;

        // If we fone trough all vectors, abort installation
        if(vectorNumber >= allPackagesVector.size())
        {
            return;
        }
    }

    DLPackage * tmpPackage = allPackagesVector.at(vectorNumber).at(packageNumber);

    if (operation == DOWNLOAD)
    {
        // Checking choosed packages and install them
        ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tr(" Проверяется пакет ") + tmpPackage->getName());

        if (tmpPackage->getPackageCheckBoxState() == true)
        {
            // Show information about installing programm
            ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tr(" Пакет ") + tmpPackage->getName() + tr(" отмечен, начинаем загрузку"));
            ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tmpPackage->getDownloadCommand());

            // Start downloading programm and save log to QString;
            tmpPackage->download();
            connect(tmpPackage, SIGNAL(readyRead(DLPackage*)), this, SLOT(onProcessReadyRead(DLPackage*)));
            connect(tmpPackage, SIGNAL(processFinished()), this, SLOT(onProcessFinished()));
        }
        else    // If checkbox isn`t checked
            installPackages(DOWNLOAD, 1);
    }
    else if (operation == INSTALL)
    {
        ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tr(" Начинаем установку "));
        // Install programm, if it`s nescessary (avaiable only for AppImage, RPM packages just skipping). Normal exit code is 0, so here false became true
        if (tmpPackage->install() == 0)
            ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tr(" Пакет ") + tmpPackage->getName() + tr(" загружен и установлен\n\n"));
        else
            ui->installationLog->append(QTime::currentTime().toString("HH:mm:ss") + tr(" Пакет ") + tmpPackage->getName() + tr(" не установлен, произошла ошибка\n\n"));

        // Make next step in the installation
        installPackages(DOWNLOAD, 1);
    }
}

void MainWindow::onProcessReadyRead(DLPackage* package)
{
    ui->installationLog->append(package->getDownloadProcessOutput());
}

void MainWindow::onProcessFinished()
{
    installPackages(INSTALL);
}

void MainWindow::onCheckBoxHover(DLPackage *package)
{
    ui->packageDescription->setText(package->getDescription());
}

void MainWindow::initAllPackagesVector()
{
    // Getting packages and adding their checkbox into layout
    allPackagesVector = createAllPackagesVectors();

    for (auto tmpVector = allPackagesVector.begin(); tmpVector != allPackagesVector.end(); tmpVector++)
    {
        for (int packageNumber = 0; packageNumber < tmpVector->size(); packageNumber++) {
            if(tmpVector->at(packageNumber)->checkInstall() == true)       // If programm is installed
                tmpVector->at(packageNumber)->setPackageCheckBoxDisabled(); // Set checkbox disabled and set tooltip

            connect(tmpVector->at(packageNumber), SIGNAL(mouseHover(DLPackage*)), this, SLOT(onCheckBoxHover(DLPackage*))); // Switch description when hovered on checkbox

            switch (tmpVector->at(packageNumber)->getCategory()) {
                case MATH:
                    ui->mathScrollAreaContents->layout()->addWidget( tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case CHEMISTRY:
                    ui->chemistryScrollAreaContents->layout()->addWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case ASTRONOMY:
                    ui->astronomyScrollAreaContents->layout()->addWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case GEOLOGY:
                    ui->geologyScrollAreaContents->layout()->addWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case ENGENEERING:
                    ui->engeneeringScrollAreaContents->layout()->addWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case CS:
                    ui->csScrollAreaContents->layout()->addWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case OTHER:
                    ui->otherKitsScrollAreaContents->layout()->addWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;
            }
        }

    }
}

void MainWindow::clearAllPackagesVector()
{
    for (auto tmpVector = allPackagesVector.begin(); tmpVector != allPackagesVector.end(); tmpVector++)
    {
        for (int packageNumber = 0; packageNumber < tmpVector->size(); packageNumber++) {

            disconnect(tmpVector->at(packageNumber), SIGNAL(mouseHover(DLPackage*)), this, SLOT(onCheckBoxHover(DLPackage*))); // Remove switching description when hovered on checkbox

            switch (tmpVector->at(packageNumber)->getCategory()) {
                case MATH:
                    ui->mathScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case CHEMISTRY:
                    ui->chemistryScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case ASTRONOMY:
                    ui->astronomyScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case GEOLOGY:
                    ui->geologyScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case ENGENEERING:
                    ui->engeneeringScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case CS:
                    ui->csScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;

                case OTHER:
                    ui->otherKitsScrollAreaContents->layout()->removeWidget(tmpVector->at(packageNumber)->getPackageCheckbox() );
                break;
            }
        }

    }

    allPackagesVector.clear();
}



/* Setting different scientific kits */

void MainWindow::on_mathButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->mathPage);
}


void MainWindow::on_chemistryButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->chemistryPage);
}

void MainWindow::on_astronomyButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->astonomyPage);
}

void MainWindow::on_geologyButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->geologyPage);
}


void MainWindow::on_engeneeringButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->engeneeringPage);
}

void MainWindow::on_csButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->csPage);
}

void MainWindow::on_otherKitButton_clicked()
{
    ui->packagesChoose->setCurrentWidget(ui->otherKitsPage);
}

void MainWindow::on_returnButton_clicked()
{
    ui->mainStackedWidget->setCurrentWidget(ui->preparationPage);

    installPackages(FINISH);
}
