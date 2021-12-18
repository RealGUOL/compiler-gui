#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void newFile();   // 新建操作
    bool maybeSave(); // 判断是否需要保存
    bool save();      // 保存操作
    bool saveAs();    // 另存为操作
    bool saveFile(const QString &fileName); // 保存文件
    bool loadFile(const QString &fileName, int mode); // 加载文件

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_action_N_triggered();

    void on_action_S_triggered();

    void on_action_O_triggered();

    void on_action_C_triggered();

    void on_action_X_triggered();

    void on_action_R_triggered();

    void on_action_C_2_triggered();

private:
    Ui::MainWindow *ui;
    // 为真表示文件没有保存过，为假表示文件已经被保存过了
    bool isUntitled;
    // 保存当前文件的路径
    QString curFile;
};

#endif // MAINWINDOW_H
