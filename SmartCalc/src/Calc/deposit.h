#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>
#include <QMessageBox>
//#include <iostream> // Добавьте эту строку в начало вашего файла, если она еще
//не включена

//написать комментарии
#ifdef __cplusplus

extern "C" {
#endif

#include "../my_smart_calc.h"

#ifdef __cplusplus
}
#endif

struct Operation {
  QString operationType;
  int term_eng;
  int monthNumber;
  double amount;
};

namespace Ui {
class Deposit;
}

class Deposit : public QDialog {
  Q_OBJECT

 public:
  explicit Deposit(QWidget* parent = nullptr);

  ~Deposit();

 private slots:
  void on_pushButton_back_clicked();
  void on_comboBox_capitalization_currentIndexChanged(int index);
  void on_pushButton_add_clicked();
  void on_pushButton_with_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_calc_clicked();
  void addRowToTable(const QString& operationType);
  void readRowFromTable(int row_cnt, std::vector<Operation>& operations);
  void onTermChanged(int index);

 private:
  Ui::Deposit* ui;
  // Создание экземпляра структуры
  deposit_calc_struct deposit;

 signals:
  void depositWindowClosed();
};

#endif  // DEPOSIT_H
