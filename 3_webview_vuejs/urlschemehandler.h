#ifndef URLSCHEMEHANDLER_H
#define URLSCHEMEHANDLER_H

#include <QWebEngineUrlSchemeHandler>
#include <QWebEngineUrlRequestJob>
#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QBuffer>

class LocalFileSchemeHandler : public QWebEngineUrlSchemeHandler
{
    Q_OBJECT

public:
    explicit LocalFileSchemeHandler(const QString &basePath, QObject *parent = nullptr)
        : QWebEngineUrlSchemeHandler(parent), m_basePath(basePath) {}

    void requestStarted(QWebEngineUrlRequestJob *job) override
    {
        QString path = job->requestUrl().path();
        
        // Remove leading slash and construct full file path
        if (path.startsWith("/")) {
            path = path.mid(1);
        }
        
        QString fullPath = m_basePath + "/" + path;
        
        qDebug() << "Loading resource:" << fullPath;
        
        QFile *file = new QFile(fullPath, job);
        
        if (!file->open(QIODevice::ReadOnly)) {
            qWarning() << "Failed to open file:" << fullPath;
            job->fail(QWebEngineUrlRequestJob::RequestFailed);
            delete file;
            return;
        }
        
        // Determine MIME type
        QMimeDatabase mimeDb;
        QMimeType mimeType = mimeDb.mimeTypeForFile(fullPath);
        QString mimeTypeName = mimeType.name();
        
        // Force correct MIME types for JavaScript modules
        if (fullPath.endsWith(".js") || fullPath.endsWith(".mjs")) {
            mimeTypeName = "text/javascript";
        } else if (fullPath.endsWith(".css")) {
            mimeTypeName = "text/css";
        } else if (fullPath.endsWith(".html")) {
            mimeTypeName = "text/html";
        }
        
        qDebug() << "MIME type:" << mimeTypeName;
        
        job->reply(mimeTypeName.toUtf8(), file);
    }

private:
    QString m_basePath;
};

#endif // URLSCHEMEHANDLER_H