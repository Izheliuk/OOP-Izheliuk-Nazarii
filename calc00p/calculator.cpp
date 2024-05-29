#include "calculator.h"
#include <QtWidgets>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), sumInMemory(0.0), sumSoFar(0.0), waitingForOperand(true)
{
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 4);

    QStringList digitButtonsTexts = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (int i = 0; i < digitButtonsTexts.size(); ++i) {
        digitButtons.append(createButton(digitButtonsTexts[i], SLOT(digitClicked())));
    }

    QStringList operatorButtonsTexts = {"/", "*", "-", "+"};
    for (const QString &text : operatorButtonsTexts) {
        mainLayout->addWidget(createButton(text, SLOT(operatorClicked())), operatorButtonsTexts.indexOf(text) + 1, 3);
    }

    mainLayout->addWidget(createButton("C", SLOT(clearClicked())), 4, 1);
    mainLayout->addWidget(createButton("=", SLOT(equalClicked())), 4, 2);

    for (int i = 1; i < digitButtons.size(); ++i) {
        int row = ((9 - i) / 3) + 1;
        int column = (i - 1) % 3;
        mainLayout->addWidget(digitButtons[i], row, column);
    }
    mainLayout->addWidget(digitButtons[0], 4, 0);

    setLayout(mainLayout);
    setWindowTitle("Calculator");
}

QPushButton *Calculator::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    int digitValue = clickedButton->text().toInt();

    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

void Calculator::operatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString clickedOperator = clickedButton->text();

    double operand = display->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        if (!calculate(operand)) {
            clearAll();
            display->setText("Error");
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

    pendingOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        if (!calculate(operand)) {
            clearAll();
            display->setText("Error");
            return;
        }
        pendingOperator.clear();
    } else {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    waitingForOperand = true;
}

void Calculator::clearClicked()
{
    if (waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

bool Calculator::calculate(double rightOperand)
{
    if (pendingOperator == "+")
        sumSoFar += rightOperand;
    else if (pendingOperator == "-")
        sumSoFar -= rightOperand;
    else if (pendingOperator == "*")
        sumSoFar *= rightOperand;
    else if (pendingOperator == "/") {
        if (rightOperand == 0.0)
            return false;
        sumSoFar /= rightOperand;
    }
    return true;
}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    pendingOperator.clear();
    waitingForOperand = true;
}
