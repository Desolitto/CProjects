#include "mainwindow.h"

#include "ui_mainwindow.h"

//#include <QScreen>
#include "../my_smart_calc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QWidget::setWindowTitle("Calculator");
  // Создание соединений между кнопками и слотами
  // Соединение 0 - 9 кнопок с слотом pushButton
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  // Создание соединений для арифметических кнопок
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(pushButton()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(pushButton()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(pushButton()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(pushButton()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(pushButton()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(pushButton()));

  // Создание соединений для скобок
  connect(ui->pushButton_Lbkt, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_Rbkt, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));

  // Создание соединений для x
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(pushButton_x()));

  // Создание соединений для тригонометрических и логарифмических функций
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(pushBUttonTrig()));
}

MainWindow::~MainWindow() { delete ui; }

// Обработчик нажатия кнопки
void MainWindow::pushButton() {
  QPushButton *button =
      (QPushButton *)sender();  // Получение указателя на кнопку-отправителя
  QLabel *currentLabel;
  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }
  QString new_label =
      currentLabel->text();  // Получение текущего текста из метки
  QStringList errorLabels = {"ERROR",
                             "CALCULATION_ERROR",
                             "MEMORY_ERROR",
                             "INCORRECT_INPUT",
                             "DIV_BY_ZERO",
                             "NAN_OR_INF",
                             "SORRY_CANT_CALC_WITH_E"};
  if (errorLabels.contains(new_label)) {  // Если на метке "+-0" или "Error"
    currentLabel->setText(button->text());
  } else {
    currentLabel->setText(currentLabel->text() + button->text());
  }
}

// Обработчик нажатия кнопки x
void MainWindow::pushButton_x() {
  QPushButton *button =
      (QPushButton *)sender();  // Получение указателя на кнопку-отправителя
  QLabel *currentLabel;
  if (modeswitchx) {
    currentLabel = ui->input_output_label;
    QString new_label =
        currentLabel->text();  // Получение текущего текста из метки
    QStringList errorLabels = {"0",
                               "ERROR",
                               "CALCULATION_ERROR",
                               "MEMORY_ERROR",
                               "INCORRECT_INPUT",
                               "DIV_BY_ZERO",
                               "NAN_OR_INF",
                               "SORRY_CANT_CALC_WITH_E"};
    if (currentLabel->text() == "-0") {
      currentLabel->setText("-");
    }
    if (currentLabel->text() == "+0") {
      currentLabel->setText("+");
    }
    if (errorLabels.contains(new_label)) {  // Если на метке "+-0" или "Error"
      currentLabel->setText(button->text());
    } else {
      currentLabel->setText(currentLabel->text() + button->text());
    }
  }
}

void MainWindow::pushBUttonTrig() {
  QLabel *currentLabel;
  QPushButton *button =
      (QPushButton *)sender();  // Получение указателя на кнопку-отправителя
  QStringList errorLabels = {"0",
                             "ERROR",
                             "CALCULATION_ERROR",
                             "MEMORY_ERROR",
                             "INCORRECT_INPUT",
                             "DIV_BY_ZERO",
                             "NAN_OR_INF",
                             "SORRY_CANT_CALC_WITH_E"};
  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }

  QString new_label =
      currentLabel->text();  // Получение текущего текста из метки

  if (currentLabel->text() == "-0") {
    currentLabel->setText("-");
  }
  if (currentLabel->text() == "+0") {
    currentLabel->setText("+");
  }

  if (errorLabels.contains(new_label)) {
    currentLabel->setText(button->text());
  } else {
    currentLabel->setText(currentLabel->text() + button->text());
  }
}

void MainWindow::digits_numbers() {
  QLabel *currentLabel;
  QPushButton *button = (QPushButton *)sender();
  QStringList errorLabels = {"ERROR",
                             "CALCULATION_ERROR",
                             "MEMORY_ERROR",
                             "INCORRECT_INPUT",
                             "DIV_BY_ZERO",
                             "NAN_OR_INF",
                             "SORRY_CANT_CALC_WITH_E"};
  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }

  QString new_label = currentLabel->text();

  if (currentLabel->text() == "0" && button->text() != ".") {
    currentLabel->setText("");
    if (button->text() == ".") currentLabel->setText("0");
  }
  if (currentLabel->text() == "-0" && button->text() != ".") {
    currentLabel->setText("-");
    if (button->text() == ".") ui->input_output_label->setText("-0");
  }
  if (currentLabel->text() == "+0" && button->text() != ".") {
    currentLabel->setText("+");
    if (button->text() == ".") currentLabel->setText("+0");
  }

  if (errorLabels.contains(new_label)) {
    currentLabel->setText(button->text());
  } else {
    currentLabel->setText(currentLabel->text() + button->text());
  }
}

