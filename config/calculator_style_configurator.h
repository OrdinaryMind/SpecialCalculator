#ifndef CALCULATOR_STYLE_CONFIGURATOR_H
#define CALCULATOR_STYLE_CONFIGURATOR_H

#include <QAction>
#include <QCheckBox>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

class CaclulatorStyleConfigurator {
 public:
  enum AppTheme { kProgrammer, kMoto, kOffice };

  CaclulatorStyleConfigurator();

  void SetStyle(AppTheme theme);

  QLineEdit *GetValueLine();
  QLineEdit *GetCoefficientLine();
  QLCDNumber *GetLCDNumber();
  QCheckBox *GetCoefficientCheckBox();
  QGridLayout *GetLayout();

 private:
  void SetCoefficientLine(QLineEdit *line, AppTheme theme = kProgrammer);
  void SetValueLine(QLineEdit *line, AppTheme theme = kProgrammer);
  void SetLineEditStyle(QLineEdit *line, AppTheme theme = kProgrammer);
  void SetLineStyleSheet(QLineEdit *line, const QString &border_color,
                         const QString &background,
                         const QString &selection_color,
                         const QString &text_color, const QString &font_weight);

  void SetLCDNumber(QLCDNumber *lcd, AppTheme theme = kProgrammer);
  void SetLCDStyle(QLCDNumber *lcd, AppTheme theme = kProgrammer);
  void SetLCDStyleSheet(QLCDNumber *lcd, const QString &border_color,
                        const QString &background, const QString &value_color);

  void SetLabel(QLabel *label, const QString &text_of_label,
                int label_size = 10, AppTheme theme = kProgrammer);
  void SetLabelStyleSheet(QLabel *label, const QString &text_of_label,
                          const QString &text_color,
                          const QString &background_format,
                          const QString &background);

  void SetCheckBox(QCheckBox *checkbox, AppTheme theme = kProgrammer);

  void SetGridLayout(QGridLayout *grid_layout, QLineEdit *line_edit,
                     QLabel *number_label, QLabel *result_label,
                     QLCDNumber *lcd);

  void SetHorizontalLayout(QHBoxLayout *layout, QLabel *label,
                           QCheckBox *checkbox, QLineEdit *line_edit);

  QLineEdit *coefficient_line_ = nullptr;
  QLineEdit *value_line_ = nullptr;
  QLCDNumber *lcd_ = nullptr;
  QLabel *coefficient_label_ = nullptr;
  QLabel *number_label_ = nullptr;

  QLabel *result_label_ = nullptr;
  QFont GetFont(int point_size);
  QCheckBox *coefficient_checkbox_ = nullptr;
  QGridLayout *grid_layout_ = nullptr;
  QHBoxLayout *horizontal_layout_ = nullptr;
};

#endif  // CALCULATOR_STYLE_CONFIGURATOR_H