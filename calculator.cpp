#include "calculator.h"

#include <cmath>

#include <QApplication>
#include <QCheckBox>
#include <QClipboard>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QPalette>
#include <QTextEdit>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      clipboard_(QApplication::clipboard()),
      coefficient_line_(new QLineEdit),
      value_line_(new QLineEdit),
      lcd_(new QLCDNumber(16)) {
  SetCoefficientLine(coefficient_line_);
  SetValueLine(value_line_);
  SetLCDNumber(lcd_);

  QLabel *coefficient_label_ = GetLabel("Coefficient:");
  QLabel *result_label = GetLabel("Result:", 14);
  QCheckBox *coefficient_checkbox = GetCheckBox();

  QHBoxLayout *horizontal_layout = new QHBoxLayout;
  SetHorizontalLayout(horizontal_layout, coefficient_label_,
                      coefficient_checkbox, coefficient_line_);

  QGridLayout *layout = new QGridLayout;
  layout->addLayout(horizontal_layout, 0, 0, 1, 2);
  layout->addWidget(value_line_, 1, 1);
  layout->addWidget(result_label, 2, 0, 2, 2);
  layout->addWidget(lcd_, 4, 1, 1, 2);
  layout->setSpacing(1);

  connect(value_line_, SIGNAL(returnPressed()), value_line_, SLOT(clear()));
  connect(value_line_, SIGNAL(textChanged(QString)),
          SLOT(CalculateResult(QString)));
  connect(this, SIGNAL(CompletedDoubleValue(double)), lcd_,
          SLOT(display(double)));

  setLayout(layout);
}

void Calculator::CalculateResult(const QString &value) {
  double multiply_coefficient = coefficient_line_->text().toDouble();
  double number = value.toDouble();

  complete_value_ = number * multiply_coefficient;

  complete_value_ = round(complete_value_ * 100) / 100;

  QString complete_qstring_value = QString::number(complete_value_);

  clipboard_->setText(complete_qstring_value);

  emit CompletedDoubleValue(complete_value_);
  emit CompleteQStringValue(complete_qstring_value);
}

QLabel *Calculator::GetLabel(const QString &text_label, int label_font) {
  QLabel *label = new QLabel;
  SetLabel(label, text_label, label_font);
  return label;
}

QCheckBox *Calculator::GetCheckBox() {
  QCheckBox *checkbox = new QCheckBox;
  SetCheckBox(checkbox);
  return checkbox;
}

void Calculator::SetCoefficientLine(QLineEdit *coefficient_line) {
  coefficient_line->setAlignment(Qt::AlignRight);
  coefficient_line->setText("1.18");
  coefficient_line->setMaximumSize(75, 25);
  SetPaletteForLineEdit(coefficient_line);
}

void Calculator::SetPaletteForLineEdit(QLineEdit *line) {
  QPalette line_edit_palette;
  line_edit_palette.setColor(QPalette::Base, Qt::black);
  line_edit_palette.setColor(QPalette::Text, Qt::green);

  line->setPalette(line_edit_palette);
}

void Calculator::SetValueLine(QLineEdit *value_line) {
  value_line->setAlignment(Qt::AlignRight);
  SetPaletteForLineEdit(value_line_);
}

void Calculator::SetPaletteForLCD(QLCDNumber *lcd) {
  QPalette lcd_palette;
  lcd_palette.setColor(QPalette::Text, Qt::green);
  lcd_palette.setColor(QPalette::Background, Qt::black);
  lcd_palette.setColor(QPalette::Foreground, Qt::green);

  lcd->setPalette(lcd_palette);
}

void Calculator::SetLCDNumber(QLCDNumber *lcd) {
  lcd->setAutoFillBackground(true);
  lcd->setSegmentStyle(QLCDNumber::Flat);
  lcd->setFrameStyle(QFrame::NoFrame);

  SetPaletteForLCD(lcd);
}

void Calculator::SetLabel(QLabel *label, const QString text_of_label,
                          int label_font) {
  label->setText("<font color='green'>" + text_of_label + "</font>");
  label->setFont(*GetFont(label_font));
}

void Calculator::SetCheckBox(QCheckBox *checkbox) {
  checkbox->setStyleSheet(
      "QCheckBox::indicator:unchecked {"
      "image: url(:/img/checkbox_unchecked.png);"
      "}");
}

void Calculator::SetHorizontalLayout(QHBoxLayout *layout, QLabel *label,
                                     QCheckBox *checkbox,
                                     QLineEdit *line_edit) {
  layout->setSpacing(5);
  layout->addWidget(label);
  layout->addWidget(checkbox);
  layout->addWidget(line_edit);
}

QFont *Calculator::GetFont(int point_size) {
  QFont *font = new QFont;
  font->setPointSize(point_size);

  return font;
}
