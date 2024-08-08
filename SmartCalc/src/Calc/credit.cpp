#include "credit.h"

#include "../my_smart_calc.h"
#include "ui_credit.h"

Credit::Credit(QWidget* parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
  this->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint |
                       Qt::CustomizeWindowHint);
  QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1e15, 2);
  ui->DepositAmount_input->setValidator(doubleValidator);
  ui->InterestRate_input->setValidator(doubleValidator);
  QComboBox* term = ui->Term_comboBox;
  term->addItem("1 month", QVariant(1));
  term->addItem("3 months", QVariant(3));
  term->addItem("6 months", QVariant(6));
  term->addItem("9 months", QVariant(9));
  term->addItem("1 year", QVariant(12));
  term->addItem("1.5 years", QVariant(18));
  term->addItem("2 years", QVariant(24));
  term->addItem("3 years", QVariant(36));
  term->addItem("4 years", QVariant(48));
  term->addItem("5 years", QVariant(60));
  term->addItem("6 years", QVariant(72));
  term->addItem("7 years", QVariant(84));
  term->addItem("10 years", QVariant(120));
  term->addItem("15 years", QVariant(180));
  term->addItem("20 years", QVariant(240));
  term->addItem("25 years", QVariant(300));
  term->addItem("30 years", QVariant(360));
  term->addItem("50 years", QVariant(600));

  QComboBox* type = ui->Type_comboBox;
  type->addItem("Annoitent", QVariant("1"));
  type->addItem("Differential", QVariant("0"));
}

Credit::~Credit() { delete ui; }

void Credit::on_pushButton_back_clicked() {
  emit creditWindowClosed();
  this->close();
}

void Credit::on_Clear_Credit_clicked() {
  ui->DepositAmount_input->clear();
  ui->InterestRate_input->clear();
  ui->Term_comboBox->setCurrentIndex(0);
  ui->Type_comboBox->setCurrentIndex(0);
}

/////////////////////////////////////////
///

void Credit::calculateAnnuityPayment(double loan, double rate, int term,
                                     double& total_loan,
                                     double& interest_rate_payment) {
  double month_payment = 0.0;
  if (!isnan(loan) && !isnan(rate) && loan > 0 && rate > 0) {
    my_credit_calc_ann(loan, term, rate, &month_payment, &total_loan,
                        &interest_rate_payment);
    ui->label_m_payment->setText(QString::number(month_payment, 'f', 2));
    ui->label_overpayment->setText(
        QString::number(interest_rate_payment, 'f', 2));
    ui->label_payout->setText(QString::number(total_loan, 'f', 2));
  } else {
    QMessageBox::critical(this, "Ошибка ввода", "INCORRECT_INPUT");
  }
}