void MainWindow::on_pushButton_point_clicked() {
  QLabel *currentLabel;

  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }
  currentLabel->setText(currentLabel->text() + ".");
}

void MainWindow::on_pushButton_Uminus_clicked() {
  QLabel *currentLabel;

  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }

  if (currentLabel->text() == "0")
    currentLabel->setText("-" + currentLabel->text());
  else
    currentLabel->setText(currentLabel->text() + "-");
}

void MainWindow::on_pushButton_Uplus_clicked() {
  QLabel *currentLabel;

  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }

  if (currentLabel->text() == "0")
    currentLabel->setText("+" + currentLabel->text());
  else
    currentLabel->setText(currentLabel->text() + "+");
}

void MainWindow::on_pushButton_clear_clicked() {
  QLabel *currentLabel;

  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }

  currentLabel->setText("0");
}

void MainWindow::on_pushButton_del_clicked() {
  QLabel *currentLabel;
  if (modeswitchx) {
    currentLabel = ui->input_output_label;
  } else {
    currentLabel = ui->label_input_x;
  }
  QString currentString = currentLabel->text();

  if (currentString.isEmpty()) {
    currentString = "0";
  } else {
    // Регулярное выражение, которое ищет последовательность нечисловых символов
    // и символов, не являющихся операторами, начиная с конца строки
    QRegularExpression static re("[^0-9\\(\\)+\\-*/^]+$");
    QRegularExpressionMatch match = re.match(currentString);

    if (match.hasMatch()) {
      // Удаляем совпадение с конца строки
      currentString.remove(match.capturedStart(0), match.capturedLength(0));
    } else {
      // Если совпадений нет, удаляем последний символ
      currentString.chop(1);
    }
  }

  currentLabel->setText(currentString);
  if (currentLabel->text() == "") {
    currentLabel->setText("0");
  }
}

void MainWindow::on_pushButton_eq_clicked() {
  double result = 0.0;
  int status = 0;
  QStringList errorLabels = {"ERROR",
                             "CALCULATION_ERROR",
                             "MEMORY_ERROR",
                             "INCORRECT_INPUT",
                             "DIV_BY_ZERO",
                             "NAN_OR_INF",
                             "SORRY_CANT_CALC_WITH_E"};
  if (!errorLabels.contains(ui->input_output_label->text())) {
    if (ui->input_output_label->text().contains("x")) {
      status = full_calcuation(
          (char *)ui->input_output_label->text().toStdString().c_str(), &result,
          (char *)ui->label_input_x->text().toStdString().c_str());
    } else {
      status = full_calcuation(
          (char *)ui->input_output_label->text().toStdString().c_str(), &result,
          0);
    }
  }
  if (!graph) {
    QString new_label = "";
    if (std::isnan(result) || status > 0) {
      if (status == 1) {
        new_label = "CALCULATION_ERROR";
      } else if (status == 2) {
        new_label = "MEMORY_ERROR";
      } else if (status == 3) {
        new_label = "INCORRECT_INPUT";
      } else if (status == 4) {
        new_label = "DIV_BY_ZERO";
      } else if (status == 5) {
        new_label = "NAN_OR_INF";
      } else if (status == 6) {
        new_label = "SORRY_CANT_CALC_WITH_E";
      } else {
        new_label = "ERROR";
      }
      ui->input_output_label->setText(new_label);  // Общий случай
    } else {
      ui->input_output_label->setText(QString::number(result, 'g', 15));
    }
  }
}

void MainWindow::onChangeButtonColorClicked(const QString &color,
                                            const QString &color_buttons) {
  // Получаем все кнопки на форме
  QList<QPushButton *> buttons = this->findChildren<QPushButton *>();

  // Цвет, который будет применен к кнопкам
  QString newColor =
      QString("background-color: %1; color: %2;").arg(color, color_buttons);

  // Изменяем цвет каждой кнопки
  for (QPushButton *button : buttons) {
    button->setStyleSheet(newColor);
  }
  emit buttonColorChanged(color, color_buttons);
}

