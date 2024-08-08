#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  load_settings();
  //    settings.beginGroup("3dViewerSettings");
  setWindowTitle("3DViewer");  // Задаем заголовок окна
}

MainWindow::~MainWindow() {
  save_settings();
  delete ui;
}

void MainWindow::on_btn_open_file_clicked() {
  ui->openGLWidget->status = 0;
  //    filepath =
  //    "/Users/jenisepl/Desktop/myProjects/C8_3DViewer_v1.0-1/src/obj/cube.obj";
  //    filepath =
  //    "/Users/calamarp/Projects/C8_3DViewer_v1.0-1/src/obj/cube.obj";
  filepath = QFileDialog::getOpenFileName(
      this, tr("Open File"), "/Users/$(whoami)/", tr("Obj file (*.obj)"));
  if (!filepath.isEmpty()) {
    freeData(&ui->openGLWidget->data_f,
             &ui->openGLWidget->data_v);  // чтоб обнулять инфу
    std::string stdString = filepath.toStdString();
    const char *path = stdString.c_str();
    QFileInfo fileInfo(filepath);
    ui->label_namefile_output->setText(fileInfo.fileName());
    FILE *file = fopen(path, "r");
    if (file == NULL) {
      QMessageBox::warning(this, tr("Ошибка"), tr("Ошибка открытия файла"));
      qDebug() << "Ошибка открытия файла";
      save_settings();
      return;
    }
    my_parse_obj(&ui->openGLWidget->data_v, &ui->openGLWidget->data_f, file);
    QString errorMessage;
    ui->openGLWidget->status =
        my_valid_data(&ui->openGLWidget->data_f, &ui->openGLWidget->data_v);
    if (ui->openGLWidget->status != OK) {
      errorMessage = tr("Файл содержит некорректные данные или пуст");
      QMessageBox::warning(this, tr("Ошибка"), errorMessage);
      filepath.clear();
      freeData(&ui->openGLWidget->data_f, &ui->openGLWidget->data_v);
      ui->label_edge_output->setText("0");
      ui->label_vertex_output->setText("0");
      save_settings();
      return;
    }
    my_normalize(&ui->openGLWidget->data_v);
    my_centralize(&ui->openGLWidget->data_v);
    ui->openGLWidget->update();
    ui->label_vertex_output->setText(
        QString::number(ui->openGLWidget->data_v.count));
    ui->label_edge_output->setText(
        QString::number(ui->openGLWidget->data_f.count / 2));
    // zoom
    ui->openGLWidget->scale = 1.0;
    ui->openGLWidget->status = OK;
  }
}

void MainWindow::on_btn_background_color_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет");
  if (color.isValid()) {
    ui->openGLWidget->my_background_openjl.red = color.redF();
    ui->openGLWidget->my_background_openjl.green = color.greenF();
    ui->openGLWidget->my_background_openjl.blue = color.blueF();
  }
  ui->openGLWidget->update();
}

/*
line box
*/

void MainWindow::on_btn_line_color_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет");
  if (color.isValid()) {
    // Устанавливаем значения цвета линий
    ui->openGLWidget->my_line.red = color.redF();
    ui->openGLWidget->my_line.green = color.greenF();
    ui->openGLWidget->my_line.blue = color.blueF();
  }
  // Обновляем виджет
  ui->openGLWidget->update();
}

void MainWindow::on_btn_radio_solid_line_clicked() {
  ui->openGLWidget->linetype = LINE_SOLID;
  ui->openGLWidget->line_thickness = ui->slider_line_thickness->value() / 1.0f;
  ui->openGLWidget->update();
}

void MainWindow::on_btn_radio_dotted_line_clicked() {
  ui->openGLWidget->linetype = LINE_DOTTED;
  ui->openGLWidget->line_thickness = ui->slider_line_thickness->value() / 1.0f;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_line_thickness_valueChanged(int value) {
  ui->openGLWidget->line_thickness = value / 1.0f;
  QCoreApplication::processEvents();
  ui->openGLWidget->update();
}

/*
vertex box
*/

void MainWindow::on_btn_vertex_color_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет");
  if (color.isValid()) {
    // Устанавливаем значения цвета линий
    ui->openGLWidget->my_vertex.red = color.redF();
    ui->openGLWidget->my_vertex.green = color.greenF();
    ui->openGLWidget->my_vertex.blue = color.blueF();

    // Обновляем виджет
  }
  QCoreApplication::processEvents();
  ui->openGLWidget->update();
}

void MainWindow::on_btn_radio_vertex_null_clicked() {
  ui->openGLWidget->vertextype = VERTEX_NONE;
  ui->openGLWidget->update();
}

void MainWindow::on_btn_radio_vertex_square_clicked() {
  ui->openGLWidget->vertextype = VERTEX_SQUARE;
  ui->openGLWidget->vertex_thickness =
      ui->slider_vertex_thickness->value() / 1.0f;
  ui->openGLWidget->update();
}

