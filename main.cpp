#include <QApplication>

#include "calculator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  Calculator calculator;
  calculator.resize(210, 240);
  calculator.setWindowTitle("Calculator");

  QPalette calculator_palette;
  calculator_palette.setColor(QPalette::Background, Qt::black);
  calculator.setPalette(calculator_palette);

  calculator.show();

  return a.exec();
}
