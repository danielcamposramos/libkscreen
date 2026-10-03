/*
 *  SPDX-FileCopyrightText: 2012 Alejandro Fiestas Olivares <afiestas@kde.org>
 *  SPDX-FileCopyrightText: 2014 Daniel Vrátil <dvratil@redhat.com>
 *
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "mode.h"

using namespace KScreen;
class Q_DECL_HIDDEN Mode::Private
{
public:
    Private()
        : rate(0)
    {
    }

    Private(const Private &other)
        : id(other.id)
        , name(other.name)
        , size(other.size)
        , rate(other.rate)
        , stereo3D(other.stereo3D)
        , virtualStereo(other.virtualStereo)
    {
    }

    QString id;
    QString name;
    QSize size;
    float rate;
    Mode::Stereo3D stereo3D = Mode::Stereo3D::None;
    bool virtualStereo = false;
};

Mode::Mode()
    : QObject(nullptr)
    , d(new Private())
{
}

Mode::Mode(Mode::Private *dd)
    : QObject()
    , d(dd)
{
}

Mode::~Mode()
{
    delete d;
}

ModePtr Mode::clone() const
{
    return ModePtr(new Mode(new Private(*d)));
}

const QString Mode::id() const
{
    return d->id;
}

void Mode::setId(const QString &id)
{
    if (d->id == id) {
        return;
    }

    d->id = id;

    Q_EMIT modeChanged();
}

QString Mode::name() const
{
    return d->name;
}

void Mode::setName(const QString &name)
{
    if (d->name == name) {
        return;
    }

    d->name = name;

    Q_EMIT modeChanged();
}

QSize Mode::size() const
{
    return d->size;
}

void Mode::setSize(const QSize &size)
{
    if (d->size == size) {
        return;
    }

    d->size = size;

    Q_EMIT modeChanged();
}

float Mode::refreshRate() const
{
    return d->rate;
}

void Mode::setRefreshRate(float refresh)
{
    if (qFuzzyCompare(d->rate, refresh)) {
        return;
    }

    d->rate = refresh;

    Q_EMIT modeChanged();
}

bool Mode::virtualStereo() const
{
    return d->virtualStereo;
}

void Mode::setVirtualStereo(bool value)
{
    if (d->virtualStereo != value) {
        d->virtualStereo = value;
        Q_EMIT modeChanged();
    }
}

Mode::Stereo3D Mode::stereo3D() const
{
    return d->stereo3D;
}

void Mode::setStereo3D(Stereo3D stereo3D)
{
    if (d->stereo3D == stereo3D) {
        return;
    }

    d->stereo3D = stereo3D;

    Q_EMIT modeChanged();
}

bool Mode::operator==(const Mode &other) const
{
    return d->size == other.d->size && d->rate == other.d->rate && d->stereo3D == other.d->stereo3D && d->virtualStereo == other.d->virtualStereo;
}

QDebug operator<<(QDebug dbg, const KScreen::ModePtr &mode)
{
    if (mode) {
        dbg << "KScreen::Mode(Id:" << mode->id() << ", Size:" << mode->size() << "@" << mode->refreshRate() << ", 3D:" << mode->stereo3D() << ")";
    } else {
        dbg << "KScreen::Mode(NULL)";
    }
    return dbg;
}

#include "moc_mode.cpp"
