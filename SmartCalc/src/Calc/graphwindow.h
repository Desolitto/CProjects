#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QTextEdit>
#include <QValidator>

#ifdef __cplusplus

extern "C" {
#endif

#include "../my_smart_calc.h"

#ifdef __cplusplus
}
#endif

namespace Ui {
class graphwindow;
}

class graphwindow : public QDialog {
  Q_OBJECT

 public:
  explicit graphwindow(QWidget* parent = nullptr);
  ~graphwindow();
 public slots:
  void onFunctionTextReceived(QString text);

 private slots:
  void on_pushButton_back_clicked();
  void on_pushButton_print_graph_clicked();
  bool validateInputs(QStringList& inputValues);
  void on_pushButton_clear_clicked();
  void initializeValidatorsAndGetRanges(double& dmin, double& dmax,
                                        double& emin, double& emax);

 private:
  Ui::graphwindow* ui;
  QString receivedFunctionText;
  ////
  double xBegin, xEnd, h, X, result = 0.0;
  int N;

  QVector<double> x, y;

  ////
 signals:
  void graphWindowClosed();
  void sendLabelText(const QString& text);
};

#endif  // GRAPHWINDOW_H
