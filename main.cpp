#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("example");
    window->resize(300, 300);

    QTabWidget *tabWidget = new QTabWidget;

    // 第一個標籤頁 (隊長)
    QWidget *tab1 = new QWidget;
    QVBoxLayout *layout1 = new QVBoxLayout;

    // 隊長頁面的標籤
    QLabel *leaderLabel = new QLabel("隊長");
    layout1->addWidget(leaderLabel); // 添加隊長標籤

    // 添加組員標籤
    for (int i = 1; i <= 3; ++i) {
        QLabel *memberLabel = new QLabel(QString("組員%1").arg(i)); // 創建組員標籤
        layout1->addWidget(memberLabel); // 將組員標籤添加到佈局中
    }

    tab1->setLayout(layout1); // 將佈局設置到標籤頁
    tabWidget->addTab(tab1, "隊長"); // 將標籤頁添加到標籤控件中，標題為"隊長"

    // 組員一和組員二標籤頁
    for (int i = 1; i <= 2; ++i) {
        QWidget *tab = new QWidget; // 創建其他標籤頁
        QVBoxLayout *layout = new QVBoxLayout; // 創建垂直佈局
        layout->addWidget(new QLabel("其他信息")); // 添加標籤顯示"其他信息"
        tab->setLayout(layout); // 將佈局設置到標籤頁
        tabWidget->addTab(tab, QString("組員%1").arg(i)); // 將標籤頁添加到標籤控件中，標題為"組員1", "組員2"
    }

    // 組員三標籤頁 (按鈕改隊長頁文字)
    QWidget *tab3 = new QWidget;
    QVBoxLayout *layout3 = new QVBoxLayout;

    // 創建按鈕
    QPushButton *fileButton = new QPushButton("選擇檔案並修改隊長標籤");
    layout3->addWidget(fileButton);

    // 設置按鈕點擊事件來打開檔案對話框並修改隊長標籤
    QObject::connect(fileButton, &QPushButton::clicked, [&]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "選擇檔案");
        if (!filePath.isEmpty()) {
            leaderLabel->setText(filePath); // 將隊長標籤改為檔案路徑
        }
    });

    tab3->setLayout(layout3);
    tabWidget->addTab(tab3, "組員3"); // 將組員三頁面添加到標籤控件中

    // 將標籤頁添加到主窗口
    QVBoxLayout *mainLayout = new QVBoxLayout; // 創建主佈局
    mainLayout->addWidget(tabWidget); // 將標籤控件添加到主佈局
    window->setLayout(mainLayout); // 將主佈局設置到主窗口

    window->show(); // 顯示主窗口
    return app.exec(); // 開始應用程式的事件循環
}
