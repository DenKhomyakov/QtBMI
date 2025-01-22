#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

QLineEdit* heightLineEdit;
QLineEdit* weightLineEdit;

void onCalculate();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* widget = new QWidget();
    widget->setWindowTitle("Body Mass Index");
    widget->setMinimumSize(300, 150);
    widget->setWindowIcon(QIcon("BMI.png"));

    QLabel* heightLabel = new QLabel(widget);
    heightLabel->setText("Enter your height (in cm):");
    heightLabel->setMinimumSize(150, 25);

    QLabel* weightLabel = new QLabel(widget);
    weightLabel->setText("Enter your weight (in kg)");
    weightLabel->setMinimumSize(150, 25);

    heightLineEdit = new QLineEdit(widget);
    heightLineEdit->setMinimumSize(150, 25);

    weightLineEdit = new QLineEdit(widget);
    weightLineEdit->setMinimumSize(150, 25);

    QPushButton* calculateButton = new QPushButton("Calculate BMI", widget);
    calculateButton->setMinimumSize(150, 25);
    calculateButton->setIcon(QIcon("Calculate.png"));

    QObject::connect(calculateButton, &QPushButton::clicked, onCalculate);

    QVBoxLayout* layout = new QVBoxLayout();
    widget->setLayout(layout);
    layout->addWidget(heightLabel);
    layout->addWidget(heightLineEdit);
    layout->addWidget(weightLabel);
    layout->addWidget(weightLineEdit);
    layout->addWidget(calculateButton);

    widget->show();
    return a.exec();
}

void onCalculate() {
    double heightInCm = heightLineEdit->text().toDouble();
    double heightInM = heightInCm / 100;

    double weightInKg = weightLineEdit->text().toDouble();

    double calculationResult = weightInKg / (heightInM * heightInM);

    QMessageBox messageBox;
    messageBox.setWindowTitle("Result");
    messageBox.setMinimumSize(250, 100);
    messageBox.setWindowIcon(QIcon("ResultWindow.png"));
    messageBox.setText("Your BMI: " + QString::number(calculationResult, 'f', 2));  // Форматируем вывод до 2 знаков после запятой

    messageBox.exec();
}
