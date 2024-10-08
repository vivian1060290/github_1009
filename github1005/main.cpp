#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFontDialog>
#include <QFileDialog>

class MyApp : public QWidget {
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);

private slots:
    void changeFont();
    void selectFilePath();

private:
    QLabel *leaderLabel;
};

MyApp::MyApp(QWidget *parent) : QWidget(parent) {

    QTabWidget *tabs = new QTabWidget(this);

    QWidget *leaderTab = new QWidget();
    QWidget *memberTab = new QWidget();      // 為"組員"創建一個新的頁面
    QWidget *member2Tab = new QWidget();     // 為"組員2"創建一個新的頁面
    QWidget *member3Tab = new QWidget();     // 新增的組員3頁面

    tabs->addTab(leaderTab, "隊長");
    tabs->addTab(memberTab, "組員");         // 正確使用新的 memberTab
    tabs->addTab(member2Tab, "組員2");       // 正確使用新的 member2Tab
    tabs->addTab(member3Tab, "組員3");

    // 隊長頁面的設定
    leaderLabel = new QLabel("隊長\n組員1\n組員2\n組員3\n", leaderTab);
    leaderLabel->move(0, 0);

    // 組員2頁面的按鈕
    QPushButton *fontButton = new QPushButton("改變文字樣式", member2Tab);
    fontButton->move(0, 0);
    connect(fontButton, &QPushButton::clicked, this, &MyApp::changeFont);

    // 組員3頁面的按鈕
    QPushButton *selectFileButton = new QPushButton("選擇檔案", member3Tab);
    selectFileButton->move(0, 0);
    connect(selectFileButton, &QPushButton::clicked, this, &MyApp::selectFilePath);

    // 設置布局
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabs);
    setLayout(layout);

    // 設置視窗的標題與大小
    setWindowTitle("Qt Tabs Example");
    setGeometry(500, 500, 500, 500);
}

void MyApp::changeFont() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        leaderLabel->setFont(font);
    }
}

void MyApp::selectFilePath() {
    QString fileName = QFileDialog::getOpenFileName(this, "選擇檔案", "", "All Files (*)");
    if (!fileName.isEmpty()) {
        // 將選擇的檔案路徑顯示在隊長頁面的標籤上
        leaderLabel->setText( fileName);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyApp window;
    window.show();
    return app.exec();
}

#include "main.moc"
