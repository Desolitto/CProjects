#include "graphwindow.h"

#include "../my_smart_calc.h"
#include "ui_graphwindow.h"

graphwindow::graphwindow(QWidget* parent)
    : QDialog(parent), ui(new Ui::graphwindow) {
  ui->setupUi(this);
  this->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint |
                       Qt::CustomizeWindowHint);
  ui->widget->setBackground(QBrush(Qt::transparent));
  ui->widget->xAxis->setLabelColor(QColor(255, 255, 255));
  // Изменение цвета цифр на шкале измерений оси X на белый
  ui->widget->xAxis->setTickLabelColor(QColor(255, 255, 255));
  // Изменение цвета подписи оси Y на белый
  ui->widget->yAxis->setLabelColor(QColor(255, 255, 255));
  // Изменение цвета цифр на шкале измерений оси Y на белый
  ui->widget->yAxis->setTickLabelColor(QColor(255, 255, 255));
  connect(ui->pushButton_clear, &QPushButton::clicked, this,
          &graphwindow::on_pushButton_clear_clicked);
}

graphwindow::~graphwindow() { delete ui; }

void graphwindow::on_pushButton_back_clicked() {
  emit graphWindowClosed();
  this->close();
}

bool graphwindow::validateInputs(QStringList& inputValues) {
  QVector<QIntValidator*> validators = {
      new QIntValidator(this), new QIntValidator(this), new QIntValidator(this),
      new QIntValidator(this)};

  bool validInput = true;
  for (int i = 0; i < inputValues.size(); ++i) {
    int pos = 0;
    if (validators[i]->validate(inputValues[i], pos) !=
        QValidator::Acceptable) {
      validInput = false;
      break;
    }
  }

  for (QIntValidator* validator : validators) {
    delete validator;
  }

  return validInput;
}

void graphwindow::on_pushButton_print_graph_clicked() {
  x.clear();
  y.clear();
  xEnd = 0.0;
  QString funcText = receivedFunctionText;
  QString funcTextTemp = funcText;
  int status = 0;
  h = 0.01;
  double dmin, dmax, emin, emax;
  initializeValidatorsAndGetRanges(dmin, dmax, emin, emax);

  xBegin = dmin;
  xEnd = dmax;
  X = xBegin;
  for (X = xBegin; X <= xEnd; X += h) {
    x.push_back(X);
    QString xStr = QString::number(X, 'd');
    QByteArray xByteArray = xStr.toStdString().c_str();
    char* xChar = xByteArray.data();
    status =
        full_calcuation((char*)funcText.toStdString().c_str(), &result, xChar);
    if (status == 0) {
      y.push_back(result);
    } else {
      // Если функция не может быть вычислена, удаляем последний добавленный x
      if (!x.empty()) {
        x.pop_back();  //Используем pop_back для удаления последнего элемента из
                       //вектора x
      }
    }
    funcTextTemp = funcText;
  }
  if (status > 1) {
    QMessageBox::critical(this, "Ошибка ввода", "INCORRECT_INPUT");
  } else {
    ui->widget->addGraph();
    ui->widget->graph(0)->data()->clear();
    for (int i = 0; i < x.size(); i++) {
      ui->widget->graph(0)->addData(x[i], y[i]);
    }
    QPen rosePen(Qt::magenta);
    rosePen.setWidth(2);
    ui->widget->graph(0)->setPen(rosePen);
    ui->widget->replot();
  }
}

void graphwindow::initializeValidatorsAndGetRanges(double& dmin, double& dmax,
                                                   double& emin, double& emax) {
  QDoubleValidator* validator = new QDoubleValidator(this);
  ui->dmin_1->setValidator(validator);
  ui->dmax_1->setValidator(validator);
  ui->emin_1->setValidator(validator);
  ui->emax_1->setValidator(validator);

  dmin = ui->dmin_1->text().replace(',', '.').toDouble();
  dmax = ui->dmax_1->text().replace(',', '.').toDouble();
  emin = ui->emin_1->text().replace(',', '.').toDouble();
  emax = ui->emax_1->text().replace(',', '.').toDouble();

  ui->widget->xAxis->setRange(dmin, dmax);
  ui->widget->yAxis->setRange(emin, emax);
}

void graphwindow::onFunctionTextReceived(QString text) {
  receivedFunctionText = text;
  ui->label_temp->setText(text);
}

void graphwindow::on_pushButton_clear_clicked() {
  ui->widget->addGraph();
  if ((ui->widget->graph(0))) {
    ui->widget->graph(0)->data()->clear();
    ui->widget->replot();
  }
}
