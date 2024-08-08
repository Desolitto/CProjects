#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus
extern "C" {
#endif
#include "../../back/3D_Viewer.h"
#ifdef __cplusplus
}
#endif

#include <qgifimage.h>  //либа для гифок

#include <QColorDialog>  // Предоставляет класс для отображения диалогового окна выбора цвета
#include <QFileDialog>  // Класс для создания диалоговых окон выбора и сохранения файлов
#include <QMainWindow>  // Основной класс для создания приложений на основе многоконной архитектуры
#include <QMessageBox>  // Класс для создания окон с сообщениями (предупреждения, информация, ошибки)
#include <QObject>  // Базовый класс Qt, предоставляющий механизмы сигналов и слотов
#include <QPushButton>  // Класс для создания кнопок в интерфейсе
#include <QSettings>  // Класс для работы с сохранением и загрузкой настроек
#include <QTimer>  // Класс для управления таймерами и периодическими событиями
#include <iostream>  // Стандартная библиотека ввода/вывода C++

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);  // Конструктор с опциональным
                                          // родительским виджетом
  ~MainWindow();  // Деструктор

  QString filepath;
  QSettings settings;
  QList<QImage> frames;

 private slots:

  void on_btn_open_file_clicked();

  void on_btn_background_color_clicked();

  void on_btn_line_color_clicked();

  void on_btn_vertex_color_clicked();

  void on_btn_radio_vertex_null_clicked();

  void on_btn_radio_vertex_square_clicked();

  void on_btn_radio_vertex_circle_clicked();

  void on_btn_radio_solid_line_clicked();

  void on_btn_radio_dotted_line_clicked();

  void on_slider_vertex_thickness_valueChanged(int value);

  void on_slider_line_thickness_valueChanged(int value);

  void on_zoom_slider_valueChanged(int value);

  void on_slider_axis_X_valueChanged(int value);

  void on_slider_axis_Y_valueChanged(int value);

  void on_slider_axis_Z_valueChanged(int value);

  void on_slider_angel_X_valueChanged(int value);

  void on_slider_angel_Y_valueChanged(int value);

  void on_slider_angel_Z_valueChanged(int value);

  void on_btn_radio_plane_parall_clicked();

  void on_btn_radio_plane_center_clicked();

  void on_btn_save_jpeg_clicked();

  void on_btn_save_bmp_clicked();

  void on_btn_save_gif_clicked();

 private:
  Ui::MainWindow *ui;
  void save_settings();
  void load_settings();
  void saveImage(const QString &filePath, const QString &format);

  void captureFrame();
  void createGif();

  // Настройки модели
};
#endif  // MAINWINDOW_H
