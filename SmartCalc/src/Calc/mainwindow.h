#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QLabel>//  для клика по окнам
#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTextEdit>
#include <QWidget>
//#include <QMessageBox>
#include <QLabel>
#include <cmath>

#include "credit.h"
#include "deposit.h"
#include "graphwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//написать комментарии
#ifdef __cplusplus

extern "C" {
#endif

#include "../my_smart_calc.h"

#ifdef __cplusplus
}
#endif

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  graphwindow *graph = nullptr;
  Deposit *deposit = nullptr;
  Credit *credit = nullptr;
  bool modeswitchx = true;

 private slots:
  void digits_numbers();
  void pushButton();
  void pushButton_x();
  void pushBUttonTrig();
  void on_pushButton_point_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_p_clicked();
  void onChangeButtonColorClicked(const QString &color,
                                  const QString &color_buttons);
  void on_pushButton_Uminus_clicked();
  void on_pushButton_Uplus_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_graph_clicked();
  void onGraphWindowClosed();
  void onCreditWindowClosed();
  void onDepositWindowClosed();
  void on_pushButton_switch_to_x_toggled(bool checked);
  void on_pushButton_deposit_clicked();
  void on_pushButton_credit_clicked();

 signals:
  void buttonColorChanged(const QString &color, const QString &color_buttons);
  void sendFunctionText(QString text);
};

#endif  // MAINWINDOW_H
