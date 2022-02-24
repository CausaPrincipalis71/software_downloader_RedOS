#include "dlpackage.h"

DLPackage::DLPackage(const typeOfPackage type, const categoryOfPackage category, const QString &name, const QString &description, const QString &link, QObject* parent)
{
    // Setting parameters
    this->m_type = type;
    this->m_category = category;
    this->m_link = link;
    this->m_name = name;
    this->m_description = description;

    // Prepare download commands
    if (this->m_type == AppImage)
    {
        // Adding parameters for download appimage from web
        this->m_downloadProgramm = "wget";
        this->m_downloadArguments << "-O" << "/usr/bin/" + m_name << m_link;

        // Install proccess is setting appimage as executable for every user
        installProcess.setProcessChannelMode(QProcess::MergedChannels); //Required for data display
        this->m_installProgramm = "chmod";
        this->m_installArguments << "777" << "/usr/bin/" + m_name;

        // Check install with bash
        this->m_checkInstallProgramm = "test";
        this->m_checkInstallArguments << "-f" << "/usr/bin/" + m_name;
    }
    else if (this->m_type == RPM)
    {
        // Adding parameters for download and install rpm from repo
        this->m_downloadProgramm = "dnf";
        this->m_downloadArguments << "install" << "-y" << m_link;

        // Check install with RPM
        this->m_checkInstallProgramm = "rpm";
        this->m_checkInstallArguments << "-q" << m_link;
    }

    // Create checkbox
    packageCheckbox = new QHoverCheckBox(this->m_name);
    connect(packageCheckbox, SIGNAL(mouseHover()), this, SLOT(onMouseHover()));
}

DLPackage::~DLPackage()
{

}

void DLPackage::download()
{
    // Creating download process
    downloadProcess = new QProcess();
    downloadProcess->setProcessChannelMode(QProcess::MergedChannels);   //Required for data display

    // Starting download process, pause the programm, while download isn`t over
    downloadProcess->start(m_downloadProgramm, m_downloadArguments);

    if (!downloadProcess->waitForStarted())
        return;

    connect(downloadProcess, &QProcess::readyRead, this, &DLPackage::onReadyRead);
    connect(downloadProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinished(int, QProcess::ExitStatus)));

    return;
}

bool DLPackage::install()
{
    if(m_type == AppImage)
    {
        installProcess.start(m_installProgramm, m_installArguments);
        installProcess.waitForFinished();
        return installProcess.exitCode();
    }
    else return false;  // Normal exit code - 0
}

bool DLPackage::checkInstall()
{
    checkInstallProcess.start(m_checkInstallProgramm, m_checkInstallArguments);
    checkInstallProcess.waitForFinished();
    return checkInstallProcess.exitCode() == 0; // Normal exit code - 0
}

void DLPackage::setPackageCheckBoxDisabled()
{
    packageCheckbox->setCheckable(false);
    packageCheckbox->setStyleSheet("color: rgb(158, 155, 155);");
    packageCheckbox->setToolTip(tr("Программа уже установлена"));
    disconnect(packageCheckbox, SIGNAL(mouseHover()), this, SLOT(onMouseHover()));
}

void DLPackage::onReadyRead()
{
    emit readyRead(this);
}

void DLPackage::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitCode)
    Q_UNUSED(exitStatus)
    delete downloadProcess;
    emit processFinished();
}

void DLPackage::onMouseHover()
{
    emit mouseHover(this);
}

QString DLPackage::getDescription() const
{
    return m_description;
}

categoryOfPackage DLPackage::getCategory() const
{
    return m_category;
}

typeOfPackage DLPackage::getType() const
{
    return m_type;
}

bool DLPackage::getPackageCheckBoxState()
{
    return this->packageCheckbox->isChecked();
}

QCheckBox *DLPackage::getPackageCheckbox() const
{
    return packageCheckbox;
}

QString DLPackage::getName() const
{
    return m_name;
}

QString DLPackage::getDownloadCommand() const
{
    // parsing string list
    QString downloadArguments;

    for(int i = 0; i < m_downloadArguments.size(); i++)
        downloadArguments += " " + m_downloadArguments.at(i);

    return " " + m_downloadProgramm + downloadArguments;
}

QString DLPackage::getDownloadProcessOutput() const
{
    return downloadProcess->readAll();
}

