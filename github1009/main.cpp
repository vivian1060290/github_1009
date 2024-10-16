#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFontDialog>
#include <QFileDialog>
#include <QColorDialog>

class MyApp : public QWidget {
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);

private slots:
    void showColorDialog();
    void changeFont();
    void selectFilePath();

private:
    QLabel *leaderLabel;
};

MyApp::MyApp(QWidget *parent) : QWidget(parent) {

    QTabWidget *tabs = new QTabWidget(this);

    QWidget *leaderTab = new QWidget();
    QWidget *member1Tab = new QWidget();
    QWidget *member2Tab = new QWidget();
    QWidget *member3Tab = new QWidget();  // 新增的組員3頁面

    tabs->addTab(leaderTab, "隊長");
    tabs->addTab(member1Tab, "組員1");
    tabs->addTab(member2Tab, "組員2");
    tabs->addTab(member3Tab, "組員3");

    // 隊長頁面的設定
    leaderLabel = new QLabel("隊長：范芷紜\n組員1：吳承璿\n組員2：胡楨\n組員3：郭品佑", leaderTab);
    leaderLabel->move(0, 0);

     QPushButton *ColorSelectButton = new QPushButton("選擇顏色", member1Tab);
    ColorSelectButton->move(0, 0);
    connect(ColorSelectButton, &QPushButton::clicked, this, &MyApp::showColorDialog);

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

void MyApp::showColorDialog(){
    QColor color = QColorDialog::getColor(Qt::black, this, "選擇字體顏色");
    if (color.isValid()) {
        QString style = QString("color: %1").arg(color.name());
        leaderLabel->setStyleSheet(style);
    }
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
        leaderLabel->setText("檔案路徑: " + fileName);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyApp window;
    window.show();
    return app.exec();
}

#include "main.moc"
