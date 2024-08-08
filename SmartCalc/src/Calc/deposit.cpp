#include "deposit.h"

#include "../my_smart_calc.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget* parent) : QDialog(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
  this->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint |
                       Qt::CustomizeWindowHint);
  // Валидация для поля amount_input
  QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1e15, 2);
  ui->amount_input->setValidator(doubleValidator);
  ui->sum_input->setValidator(doubleValidator);
  ui->rate_int->setValidator(doubleValidator);
  ui->rate_tax->setValidator(doubleValidator);
  QTableWidget* tbl = ui->deposit_table;
  tbl->setColumnCount(4);
  QStringList names = {"Type", "Term", "№: Month", "Amount"};
  tbl->setHorizontalHeaderLabels(names);
  tbl->setColumnWidth(0, 200);
  tbl->setColumnWidth(1, 148);
  tbl->setColumnWidth(2, 100);
  tbl->setColumnWidth(3, 300);

  QDateEdit* date = ui->dateEdit;
  QDate minDate(2024, 1, 1);  // Установка минимальной даты на 01.01.2024
  date->setMinimumDate(minDate);
  QDate maxDate = minDate.addMonths(1);
  // Установка новой максимальной даты в QDateEdit
  date->setMaximumDate(maxDate);

  QComboBox* term = ui->term;
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
  connect(term, &QComboBox::currentIndexChanged, this, &Deposit::onTermChanged);

  QComboBox* period = ui->periodicity;
  period->addItem("1 month", QVariant(1));
  period->addItem("2 months", QVariant(2));
  period->addItem("Every quart", QVariant(3));
  period->addItem("6 months", QVariant(6));
  period->addItem("1 year", QVariant(12));

  QComboBox* per_dep = ui->period_to_tab;
  per_dep->addItem("Once", QVariant(0));

  QComboBox* cap = ui->comboBox_capitalization;
  cap->addItem("Disabled", QVariant(0));
  cap->addItem("Enabled", QVariant(1));
}

Deposit::~Deposit() { delete ui; }

// Слот, который вызывается при изменении выбранного элемента в QComboBox
void Deposit::onTermChanged(int index) {
  QComboBox* term = ui->term;
  // Получение выбранного срока в месяцах
  int months = term->itemData(index).toInt();
  QDateEdit* date = ui->dateEdit;
  // Вычисление новой максимальной даты
  QDate minDate(2024, 1, 1);
  QDate maxDate = minDate.addMonths(months);

  // Установка новой максимальной даты в QDateEdit
  date->setMaximumDate(maxDate);
}

void Deposit::on_pushButton_back_clicked() {
  emit depositWindowClosed();
  this->close();
}

void Deposit::on_comboBox_capitalization_currentIndexChanged(int index) {
  // Получаем выбранное значение из comboBox_capitalization
  int selectedCapitalization =
      ui->comboBox_capitalization->itemData(index).toInt();

  // Очищаем текущие элементы в period
  ui->periodicity->clear();

  // Добавляем новые элементы в period в зависимости от выбранного значения в
  // comboBox_capitalization
  if (!selectedCapitalization) {  // Пример условия для выбранного значения
    ui->periodicity->addItem("1 month", QVariant(1));
    ui->periodicity->addItem("2 months", QVariant(2));
    //        ui->periodicity->addItem("3 months", QVariant(3));

    ui->periodicity->addItem("Every quart", QVariant(3));
    ui->periodicity->addItem("6 months", QVariant(6));
    ui->periodicity->addItem("1 year", QVariant(12));
    ui->label_payment->setText("Payment periodicity");
  } else {  // Другое условие
    ui->periodicity->addItem("Per month", QVariant(1));
    ui->periodicity->addItem("Per quart",
                             QVariant(3));  ////как будто бы 3 а не 4
    ui->periodicity->addItem("Per 6 months", QVariant(6));
    ui->periodicity->addItem("Per year", QVariant(12));
    ui->label_payment->setText("Capitalization periodicity");
  }

  // Выбираем первый элемент в period по умолчанию
  ui->periodicity->setCurrentIndex(0);
}

