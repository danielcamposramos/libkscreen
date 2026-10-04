/*
 *  SPDX-FileCopyrightText: 2021 Méven Car <meven.car@enioka.com>
 *
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 */
#include "waylandoutputdevicemode.h"

#include <QGuiApplication>

using namespace KScreen;

static QString nextId()
{
    static uint id = 1;
    return QString::number(id++);
}

WaylandOutputDeviceMode::WaylandOutputDeviceMode(struct ::kde_output_device_mode_v2 *object)
    : QtWayland::kde_output_device_mode_v2(object)
    , m_id(nextId())
{
}

WaylandOutputDeviceMode::~WaylandOutputDeviceMode()
{
    if (qGuiApp) {
        kde_output_device_mode_v2_destroy(object());
    }
}

void WaylandOutputDeviceMode::kde_output_device_mode_v2_size(int32_t width, int32_t height)
{
    m_size = QSize(width, height);
}

void WaylandOutputDeviceMode::kde_output_device_mode_v2_refresh(int32_t refresh)
{
    m_refreshRate = refresh / 1000.0;
}

void WaylandOutputDeviceMode::kde_output_device_mode_v2_preferred()
{
    m_preferred = true;
}

void WaylandOutputDeviceMode::kde_output_device_mode_v2_removed()
{
    Q_EMIT removed();
}

void WaylandOutputDeviceMode::kde_output_device_mode_v2_flags(uint32_t flags)
{
    m_flags = {};
    if (flags & 0x40) {
        m_flags |= ModeInfo::Flag::Stereo3DAnaglyphModern;
    }
    if (flags & 0x80) {
        m_flags |= ModeInfo::Flag::Stereo3DAnaglyphCrt;
    }
    if (flags & 0x100) {
        m_flags |= ModeInfo::Flag::Stereo3DRowsLeftFirst;
    }
    if (flags & 0x200) {
        m_flags |= ModeInfo::Flag::Stereo3DRowsRightFirst;
    }
    if (flags & 0x400) {
        m_flags |= ModeInfo::Flag::Stereo3DColumnsLeftFirst;
    }
    if (flags & 0x800) {
        m_flags |= ModeInfo::Flag::Stereo3DColumnsRightFirst;
    }
    if (flags & 0x1000) {
        m_flags |= ModeInfo::Flag::Stereo3DCheckerboardLeftFirst;
    }
    if (flags & 0x2000) {
        m_flags |= ModeInfo::Flag::Stereo3DCheckerboardRightFirst;
    }
    if (flags & 0x4000) {
        m_flags |= ModeInfo::Flag::VirtualStereo;
    }
    if (flags & 0x40000) {
        m_flags |= ModeInfo::Flag::Stereo3DSequentialLeftFirst;
    }
    if (flags & 0x80000) {
        m_flags |= ModeInfo::Flag::Stereo3DSequentialRightFirst;
    }

    if (flags & KDE_OUTPUT_DEVICE_MODE_V2_FLAGS_CUSTOM) {
        m_flags |= ModeInfo::Flag::Custom;
    }
    if (flags & KDE_OUTPUT_DEVICE_MODE_V2_FLAGS_REDUCED_BLANKING) {
        m_flags |= ModeInfo::Flag::ReducedBlanking;
    }
    // stereo_side_by_side_half, stereo_top_and_bottom, stereo_frame_packing and
    // stereo_side_by_side_full (plasma-wayland-protocols, stereo3d branch)
    if (flags & 0x4) {
        m_flags |= ModeInfo::Flag::Stereo3DSideBySideHalf;
    }
    if (flags & 0x8) {
        m_flags |= ModeInfo::Flag::Stereo3DTopAndBottom;
    }
    if (flags & 0x10) {
        m_flags |= ModeInfo::Flag::Stereo3DFramePacking;
    }
    if (flags & 0x20) {
        m_flags |= ModeInfo::Flag::Stereo3DSideBySideFull;
    }
}

QString WaylandOutputDeviceMode::id() const
{
    return m_id;
}

float WaylandOutputDeviceMode::refreshRate() const
{
    return m_refreshRate;
}

QSize WaylandOutputDeviceMode::size() const
{
    return m_size;
}

bool WaylandOutputDeviceMode::preferred() const
{
    return m_preferred;
}

ModeInfo::Flags WaylandOutputDeviceMode::flags() const
{
    return m_flags;
}

WaylandOutputDeviceMode *WaylandOutputDeviceMode::get(struct ::kde_output_device_mode_v2 *object)
{
    auto mode = QtWayland::kde_output_device_mode_v2::fromObject(object);
    return static_cast<WaylandOutputDeviceMode *>(mode);
}

#include "moc_waylandoutputdevicemode.cpp"