void Credit::calculateDifferentialPayment(double loan, double rate, int term,
                                          double& total_loan,
                                          double& interest_rate_payment,
                                          QLabel* newLabel) {
  double month_payment_min, month_payment_max = 0.0;
  if (!isnan(loan) && !isnan(rate) && loan > 0 && rate > 0) {
    my_credit_calc_dif(loan, term, rate, &total_loan, &interest_rate_payment,
                        &month_payment_min, &month_payment_max);
    ui->label_m_payment->setText(QString::number(month_payment_max, 'f', 2));
    newLabel->setText(QString::number(month_payment_min, 'f', 2));
    ui->label_overpayment->setText(
        QString::number(interest_rate_payment, 'f', 2));
    ui->label_payout->setText(QString::number(total_loan, 'f', 2));
  } else {
    QMessageBox::critical(this, "Ошибка ввода", "INCORRECT_INPUT");
  }
}
/*
 * в условии повтороного нажатия на кнопку при депоза
Обратите внимание на использование static для newLabelL и newLabel.
Это гарантирует, что они инициализируются один раз и сохраняют свое состояние
между вызовами функции. Это позволяет обновлять текст newLabel при каждом
нажатии кнопки, если входные данные корректны.
*/
void Credit::on_Calculate_Credit_clicked() {
  int type = ui->Type_comboBox->currentData().toInt();
  double loan = ui->DepositAmount_input->text().replace(',', '.').toDouble();
  double rate = ui->InterestRate_input->text().replace(',', '.').toDouble();
  int term = ui->Term_comboBox->currentData().toInt();
  double total_loan, interest_rate_payment = 0.0;

  static bool isDifferentialPayment =
      false;  // Статическая переменная для отслеживания, был ли уже выбран
              // дифференцированный тип платежа
  static bool isFirstClick = true;  // Статическая переменная для отслеживания,
                                    // был ли уже выполнен первый клик
  if (isFirstClick) {
    initializeLabelsInfoAndResetFirstClick();
    isFirstClick =
        false;  // Сбрасываем флаг, так как первый клик уже был обработан
  }
  // Удаляем созданные лейблы при переключении на аннуитетный тип платежа
  if (type == 1 && isDifferentialPayment) {
    for (QLabel* label : dynamicLabels) {
      delete label;
    }
    dynamicLabels.clear();  // Очищаем вектор созданных лейблов
    isDifferentialPayment = false;
  }
  if (type == 1) {  // Аннуитетный
    // Восстанавливаем исходные размеры и положения лейблов
    for (const auto& info : labelsInfo) {
      info.label->setFixedSize(info.originalSize);
      info.label->move(info.originalPos);
    }
    ui->MonthlyPayment_label->setText("Monthly \npayment");
    // Код для аннуитетного платежа
    calculateAnnuityPayment(loan, rate, term, total_loan,
                            interest_rate_payment);
  } else {                               // Дифференцированный
    static QLabel* newLabelL = nullptr;  // Инициализация один раз
    static QLabel* newLabel = nullptr;  // Инициализация один раз
    if (!isDifferentialPayment) {  // Проверяем, был ли уже выбран
      createDifferentialPaymentLabels(
          newLabelL, newLabel);  // дифференцированный тип платежа
      for (auto& info : labelsInfo) {
        if (info.label->y() > newLabel->y()) {
          info.label->move(info.label->x(),
                           info.label->y() + newLabel->height() + 10);
        }
      }
      isDifferentialPayment = true;
    }
    calculateDifferentialPayment(loan, rate, term, total_loan,
                                 interest_rate_payment, newLabel);
  }
}

void Credit::initializeLabelsInfoAndResetFirstClick() {
  // Сохраняем позиции и размеры лейблов в вектор только при первом клике
  labelsInfo.clear();  // Очищаем вектор перед заполнением
  labelsInfo.push_back({ui->Overpayment_label, ui->Overpayment_label->pos(),
                        ui->Overpayment_label->size()});
  labelsInfo.push_back({ui->TotalPayout_label, ui->TotalPayout_label->pos(),
                        ui->TotalPayout_label->size()});
  labelsInfo.push_back({ui->label_overpayment, ui->label_overpayment->pos(),
                        ui->label_overpayment->size()});
  labelsInfo.push_back(
      {ui->label_payout, ui->label_payout->pos(), ui->label_payout->size()});
}

void Credit::createDifferentialPaymentLabels(QLabel*& newLabelL,
                                             QLabel*& newLabel) {
  newLabelL = new QLabel(this);
  ui->MonthlyPayment_label->setText("Max monthly \npayment");
  newLabelL->setText("Min monthly \npayment");
  newLabelL->setGeometry(
      ui->MonthlyPayment_label->x(),
      ui->MonthlyPayment_label->y() + ui->MonthlyPayment_label->height() + 10,
      ui->MonthlyPayment_label->width(), 41);
  newLabelL->show();
  dynamicLabels.push_back(
      newLabelL);  // Добавляем новый лейбл в список созданных

  newLabel = new QLabel(this);
  newLabel->setGeometry(
      ui->label_m_payment->x(),
      ui->label_m_payment->y() + ui->label_m_payment->height() + 10,
      ui->label_m_payment->width(), ui->label_m_payment->height());
  newLabel->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
  newLabel->setStyleSheet("border: 1px solid white;");
  newLabel->show();
  dynamicLabels.push_back(
      newLabel);  // Добавляем новый лейбл в список созданных
}
//////////////////////////////////
///
/// FULL FUNC
// void Credit::on_Calculate_Credit_clicked()
//{
//     int type = ui->Type_comboBox->currentData().toInt();
//     static std::vector<LabelInfo> labelsInfo; // Статический вектор для
//     хранения информации о лейблах static std::vector<QLabel*> dynamicLabels;
//     // Статический вектор для хранения созданных лейблов static bool
//     isDifferentialPayment = false; // Статическая переменная для
//     отслеживания, был ли уже выбран дифференцированный тип платежа static
//     bool isFirstClick = true; // Статическая переменная для отслеживания, был
//     ли уже выполнен первый клик

