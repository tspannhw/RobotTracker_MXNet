#ifndef VIDEOWRAPPER_H
#define VIDEOWRAPPER_H

#include <QObject>
#include <QAbstractVideoSurface>
#include <QVideoFrame>
#include <QVideoSurfaceFormat>
#include <QCamera>
#include <QDateTime>
#include "private/qvideoframe_p.h"

class VideoWrapper: public QAbstractVideoSurface
{
    Q_OBJECT

public:
    Q_PROPERTY(QObject *source READ get_source WRITE set_source NOTIFY sourceChanged)
    Q_PROPERTY(QAbstractVideoSurface *videoSurface READ get_videoSurface WRITE set_videoSurface)

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle
            ) const;

    bool present(const QVideoFrame &frame);

    virtual bool start(const QVideoSurfaceFormat &format);
    virtual void stop();

    QAbstractVideoSurface *get_videoSurface() const;
    void set_videoSurface(QAbstractVideoSurface *m);

    QObject *get_source();
    void set_source(QObject *qsrc);

signals:
    void sourceChanged();

private:
    QObject *m_source = nullptr;
    QAbstractVideoSurface *surf = nullptr;
    QVideoSurfaceFormat m_format;
};

#endif // VIDEOWRAPPER_H
