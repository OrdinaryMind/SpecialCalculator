#include "line_edit_styler.h"

#include <QLineEdit>

void LineEditStyler::SetCoefficientLine(QLineEdit *line_edit,
                                        config::Theme theme) {
  SetLineFeature(line_edit, true, 75, 25);
  SetLineEditStyle(line_edit, theme);
}

void LineEditStyler::SetValueLine(QLineEdit *line_edit, config::Theme theme) {
  SetLineFeature(line_edit, false, 200, 25);
  SetLineEditStyle(line_edit, theme);
}

void LineEditStyler::SetLineFeature(QLineEdit *line_edit, bool disable_state,
                                    int w, int h) {
  line_edit->setAlignment(Qt::AlignRight);
  line_edit->setDisabled(disable_state);
  line_edit->setFixedSize(w, h);
}

void LineEditStyler::SetLineEditStyle(QLineEdit *line_edit,
                                      config::Theme theme) {
  switch (theme) {
    case config::kProgrammer:
      SetLineStyleSheet(line_edit, "green", "black");
      break;
    case config::kOffice:
      SetLineStyleSheet(line_edit, "black", "#606060", "normal");
      break;
    case config::kMoto:
      SetLineStyleSheet(line_edit, "#000099", "white");
      break;
  }
}

void LineEditStyler::SetLineStyleSheet(QLineEdit *line_edit,
                                       const QString &color,
                                       const QString &background,
                                       const QString &font_weight) {
  QString style_sheet =
      "QLineEdit {"
      "border: 2px solid %1;"
      "border-radius: 7px;"
      "background: %2;"
      "selection-background-color: #40494D;"
      "color: %4;"
      "font-weight: %5;}";

  line_edit->setStyleSheet(
      style_sheet.arg(color, background, color, font_weight));
}