#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QPainter>
extern "C" {
#include "finalcompiler.tab.h"
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化文件为未保存状态
    isUntitled = true;
    // 初始化文件名为"未命名.txt"
    curFile = tr("未命名.txt");
    // 初始化窗口标题为文件名
    setWindowTitle(curFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
   if (maybeSave()) {
       isUntitled = true;
       curFile = tr("未命名.txt");
       setWindowTitle(curFile);
       ui->textEdit->clear();
       ui->textEdit->setVisible(true);
   }
}

bool MainWindow::maybeSave()
{
    // 如果文档被更改了
    if (ui->textEdit->document()->isModified()) {
    // 自定义一个警告对话框
       QMessageBox box;
       box.setWindowTitle(tr("警告"));
       box.setIcon(QMessageBox::Warning);
       box.setText(curFile + tr(" 尚未保存，是否保存？"));
       QPushButton *yesBtn = box.addButton(tr("是(&Y)"),
                        QMessageBox::YesRole);
       box.addButton(tr("否(&N)"), QMessageBox::NoRole);
       QPushButton *cancelBut = box.addButton(tr("取消"),
                        QMessageBox::RejectRole);
       box.exec();
       if (box.clickedButton() == yesBtn)
            return save();
       else if (box.clickedButton() == cancelBut)
            return false;
   }
   // 如果文档没有被更改，则直接返回true
   return true;
}

bool MainWindow::save()
{
   if (isUntitled) {
       return saveAs();
   } else {
       return saveFile(curFile);
   }
}

bool MainWindow::saveAs()
{
   QString fileName = QFileDialog::getSaveFileName(this,
                                         tr("另存为"),curFile);
   if (fileName.isEmpty()) return false;
   return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
   QFile file(fileName);

   if (!file.open(QFile::WriteOnly | QFile::Text)) {

       // %1和%2分别对应后面arg两个参数，/n起换行的作用
       QMessageBox::warning(this, tr("多文档编辑器"),
                   tr("无法写入文件 %1：/n %2")
                  .arg(fileName).arg(file.errorString()));
       return false;
   }
   QTextStream out(&file);
   // 鼠标指针变为等待状态
   QApplication::setOverrideCursor(Qt::WaitCursor);
   out << ui->textEdit->toPlainText();
   // 鼠标指针恢复原来的状态
   QApplication::restoreOverrideCursor();
   isUntitled = false;
   // 获得文件的标准路径
   curFile = QFileInfo(fileName).canonicalFilePath();
   setWindowTitle(curFile);
   return true;
}

bool MainWindow::loadFile(const QString &fileName, int mode)
{
   QFile file(fileName); // 新建QFile对象
   if (!file.open(QFile::ReadOnly | QFile::Text)) {
       QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
       return false; // 只读方式打开文件，出错则提示，并返回false
   }
   QTextStream in(&file); // 新建文本流对象
   QApplication::setOverrideCursor(Qt::WaitCursor);
   if(mode == 0) {
       // 读取文件的全部文本内容，并添加到编辑器中
       ui->textEdit->setPlainText(in.readAll());      QApplication::restoreOverrideCursor();
       // 设置当前文件
       curFile = QFileInfo(fileName).canonicalFilePath();
       isUntitled = true;
       setWindowTitle(curFile);
   } else if(mode == 1) {
       ui->result->setPlainText(in.readAll());      QApplication::restoreOverrideCursor();
   } else if(mode == 2) {
       ui->code->setPlainText(in.readAll());      QApplication::restoreOverrideCursor();
   } else if(mode == 3) {
       ui->symbaltable->setPlainText(in.readAll());      QApplication::restoreOverrideCursor();
   } else if(mode == 4) {
       ui->errout->setPlainText(in.readAll());      QApplication::restoreOverrideCursor();
   }
   return true;

}

void MainWindow::on_action_N_triggered()
{
    newFile();
}

void MainWindow::on_action_S_triggered()
{
    save();
}

void MainWindow::on_action_O_triggered()
{
    if (maybeSave()) {

        QString fileName = QFileDialog::getOpenFileName(this);

        // 如果文件名不为空，则加载文件
        if (!fileName.isEmpty()) {
             loadFile(fileName, 0);
             ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_action_C_triggered()
{
    if (maybeSave()) {
        ui->textEdit->setVisible(false);
    }
}

void MainWindow::on_action_X_triggered()
{
    // 先执行关闭操作，再退出程序
    // qApp是指向应用程序的全局指针
    on_action_C_triggered();
    qApp->quit();
}

void MainWindow::on_action_R_triggered()
{
    if (maybeSave()) {
        compile(curFile.toLocal8Bit().data());
        QString str1 = "T/编译est";
        const char *c_str2 = str1.toLocal8Bit().data();
        printf("str1: %s\n", c_str2);
        fflush(stdout);
        loadFile("fresult.txt", 1);
        loadFile("fcode.txt", 2);
        loadFile("ftable.txt", 3);
        loadFile("ferrout.txt", 4);
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    painter.drawText(100, 100, "qter.org_yafeilinux");
}

void MainWindow::on_action_C_2_triggered()
{
    if (maybeSave()) {
        compile(curFile.toLocal8Bit().data());
        QString str1 = "T/编译est";
        const char *c_str2 = str1.toLocal8Bit().data();
        printf("str1: %s\n", c_str2);
        fflush(stdout);
        loadFile("fcode.txt", 2);
        loadFile("ftable.txt", 3);
        loadFile("ferrout.txt", 4);
    }
}
