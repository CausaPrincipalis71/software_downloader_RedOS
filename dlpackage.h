#ifndef DLPACKAGE_H
#define DLPACKAGE_H

#include <QString>
#include <QCheckBox>
#include <QProcess>
#include "qhovercheckbox.h"

enum typeOfPackage { RPM = 0, AppImage };
enum categoryOfPackage { MATH = 0, HYDROLOGY, ASTRONOMY, GEOLOGY, ENGENEERING, CS };


class DLPackage : public QObject
{

    Q_OBJECT
public:
    DLPackage(const typeOfPackage type, const categoryOfPackage category, const QString &name, const QString &description, const QString &link, QObject* parent = 0);
    ~DLPackage();

    // Actions
    void download();
    bool install();
    bool checkInstall();

    // Wotk with checkBox
    void setPackageCheckBoxDisabled();

    // Get functions
    bool getPackageCheckBoxState();

    QCheckBox *getPackageCheckbox() const;

    QString getName() const;

    QString getDownloadCommand() const;

    QString getDownloadProcessOutput() const;

    typeOfPackage getType() const;

    categoryOfPackage getCategory() const;

    QString getDescription() const;

signals:
    void readyRead(DLPackage*);       // For internal connections
    void processFinished();

    void mouseHover(DLPackage*);

private slots:
    void onReadyRead();    // For work with process inside class
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

    void onMouseHover();

private:
    // Parameters of package
    typeOfPackage m_type;           // RPM or AppImage package
    categoryOfPackage m_category;   // In whick category you may find this package
    QString m_link;                 // Link to the package in the web for AppImage or name of RPM in repository
    QString m_name;                 // Displayed name of the package
    QString m_description;          // Displayed description

    // Package widget
    QCheckBox *packageCheckbox;

    // Download process and it`s parameters
    QProcess * downloadProcess;
    QString m_downloadProgramm;
    QStringList m_downloadArguments;

    // Install process (chmod for appimage, RPM is ignored)
    QProcess installProcess;
    QString m_installProgramm;
    QStringList m_installArguments;

    // Check install process
    QProcess checkInstallProcess;
    QString m_checkInstallProgramm;
    QStringList m_checkInstallArguments;

};

#endif // DLPACKAGE_H
