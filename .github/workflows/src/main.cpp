#include <QApplication>
#include <QComboBox>
#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QStringList>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt Sample");
    window.resize(420, 320);

    auto *layout = new QVBoxLayout(&window);
    layout->setContentsMargins(24, 24, 24, 24);
    layout->setSpacing(12);

    auto *title = new QLabel("Qt GUI sample");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 18px; font-weight: bold;");

    auto *body = new QLabel("This window is created with Qt Widgets and C++.");
    body->setWordWrap(true);
    body->setAlignment(Qt::AlignCenter);

    QStringList branchChoices = {"main", "develop", "release/1.0.0"};

    auto *targetLabel = new QLabel("比較対象ブランチ名");
    auto *targetBranch = new QComboBox;
    targetBranch->addItems(branchChoices);

    auto *sourceLabel = new QLabel("比較元ブランチ名");
    auto *sourceBranch = new QComboBox;
    sourceBranch->addItems(branchChoices);

    auto *targetFolderLabel = new QLabel("比較対象ファイル保存先フォルダ");
    auto *targetFolderInput = new QLineEdit(QDir::currentPath());
    targetFolderInput->setPlaceholderText("例: C:/work/downloads/target");

    auto *sourceFolderLabel = new QLabel("比較元ファイル保存先フォルダ");
    auto *sourceFolderInput = new QLineEdit(QDir::currentPath());
    sourceFolderInput->setPlaceholderText("例: C:/work/downloads/source");

    auto *button = new QPushButton("Say hello");

    QObject::connect(button, &QPushButton::clicked,
                     [&window, targetBranch, sourceBranch, targetFolderInput, sourceFolderInput]() {
                         auto message = QString("比較対象: %1\n保存先: %2\n\n比較元: %3\n保存先: %4")
                                            .arg(targetBranch->currentText(),
                                                 targetFolderInput->text(),
                                                 sourceBranch->currentText(),
                                                 sourceFolderInput->text());
                         QMessageBox::information(&window, "Qt Sample", message);
                     });

    layout->addWidget(title);
    layout->addWidget(body);
    layout->addWidget(targetLabel);
    layout->addWidget(targetBranch);
    layout->addWidget(targetFolderLabel);
    layout->addWidget(targetFolderInput);
    layout->addWidget(sourceLabel);
    layout->addWidget(sourceBranch);
    layout->addWidget(sourceFolderLabel);
    layout->addWidget(sourceFolderInput);
    layout->addStretch();
    layout->addWidget(button, 0, Qt::AlignCenter);

    window.show();
    return app.exec();
}


