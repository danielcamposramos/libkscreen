/*
 *  SPDX-FileCopyrightText: 2012 Alejandro Fiestas Olivares <afiestas@kde.org>
 *  SPDX-FileCopyrightText: 2014 Daniel Vrátil <dvratil@redhat.com>
 *
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

#include "kscreen_export.h"
#include "types.h"

#include <QDebug>
#include <QMetaType>
#include <QObject>
#include <QSize>

namespace KScreen
{
class KSCREEN_EXPORT Mode : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY modeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY modeChanged)
    Q_PROPERTY(QSize size READ size WRITE setSize NOTIFY modeChanged)
    Q_PROPERTY(float refreshRate READ refreshRate WRITE setRefreshRate NOTIFY modeChanged)
    Q_PROPERTY(Stereo3D stereo3D READ stereo3D WRITE setStereo3D NOTIFY modeChanged)

public:
    /**
     * The HDMI 3D structure the mode is sent in: a 3D mode repeats a 2D mode's size and
     * refresh rate, and choosing it turns the display's 3D on. Never chosen automatically.
     */
    enum class Stereo3D {
        None,
        SideBySideHalf,
        TopAndBottom,
    };
    Q_ENUM(Stereo3D)

    explicit Mode();
    ~Mode() override;

    ModePtr clone() const;

    const QString id() const;
    void setId(const QString &id);

    QString name() const;
    void setName(const QString &name);

    QSize size() const;
    void setSize(const QSize &size);

    float refreshRate() const;
    void setRefreshRate(float refresh);

    Stereo3D stereo3D() const;
    void setStereo3D(Stereo3D stereo3D);

    bool operator==(const Mode &other) const;

Q_SIGNALS:
    void modeChanged();

private:
    Q_DISABLE_COPY(Mode)

    class Private;
    Private *const d;

    Mode(Private *dd);
};

} // KSCreen namespace

KSCREEN_EXPORT QDebug operator<<(QDebug dbg, const KScreen::ModePtr &mode);
