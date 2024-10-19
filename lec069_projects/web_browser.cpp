// SimpleWebBrowser.cpp
#include <QApplication>
#include <QWebEngineView>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>

class SimpleBrowser : public QWidget {
    Q_OBJECT

public:
    SimpleBrowser() {
        // Set up the layout
        QVBoxLayout *layout = new QVBoxLayout(this);
        
        // Create URL bar and add it to the layout
        urlBar = new QLineEdit();
        layout->addWidget(urlBar);

        // Create "Go" button and add it to the layout
        QPushButton *goButton = new QPushButton("Go");
        layout->addWidget(goButton);

        // Create web view and add it to the layout
        webView = new QWebEngineView();
        layout->addWidget(webView);

        // Connect signals and slots
        connect(goButton, &QPushButton::clicked, this, &SimpleBrowser::navigateToUrl);
        connect(urlBar, &QLineEdit::returnPressed, this, &SimpleBrowser::navigateToUrl);
    }

private slots:
    void navigateToUrl() {
        QString url = urlBar->text();
        if (!url.startsWith("http://") && !url.startsWith("https://")) {
            url = "http://" + url;
        }
        webView->setUrl(QUrl(url));
    }

private:
    QLineEdit *urlBar;
    QWebEngineView *webView;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SimpleBrowser browser;
    browser.setWindowTitle("Simple Web Browser");
    browser.resize(800, 600);
    browser.show();
    return app.exec();
}

#include "SimpleWebBrowser.moc"