void Deposit::addRowToTable(const QString& operationType) {
  QTableWidget* tbl = ui->deposit_table;
  int row_cnt = tbl->rowCount();
  tbl->insertRow(row_cnt);
  tbl->setItem(row_cnt, 0, new QTableWidgetItem(operationType));

  QString period;
  int term_eng = ui->period_to_tab->currentData().toInt();
  if (!term_eng) {
    period = "Once";
  } else if (term_eng == 12) {
    period = "Per year";
  }

  QTableWidgetItem* new_item = new QTableWidgetItem(period);
  new_item->setData(Qt::UserRole, term_eng);
  tbl->setItem(row_cnt, 1, new_item);

  // Считывание даты и преобразование в номер месяца
  QDate date = ui->dateEdit->date();
  int monthNumber = date.month();  // Получение номера месяца
  int yearNumber = date.year();    // Получение номера года

  // Вычисление количества полных лет между текущей датой и 2024 годом
  int yearsDifference = yearNumber - 2024;
  // Увеличение номера месяца на 12 для каждого полного года после 2024 года
  monthNumber += yearsDifference * 12;

  // Отображение числа месяца и его названия в таблице
  QString monthName = date.toString("MMMM");
  QString displayText = QString("%1: %2").arg(monthNumber).arg(monthName);
  QTableWidgetItem* monthItem = new QTableWidgetItem(displayText);
  monthItem->setTextAlignment(
      Qt::AlignCenter);  // Выравнивание текста по центру
  tbl->setItem(row_cnt, 2, monthItem);

  double amount = ui->amount_input->text().replace(',', '.').toDouble();
  QTableWidgetItem* amountItem =
      new QTableWidgetItem(QString::number(amount, 'f', 2));
  amountItem->setTextAlignment(
      Qt::AlignCenter);  // Выравнивание текста по правому краю
  tbl->setItem(row_cnt, 3, amountItem);
}

void Deposit::on_pushButton_add_clicked() { addRowToTable("Deposit"); }

void Deposit::on_pushButton_with_clicked() { addRowToTable("Withdrawal"); }

void Deposit::on_pushButton_del_clicked() {
  QTableWidget* table =
      ui->deposit_table;  // Предполагается, что у вас есть QTableWidget с
                          // именем tableWidget в вашем интерфейсе
  int lastRowIndex = table->rowCount() - 1;  // Получаем индекс последней строки
  if (lastRowIndex >= 0) {  // Проверяем, что таблица не пуста
    table->removeRow(lastRowIndex);  // Удаляем последнюю строку
  }
}

// int my_deposit_calc(deposit_calc_struct* deposit, double* total_amount,
//                      double* tax_amount, double* interest_amount) {
//   int error = false;
//   double origin_deposit = deposit->sum;

//  if (!deposit->capitalization) {
//    calculateInterestWithoutCapitalization(deposit, interest_amount,
//                                           tax_amount);
//  } else {
//    calculateInterestWithCapitalization(deposit, interest_amount, tax_amount);
//  }

//  *total_amount = origin_deposit + *interest_amount;

//  return error;
//}

// void calculateInterestWithoutCapitalization(deposit_calc_struct* deposit,
//                                             double* interest_amount,
//                                             double* tax_amount) {
//   *interest_amount =
//       deposit->sum * deposit->interest_rate * deposit->duration_month /
//       1200.0;
//   if (*interest_amount - 160000 > 0)
//     *tax_amount = (*interest_amount - 160000) * deposit->tax_rate / 100;
//   else
//     *tax_amount = 0.0;
// }

// void calculateInterestWithCapitalization(deposit_calc_struct* deposit,
//                                          double* interest_amount,
//                                          double* tax_amount) {
//   double num_pay = 1.0;
//   *tax_amount = 0.0;  // Инициализация tax_amount
//   if (deposit->frequency_of_payments > deposit->duration_month) {
//     deposit->frequency_of_payments = deposit->duration_month;
//   } else {
//     num_pay = (12.0 / deposit->frequency_of_payments);
//   }
//   double interest_sum = 0;
//   double period =
//       ceil(deposit->duration_month / deposit->frequency_of_payments);
//   double year_interest = 0.0;
//   int count_month = 1;
//   int month = deposit->duration_month;
//   //    int months_with_payments = 0; // Добавление переменной для подсчета
//   //    месяцев с выплатами

//  while (period > 0) {
//    double interest =
//        deposit->sum * ((deposit->interest_rate / 100.0) /
//                        (12.0 / (month < deposit->frequency_of_payments
//                                     ? month
//                                     : deposit->frequency_of_payments)));
//    deposit->sum += interest;
//    interest_sum += interest;
//    year_interest += interest;
//    if (count_month == num_pay - 1 || period <= 1 ||
//        (num_pay == 1 && ((int)deposit->duration_month %
//                          (int)deposit->frequency_of_payments) == 0)) {
//      *tax_amount +=
//          std::max(0.0, year_interest - 160000) * deposit->tax_rate / 100;
//      count_month = 0;
//      year_interest = 0.0;
//    } else {
//      count_month++;
//    }
//    //        months_with_payments++; // Увеличение счетчика месяцев с
//    выплатами period--; month = deposit->duration_month -
//    deposit->frequency_of_payments;
//  }
//  *interest_amount = interest_sum;
//}

