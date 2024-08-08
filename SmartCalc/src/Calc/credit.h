#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <QMessageBox>
//#include "../modules/my_finance.h"
//#include <QMessageBox>

//написать комментарии
#ifdef __cplusplus

extern "C" {
#endif

#include "../my_smart_calc.h"

#ifdef __cplusplus
}
#endif

struct LabelInfo {
  QLabel* label;
  QPoint originalPos;
  QSize originalSize;
};

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT
  std::vector<LabelInfo>
      labelsInfo;  // Статический вектор для хранения информации о лейблах
  std::vector<QLabel*>
      dynamicLabels;  // Статический вектор для хранения созданных лейблов
 public:
  explicit Credit(QWidget* parent = nullptr);
  void initializeLabelsInfoAndResetFirstClick();
  ~Credit();

 private slots:
  void on_pushButton_back_clicked();
  void on_Calculate_Credit_clicked();
  void calculateAnnuityPayment(double loan, double rate, int term,
                               double& total_loan,
                               double& interest_rate_payment);
  void calculateDifferentialPayment(double loan, double rate, int term,
                                    double& total_loan,
                                    double& interest_rate_payment,
                                    QLabel* newLabel);
  void createDifferentialPaymentLabels(QLabel*& newLabelL, QLabel*& newLabel);
  void on_Clear_Credit_clicked();

 private:
  Ui::Credit* ui;

 signals:
  void creditWindowClosed();
};

#endif  // CREDIT_H
