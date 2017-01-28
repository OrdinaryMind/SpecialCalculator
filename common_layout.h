#ifndef COMMONLAYOUT_H
#define COMMONLAYOUT_H

class QGridLayout;
class QHBoxLayout;
class QLineEdit;
class QLabel;
class QLCDNumber;
class QCheckBox;

class CommonLayout {
 public:
  CommonLayout();

  QGridLayout* GetLayout();

  void SetGridLayout(QLineEdit* line_edit, QLabel* label, QLCDNumber* lcd);

  void SetHorizontalLayout(QLabel* label, QCheckBox* checkbox,
                           QLineEdit* line_edit);

 private:
  QGridLayout* grid_layout_;
  QHBoxLayout* horizontal_layout_;
};

#endif  // COMMONLAYOUT_H