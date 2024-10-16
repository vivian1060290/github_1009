#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>

class MyApp : public QWidget {
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);

private slots:
    void changeColor();
    void changeFont();
    void selectFile();

private:
    QLabel *leaderLabel;  // 用來顯示隊長與組員的標籤
};

MyApp::MyApp(QWidget *parent) : QWidget(parent) {
    // 創建標籤頁
    QTabWidget *tabs = new QTabWidget(this);

    QWidget *leaderTab = new QWidget();
    QWidget *member1Tab = new QWidget();
    QWidget *member2Tab = new QWidget();
    QWidget *member3Tab = new QWidget();

    tabs->addTab(leaderTab, "隊長");
    tabs->addTab(member1Tab, "組員1");
    tabs->addTab(member2Tab, "組員2");
    tabs->addTab(member3Tab, "組員3");

    // 隊長的 Label 顯示隊長和所有組員的資訊
    leaderLabel = new QLabel("隊長 \n組員1 \n組員2 \n組員3: ", leaderTab);
    leaderLabel->move(50, 50);

    // 組員2 - 改變文字字體的按鈕
    QPushButton *fontButton = new QPushButton("改變文字樣式", member2Tab);
    fontButton->move(0, 0);
    connect(fontButton, &QPushButton::clicked, this, &MyApp::changeFont);  // 按鈕連接到槽函數

    // 主視窗布局
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabs);
    setLayout(layout);

    setWindowTitle("Qt Tabs Example - 隊長與組員");
    setGeometry(300, 300, 400, 300); // 設定視窗初始大小
}

void MyApp::changeColor() {
    QColor color = QColorDialog::getColor(Qt::black, this, "選擇顏色");
    if (color.isValid()) {
        QPalette palette = leaderLabel->palette();
        palette.setColor(QPalette::WindowText, color);
        leaderLabel->setPalette(palette);
    }
}

void MyApp::changeFont() {
    bool ok;
    // 打開字體選擇對話框，讓使用者選擇字體
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        // 如果用戶按下確定，則應用所選的字體到隊長與組員標籤
        leaderLabel->setFont(font);
    }
}

void MyApp::selectFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "選擇檔案", "", "所有檔案 (*.*);;文本檔案 (*.txt)");
    if (!fileName.isEmpty()) {
        // 當檔案被選擇時，更新隊長的標籤以顯示檔案路徑
        leaderLabel->setText("隊長\n檔案路徑: " + fileName + "\n組員1: \n組員2: \n組員3: ");
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyApp window;
    window.show();
    return app.exec();
}

#include "main.moc"