////3111
void Deposit::on_pushButton_calc_clicked() {
  deposit.sum = ui->sum_input->text().replace(',', '.').toDouble();
  // Инициализация общей суммы депозита
  double totalDepositAmount = deposit.sum;
  // Считывание данных из таблицы
  std::vector<Operation> operations;
  for (int row_cnt = 0; row_cnt < ui->deposit_table->rowCount(); ++row_cnt) {
    readRowFromTable(row_cnt, operations);
  }
  // Проверка типа операции и изменение общей суммы депозита
  for (const Operation& op : operations) {
    if (op.operationType == "Deposit") {
      totalDepositAmount += op.amount;
    } else if (op.operationType == "Withdrawal") {
      // Проверка, превышает ли сумма снятия текущую сумму депозита
      if (op.amount > totalDepositAmount) {
        QMessageBox::warning(
            this, "Ошибка",
            "Сумма снятия не может быть больше текущей суммы депозита.");
        // return; // Прекратить выполнение функции, если условие не выполняется
      } else {
        totalDepositAmount -= op.amount;
      }
    }
  }

  deposit.sum = totalDepositAmount;
  deposit.interest_rate = ui->rate_int->text().replace(',', '.').toDouble();
  deposit.tax_rate = ui->rate_tax->text().replace(',', '.').toDouble();
  deposit.duration_month = ui->term->currentData().toDouble();
  deposit.frequency_of_payments = ui->periodicity->currentData().toDouble();
  deposit.capitalization =
      ui->comboBox_capitalization->currentData().toDouble();

  double total_amount, tax_amount, interest_amount = 0.0;

  my_deposit_calc(&deposit, &total_amount, &tax_amount, &interest_amount);
  ui->Amount_output->setText(QString::number(total_amount, 'f', 2));
  ui->Tax_output->setText(QString::number(tax_amount, 'f', 2));
  ui->Income_output->setText(QString::number(interest_amount, 'f', 2));
}

/*
В функции void Deposit::readRowFromTable(int row_cnt, std::vector<Operation>&
operations), std::vector<Operation>& operations означает, что функция принимает
ссылку на вектор объектов типа Operation в качестве одного из своих параметров.
Это позволяет функции изменять содержимое вектора, переданного в неё, напрямую,
без необходимости возвращать изменённый вектор.

std::vector<Operation> указывает на то, что параметр operations является
вектором, содержащим элементы типа Operation. std::vector — это динамический
массив, который может изменять свой размер во время выполнения программы, что
делает его удобным для хранения коллекций данных, размер которых может
изменяться 10. & перед operations означает, что параметр передаётся по ссылке.
Это означает, что функция работает не с копией вектора, а с самим вектором,
переданным в неё. Любые изменения, сделанные с вектором внутри функции, будут
отражены на оригинальном векторе, который был передан в функцию. Это позволяет
избежать дополнительных затрат на копирование вектора и делает функцию более
эффективной 10. В контексте вашей функции readRowFromTable, это означает, что вы
можете добавлять, удалять или изменять элементы вектора operations
непосредственно внутри функции, и эти изменения будут видны и вне функции. Это
особенно полезно, когда вы хотите агрегировать данные из различных источников в
один вектор, как в вашем случае, где вы считываете данные из таблицы и
добавляете их в вектор операций.

В контексте std::vector<Operation>, Operation — это тип данных, который
определен пользователем. Это может быть структура, класс или любой другой
пользовательский тип данных. Вектор std::vector<Operation> будет содержать
элементы этого типа.

Использование std::vector позволяет легко и эффективно работать с коллекциями
данных, предоставляя широкий спектр функций для управления этими данными.
*/

void Deposit::readRowFromTable(int row_cnt,
                               std::vector<Operation>& operations) {
  QTableWidget* tbl = ui->deposit_table;

  // Считывание типа операции
  QString operationType = tbl->item(row_cnt, 0)->text();

  // Считывание периодичности
  QTableWidgetItem* periodItem = tbl->item(row_cnt, 1);
  int term_eng = periodItem->data(Qt::UserRole).toInt();

  // Считывание даты
  QString displayText =
      tbl->item(row_cnt, 2)->text();  // Получение строки из таблицы
  QStringList parts = displayText.split(":");  // Разделение строки по двоеточию
  int monthNumber = parts[0].toInt();

  // Считывание суммы
  QString amountStr = tbl->item(row_cnt, 3)->text();
  double amount = amountStr.replace(',', '.').toDouble();

  // Создание и добавление операции в вектор
  Operation op = {operationType, term_eng, monthNumber, amount};
  operations.push_back(op);
}