void MainWindow::on_pushButton_p_clicked() {
  static int clickCounter =
      0;  // Счетчик кликов, используемый для переключения цветов
  static QString initialStyleSheet = "";  // Сохранение начального стиля фона
  QString color, color_text;
  QString color_buttons;

  // Если это первый клик, сохраняем начальный стиль фона
  if (clickCounter == 0) {
    initialStyleSheet = this->styleSheet();
  }
  // Переключение между цветами при каждом клике
  switch (
      clickCounter %
      5) {  // Используем остаток от деления на 5 для циклического переключения
    case 0:
      color = "rgb(255, 184, 234)";  // Розовый
      color_buttons = "rgb(255, 255, 255)";
      color_text = color;
      break;
    case 1:
      color = "rgb(158, 219, 15)";  // Зеленый
      color_buttons = "rgb(209, 15, 102)";
      color_text = "rgb(255, 255, 255)";
      break;
    case 2:
      color = "rgb(0, 0, 255)";  // Синий
      color_buttons = "rgb(255, 20, 188)";
      color_text = "rgb(255, 255, 255)";
      break;
    case 3:
      color = "rgb(0, 0, 0)";  // Черный
      color_buttons = "rgb(255, 20, 188)";
      color_text = "rgb(255, 255, 255)";
      break;
  }
  // Если 5 клик, возвращаемся к стартовому цвету
  if (clickCounter % 5 == 4) {
    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
    this->setStyleSheet(initialStyleSheet);
    for (QPushButton *button : buttons) {
      button->setStyleSheet("");
    }
  } else {
    // Изменение фона всего приложения на выбранный цвет
    this->setStyleSheet(QString("QWidget {background-color: %1;}").arg(color));
    onChangeButtonColorClicked(color_buttons, color_text);
  }
  // Увеличение счетчика кликов
  clickCounter++;
}

/////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_graph_clicked() {
  QStringList errorLabels = {"ERROR",
                             "CALCULATION_ERROR",
                             "MEMORY_ERROR",
                             "INCORRECT_INPUT",
                             "DIV_BY_ZERO",
                             "NAN_OR_INF",
                             "SORRY_CANT_CALC_WITH_E"};

  // Проверяем, существует ли уже окно графа
  if (!graph) {
    if (credit) {
      credit->close();
      credit = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы
                         // разрешить повторное открытие окна граф
    }
    // Если нет, создаем новое окно графа и устанавливаем его как дочернее окно
    // текущего окна
    graph = new graphwindow(this);
    graph->setWindowTitle(
        "Graph Window");  // Устанавливаем заголовок окна для удобства
    // Устанавливаем положение окна графа относительно основного окна
    // Например, можно открыть окно графа справа от основного окна
    graph->move(this->x() + this->width(), this->y());
    connect(graph, &graphwindow::graphWindowClosed, this,
            &MainWindow::onGraphWindowClosed);
    graph->show();
    if (!errorLabels.contains(ui->input_output_label->text())) {
      connect(this, &MainWindow::sendFunctionText, graph,
              &graphwindow::onFunctionTextReceived);
    }
    emit sendFunctionText(ui->input_output_label->text());
    QMetaObject::invokeMethod(graph, "on_pushButton_print_graph_clicked",
                              Qt::QueuedConnection);
  } else {
    // Если окно графа уже существует, просто активируем его
    emit sendFunctionText(ui->input_output_label->text());
    graph->activateWindow();
  }
  ui->pushButton_graph->setText(" Function\n to Graph");
  ui->pushButton_graph->setStyleSheet("text-align:center;");
}

void MainWindow::onGraphWindowClosed() {
  graph = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы разрешить
                    // повторное открытие окна графа
  ui->pushButton_graph->setText("Graph");
}

void MainWindow::on_pushButton_switch_to_x_toggled(bool checked) {
  if (checked)
    modeswitchx = 0;
  else
    modeswitchx = 1;
}

/////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_deposit_clicked() {
  if (!deposit) {
    if (graph) {
      graph->close();
      graph = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы
                        // разрешить повторное открытие окна графа
      ui->pushButton_graph->setText("Graph");
    }
    if (credit) {
      credit->close();
      credit = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы
                         // разрешить повторное открытие окна граф
    }
    deposit = new Deposit(this);
    deposit->setWindowTitle(
        "Deposit Window");  // Устанавливаем заголовок окна для удобства
    deposit->setModal(true);  // Делаем новое окно модальным
    connect(deposit, &Deposit::depositWindowClosed, this,
            &MainWindow::onDepositWindowClosed);
    deposit->show();
  } else {
    deposit->activateWindow();
  }
}

void MainWindow::on_pushButton_credit_clicked() {
  if (!credit) {
    if (graph) {
      graph->close();
      graph = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы
                        // разрешить повторное открытие окна графа
      ui->pushButton_graph->setText("Graph");
    }
    credit = new Credit(this);
    credit->setWindowTitle("Credit Window");
    connect(credit, &Credit::creditWindowClosed, this,
            &MainWindow::onCreditWindowClosed);
    credit->move(this->x() + this->width(), this->y());
    credit->show();

  } else {
    credit->activateWindow();
  }
}

void MainWindow::onCreditWindowClosed() {
  credit = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы
                     // разрешить повторное открытие окна графа
}

void MainWindow::onDepositWindowClosed() {
  deposit = nullptr;  // Устанавливаем переменную graph в nullptr, чтобы
                      // разрешить повторное открытие окна графа
}
