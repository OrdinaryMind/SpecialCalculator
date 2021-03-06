#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

#include <QAction>
#include <QMenu>
#include <QMenuBar>

class Former;
class Multiplier;
class StyleMaker;

class QClipboard;

class Calculator : public QWidget {
  Q_OBJECT
 public:
  explicit Calculator(QWidget* parent = nullptr);
  ~Calculator();

 public slots:
  void CalculateResult(const QString& result);
  void SetCoefficient(const QString& coefficient);

  void SetProgrammingStyle();
  void SetOfficeStyle();
  void SetMoto();

 signals:
  void CompletedDoubleValue(double complete_value);
  void CompleteQStringValue(const QString& complete_value);

 private:
  using Style = unsigned int;

  void SetConnections();
  void ConnectEditLine();
  void ConnectCoefficientLineActivation();
  void ConnectLCD();
  void ConnectRadioButton();

  void SetStyle(Style style = 0);
  void SetMainWindowStyle(Style style);

  void SetMainWindow();

  QClipboard* clipboard_ = nullptr;
  Multiplier* multiplier_ = nullptr;
  Former* former_ = nullptr;
  StyleMaker* style_maker_ = nullptr;

  double coefficient_ = 1.18;
};

#endif  // CALCULATOR_H
