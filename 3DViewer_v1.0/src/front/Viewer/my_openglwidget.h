#ifndef S21_OPENGLWIDGET_H
#define S21_OPENGLWIDGET_H

#ifdef __cplusplus
extern "C" {
#endif
#include "../../back/3D_Viewer.h"
#ifdef __cplusplus
}
#endif

#include <QMouseEvent>
#include <QObject>
#include <QOpenGLWidget>

#define PARALLEL 1
#define CENTRAL 0
#define VERTEX_NONE 0
#define VERTEX_CIRCLE 1
#define VERTEX_SQUARE 2
#define LINE_SOLID 1
#define LINE_DOTTED 0

class my_OpenGLWidget : public QOpenGLWidget {
 public:
  my_OpenGLWidget(QWidget *parent);
  f_data data_f{};
  v_data data_v{};

  int projection = CENTRAL;

  int linetype = LINE_SOLID;
  float line_thickness = 2.0f;

  int vertextype = VERTEX_NONE;
  float vertex_thickness = 2.0f;

  int status = OK;
  float scale = 0.0;
  int shift_x = 0;
  int shift_y = 0;
  int shift_z = 0;
  int rotate_x = 0;
  int rotate_y = 0;
  int rotate_z = 0;

  float rotationX = 0;  // углы поворота вокруг осей X
  float rotationY = 0;  // углы поворота вокруг осей Y

  my_color my_background_openjl = {0.0, 0.0, 0.0};
  my_color my_line = {1.0, 1.0, 1.0};
  my_color my_vertex = {1.0, 1.0, 1.0};

  bool isMousePressed;
  QPoint lastMousePos;

 protected:
  void initializeGL() override;
  void paintGL() override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif  // S21_OPENGLWIDGET_H
