// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
//![0]
ListView {
    width: 480; height: 640

    required model

    delegate: Text {
        required property string type
        required property string size
        text: "Animal: " + type + ", " + size
    }
}
//![0]
