#include "calculator.h"

#include <cmath>

#include <QApplication>
#include <QCheckBox>
#include <QClipboard>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      configurator_(new CaclulatorStyleConfigurator) {
  configurator_->SetStyle(CaclulatorStyleConfigurator::kProgrammer);

  QGridLayout *layout = configurator_->GetLayout();

  QLineEdit *value_line = configurator_->GetValueLine();
  QLCDNumber *lcd = configurator_->GetLCDNumber();
  QLineEdit *coefficient_line = configurator_->GetCoefficientLine();
  QCheckBox *coef_checkbox = configurator_->GetCoefficientCheckBox();

  connect(value_line, SIGNAL(returnPressed()), value_line, SLOT(clear()));
  connect(value_line, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd,
          SLOT(display(double)));
  connect(coef_checkbox, SIGNAL(clicked(bool)), coefficient_line,
          SLOT(setEnabled(bool)));
  connect(coefficient_line, SIGNAL(textChanged(QString)),
          SLOT(SetCoefficient(QString)));

  SetMainWindow(layout);
}

void Calculator::SetConnections() {}

void Calculator::ConnectWidgets() {}

void Calculator::CalculateResult(const QString &value) {
  multipyer_.SetCoefficient(coefficient_);
  multipyer_.SetNumber(value);

  clipboard_->setText(multipyer_.GetCompleteStringValue());

  emit CompletedDoubleValue(multipyer_.GetCompleteDoubleValue());
}

void Calculator::SetCoefficient(const QString &coefficient) {
  coefficient_ = coefficient.toDouble();
}

void Calculator::SetMainWindow(QGridLayout *layout) {
  setLayout(layout);
  setFixedSize(210, 160);
  setWindowTitle("Calculator");
  setStyleSheet("background-color:black;");
}
