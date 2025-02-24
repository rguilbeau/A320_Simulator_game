import QtQuick 2.15
import QtQuick.Controls.Fusion 2.15
import QtQuick.Layouts

ApplicationWindow
{
    visible: true
    width: 800
    height: 800
    title: "A320 Cockpit"

    ColumnLayout
    {
        Text
        {
            font.pixelSize: 13
            color: _mainController.connected ? "green" : "red"
            text: _mainController.connected ? "CONNECTED" : "DISCONNECTED"
        }

        Loader
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            source: "qml/Fcu.qml"
        }
    }


}
