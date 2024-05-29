#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();

private:
    QLineEdit *display;
    QGridLayout *mainLayout;
    QList<QPushButton*> digitButtons;
    QPushButton *createButton(const QString &text, const char *member);

    double sumInMemory;
    double sumSoFar;
    QString pendingOperator;
    bool waitingForOperand;

    bool calculate(double rightOperand);
    void clearAll();
};

#endif
