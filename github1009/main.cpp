#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("example");
    window->resize(300, 300);

    QTabWidget *tabWidget = new QTabWidget;

    // 第一個標籤頁
    QWidget *tab1 = new QWidget;
    QVBoxLayout *layout1 = new QVBoxLayout;

    // 對整個標籤頁設置字體顏色
    tab1->setStyleSheet("color: blue;"); // 設置標籤頁的字體顏色為藍色
    layout1->addWidget(new QLabel("隊長")); // 添加隊長標籤

    // 添加組員標籤
    for (int i = 1; i <= 3; ++i) {
        QLabel *memberLabel = new QLabel(QString("組員%1").arg(i)); // 創建組員標籤
        layout1->addWidget(memberLabel); // 將組員標籤添加到佈局中
    }

    tab1->setLayout(layout1); // 將佈局設置到標籤頁
    tabWidget->addTab(tab1, "隊長"); // 將標籤頁添加到標籤控件中，標題為"隊長"

    // 其他標籤頁
    for (int i = 1; i <= 3; ++i) {
        QWidget *tab = new QWidget; // 創建其他標籤頁
        QVBoxLayout *layout = new QVBoxLayout; // 創建垂直佈局
        layout->addWidget(new QLabel("其他信息")); // 添加標籤顯示"其他信息"
        tab->setLayout(layout); // 將佈局設置到標籤頁
        tabWidget->addTab(tab, QString("組員%1").arg(i)); // 將標籤頁添加到標籤控件中，標題為"組員1", "組員2", "組員3"
    }

    // 將標籤頁添加到主窗口
    QVBoxLayout *mainLayout = new QVBoxLayout; // 創建主佈局
    mainLayout->addWidget(tabWidget); // 將標籤控件添加到主佈局
    window->setLayout(mainLayout); // 將主佈局設置到主窗口

    window->show(); // 顯示主窗口
    return app.exec(); // 開始應用程式的事件循環
}