//    if (isFirstClick) {
//        // Сохраняем позиции и размеры лейблов в вектор только при первом
//        клике labelsInfo.clear(); // Очищаем вектор перед заполнением
//        labelsInfo.push_back({ui->Overpayment_label,
//        ui->Overpayment_label->pos(), ui->Overpayment_label->size()});
//        labelsInfo.push_back({ui->TotalPayout_label,
//        ui->TotalPayout_label->pos(), ui->TotalPayout_label->size()});
//        labelsInfo.push_back({ui->label_overpayment,
//        ui->label_overpayment->pos(), ui->label_overpayment->size()});
//        labelsInfo.push_back({ui->label_payout, ui->label_payout->pos(),
//        ui->label_payout->size()}); isFirstClick = false; // Сбрасываем флаг,
//        так как первый клик уже был обработан
//    }

//    // Удаляем созданные лейблы при переключении на аннуитетный тип платежа
//    if (type == 1 && isDifferentialPayment) {
//        for (QLabel* label : dynamicLabels) {
//            delete label;
//        }
//        dynamicLabels.clear(); // Очищаем вектор созданных лейблов
//        isDifferentialPayment = false; // Сбрасываем флаг, так как теперь
//        выбран аннуитетный тип платежа
//    }

//    if (type == 1) { // Аннуитетный
//        // Восстанавливаем исходные размеры и положения лейблов
//        for (const auto& info : labelsInfo) {
//            info.label->setFixedSize(info.originalSize);
//            info.label->move(info.originalPos);
//        }
//        ui->MonthlyPayment_label->setText("Monthly \npayment");
//        // Код для аннуитетного платежа
//    } else { // Дифференцированный
//        if (!isDifferentialPayment) { // Проверяем, был ли уже выбран
//        дифференцированный тип платежа
//            // Создаем новый лейбл для вывода под label_m_payment
//            QLabel* newLabelL = new QLabel(this);
//            ui->MonthlyPayment_label->setText("Max monthly \npayment");
//            newLabelL->setText("Min Monthly \npayment");
//            newLabelL->setGeometry(ui->MonthlyPayment_label->x(),
//            ui->MonthlyPayment_label->y() + ui->MonthlyPayment_label->height()
//            + 10, ui->MonthlyPayment_label->width(), 41); newLabelL->show();
//            dynamicLabels.push_back(newLabelL); // Добавляем новый лейбл в
//            список созданных

//            QLabel* newLabel = new QLabel(this);
//            newLabel->setGeometry(ui->label_m_payment->x(),
//            ui->label_m_payment->y() + ui->label_m_payment->height()+10,
//            ui->label_m_payment->width(), ui->label_m_payment->height());
//            newLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop); //
//            Выравнивание текста по верхнему левому краю
//            newLabel->setStyleSheet("border: 1px solid white;");
//            newLabel->show();
//            dynamicLabels.push_back(newLabel); // Добавляем новый лейбл в
//            список созданных

//            // Сдвигаем остальные лейблы вниз
//            for (auto& info : labelsInfo) {
//                if (info.label->y() > newLabel->y()) {
//                    info.label->move(info.label->x(), info.label->y() +
//                    newLabel->height() + 10);
//                }
//            }

//            isDifferentialPayment = true; // Устанавливаем флаг, что
//            дифференцированный тип платежа уже был выбран
//        }
//    }
//}