void MainWindow::on_btn_radio_vertex_circle_clicked() {
  ui->openGLWidget->vertextype = VERTEX_CIRCLE;
  ui->openGLWidget->vertex_thickness =
      ui->slider_vertex_thickness->value() / 1.0f;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_vertex_thickness_valueChanged(int value) {
  ui->openGLWidget->vertex_thickness = value / 1.0f;
  ui->openGLWidget->update();
}

/*
x y z
*/

void MainWindow::on_zoom_slider_valueChanged(int value) {
  my_change_scale(&ui->openGLWidget->data_v,
                   (value / ui->openGLWidget->scale) / 10);
  ui->openGLWidget->scale = value / 10.0;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_axis_X_valueChanged(int value) {
  my_move(&ui->openGLWidget->data_v,
           (ui->openGLWidget->shift_x - value) / -100.0f, 0, 0);
  ui->openGLWidget->shift_x = value;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_axis_Y_valueChanged(int value) {
  my_move(&ui->openGLWidget->data_v, 0,
           (ui->openGLWidget->shift_y - value) / -100.0f, 0);
  ui->openGLWidget->shift_y = value;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_axis_Z_valueChanged(int value) {
  my_move(&ui->openGLWidget->data_v, 0, 0,
           (ui->openGLWidget->shift_z - value) / -100.0f);
  ui->openGLWidget->shift_z = value;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_angel_X_valueChanged(int value) {
  //        std::cout << value << std::endl;
  my_rotate_x(&ui->openGLWidget->data_v,
               (ui->openGLWidget->rotate_x - value) / -50.0f);
  ui->openGLWidget->rotate_x = value;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_angel_Y_valueChanged(int value) {
  my_rotate_y(&ui->openGLWidget->data_v,
               (ui->openGLWidget->rotate_x - value) / -50.0f);
  ui->openGLWidget->rotate_x = value;
  ui->openGLWidget->update();
}

void MainWindow::on_slider_angel_Z_valueChanged(int value) {
  my_rotate_z(&ui->openGLWidget->data_v,
               (ui->openGLWidget->rotate_x - value) / -50.0f);
  ui->openGLWidget->rotate_x = value;
  ui->openGLWidget->update();
}

/*
settings
*/

void MainWindow::save_settings() {
  settings.setValue("redbackcolor",
                    ui->openGLWidget->my_background_openjl.red);
  settings.setValue("greenbackcolor",
                    ui->openGLWidget->my_background_openjl.green);
  settings.setValue("bluebackcolor",
                    ui->openGLWidget->my_background_openjl.blue);
  settings.setValue("plane_center", ui->btn_radio_plane_center->isChecked());
  settings.setValue("plane_parall", ui->btn_radio_plane_parall->isChecked());
  // vertex
  settings.setValue("vertex_null", ui->btn_radio_vertex_null->isChecked());
  settings.setValue("vertex_circle", ui->btn_radio_vertex_circle->isChecked());
  settings.setValue("vertex_square", ui->btn_radio_vertex_square->isChecked());
  settings.setValue("redvertexcolor", ui->openGLWidget->my_vertex.red);
  settings.setValue("greeтvertexcolor", ui->openGLWidget->my_vertex.green);
  settings.setValue("bluevertexcolor", ui->openGLWidget->my_vertex.blue);
  settings.setValue("vertex_thickness", ui->slider_vertex_thickness->value());
  // line
  settings.setValue("line_solid", ui->btn_radio_solid_line->isChecked());
  settings.setValue("line_dotted", ui->btn_radio_dotted_line->isChecked());
  settings.setValue("redlinecolor", ui->openGLWidget->my_line.red);
  settings.setValue("greeтlinecolor", ui->openGLWidget->my_line.green);
  settings.setValue("bluelinecolor", ui->openGLWidget->my_line.blue);
  settings.setValue("line_thickness", ui->slider_line_thickness->value());
  // Сохранение слайдеры размера вершин
}

void MainWindow::load_settings() {
  ui->openGLWidget->my_background_openjl.red =
      settings.value("redbackcolor").toFloat();
  ui->openGLWidget->my_background_openjl.green =
      settings.value("greenbackcolor").toFloat();
  ui->openGLWidget->my_background_openjl.blue =
      settings.value("bluebackcolor").toFloat();
  ui->btn_radio_plane_center->setChecked(
      settings.value("plane_center").toBool());
  ui->btn_radio_plane_parall->setChecked(
      settings.value("plane_parall").toBool());
  ui->openGLWidget->projection = settings.value("plane_parall").toInt();
  // vertex
  ui->btn_radio_vertex_null->setChecked(settings.value("vertex_null").toBool());
  ui->btn_radio_vertex_circle->setChecked(
      settings.value("vertex_circle").toBool());
  ui->btn_radio_vertex_square->setChecked(
      settings.value("vertex_square").toBool());
  ui->openGLWidget->vertextype = settings.value("vertex_square").toInt();
  ui->openGLWidget->my_vertex.red = settings.value("redvertexcolor").toFloat();
  ui->openGLWidget->my_vertex.green =
      settings.value("greeтvertexcolor").toFloat();
  ui->openGLWidget->my_vertex.blue =
      settings.value("bluevertexcolor").toFloat();
  on_slider_vertex_thickness_valueChanged(
      settings.value("vertex_thickness").toInt());
  ui->slider_vertex_thickness->setValue(
      settings.value("vertex_thickness").toInt());
  // line
  ui->btn_radio_solid_line->setChecked(settings.value("line_solid").toBool());
  ui->btn_radio_dotted_line->setChecked(settings.value("line_dotted").toBool());
  ui->openGLWidget->linetype = settings.value("line_solid").toInt();

  ui->openGLWidget->my_line.red = settings.value("redlinecolor").toFloat();
  ui->openGLWidget->my_line.green = settings.value("greeтlinecolor").toFloat();
  ui->openGLWidget->my_line.blue = settings.value("bluelinecolor").toFloat();
  on_slider_line_thickness_valueChanged(
      settings.value("line_thickness").toInt());
  ui->slider_line_thickness->setValue(settings.value("line_thickness").toInt());
}

void MainWindow::on_btn_radio_plane_parall_clicked() {
  ui->openGLWidget->projection = PARALLEL;
  ui->openGLWidget->update();
}

void MainWindow::on_btn_radio_plane_center_clicked() {
  ui->openGLWidget->projection = CENTRAL;
  ui->openGLWidget->update();
}

/*
save
*/

void MainWindow::on_btn_save_jpeg_clicked() {
  QString filePath =
      QFileDialog::getSaveFileName(this, tr("Сохранить изображение"),
                                   QDir::homePath(), tr("Изображения (*.jpg)"));
  if (!filePath.isEmpty()) {
    saveImage(filePath, "JPEG");
  }
}

void MainWindow::on_btn_save_bmp_clicked() {
  QString filePath =
      QFileDialog::getSaveFileName(this, tr("Сохранить изображение"),
                                   QDir::homePath(), tr("Изображения (*.bmp)"));
  if (!filePath.isEmpty()) {
    saveImage(filePath, "BMP");
  }
}

void MainWindow::saveImage(const QString &filePath, const QString &format) {
  // Получаем текущий контекст OpenGL
  QOpenGLContext *context = ui->openGLWidget->context();
  if (!context) {
    //        qDebug() << "Ошибка: Контекст OpenGL не найден.";
    return;
  }

  // Получаем текущий кадр из QOpenGLWidget
  QImage image = ui->openGLWidget->grabFramebuffer();

  // Переворачиваем изображение, так как OpenGL использует противоположную
  // систему координат Y image = image.mirrored(false, true);

  // Сохраняем изображение в указанном формате
  if (!image.save(filePath, format.toUtf8().constData())) {
    //        qDebug() << "Ошибка: Не удалось сохранить изображение в формате"
    //        << format;
    return;
  }

  //    qDebug() << "Изображение успешно сохранено в" << filePath;
}

/*
gifs
*/

void MainWindow::on_btn_save_gif_clicked() {
  if (filepath.isEmpty()) {
    QMessageBox::information(this, tr("Alert"),
                             tr("Вы не загрузили модель для демонстрации"));
    return;
  }

  auto reply = QMessageBox::information(
      this, tr("Alert"),
      tr("Будут записаны все действия с моделью в течении 5 секунд."),
      QMessageBox::Ok | QMessageBox::Cancel);

  if (reply == QMessageBox::Ok) {
    frames.clear();  // Очищаем предыдущие кадры

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::captureFrame);
    timer->start(100);  // Захват кадра каждые 100 мс

    QTimer::singleShot(5000, this, [this, timer]() {
      timer->stop();
      createGif();
    });
  }
}

void MainWindow::captureFrame() {
  QImage frame = ui->openGLWidget->grabFramebuffer();
  frames.append(frame);
}

void MainWindow::createGif() {
  QGifImage gif(QSize(640, 480));
  gif.setDefaultDelay(100);

  for (const QImage &frame : std::as_const(frames)) {
    gif.addFrame(frame);
  }

  QFileInfo fileInfo(filepath);
  QString directory = fileInfo.absolutePath();  // Получаем директорию файла
  QString baseName =
      fileInfo.baseName();  // Получаем базовое имя файла без расширения
  //  std::cout << "Absolute Path: " << directory.toStdString() << std::endl;
  //  std::cout << "Base Name: " << baseName.toStdString() << std::endl;
  QString newFilePath = directory + "/" + baseName + ".gif";
  // Создаем новый путь с тем же базовым именем, но с расширением .jpg

  bool success = gif.save(newFilePath);
  if (!success) {
    // Обработка ошибки
    QMessageBox::warning(this, tr("Ошибка"),
                         tr("Не удалось сохранить анимацию."));
  } else {
    QMessageBox::information(this, tr("Успех!"),
                             tr("Анимация сохранена в папке с моделями(obj)."));
  }
}
