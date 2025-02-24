import QtQuick 2.15
import QtQuick.Controls.Fusion 2.15
import QtQuick.Layouts

ColumnLayout
{
    RowLayout
    {
        Text
        {
            text: "Speed"
        }

        TextField
        {
            id: speed
            text: "250"
        }

        Button
        {
            text: "send"
            onClicked:
            {
                if(speedMach.checked)
                {
                    _mainController.fcu.speedMach(parseInt(parseFloat(speed.text) * 100));
                }
                else
                {
                    _mainController.fcu.speedKnot(parseInt(speed.text));
                }
            }
            Component.onCompleted:
            {
                _mainController.fcu.speedKnot(parseInt(speed.text));
            }
        }

        CheckBox
        {
            id: speedMach
            text: "MACH"
            onCheckedChanged:
            {
                if(checked)
                {
                    speed.text = "0.77";
                    _mainController.fcu.speedMach(parseInt(parseFloat(speed.text) * 100));
                }
                else
                {
                    speed.text = "250";
                    _mainController.fcu.speedKnot(parseInt(speed.text));
                }
            }
        }

        CheckBox
        {
            text: "⬤"
            Component.onCompleted: _mainController.fcu.speedDot(checked)
            onCheckedChanged: _mainController.fcu.speedDot(checked)
        }

        CheckBox
        {
            text: "----"
            Component.onCompleted: _mainController.fcu.speedDashed(checked)
            onCheckedChanged: _mainController.fcu.speedDashed(checked)
        }
    }

    RowLayout
    {
        Text
        {
            text: "Heading"
        }

        TextField
        {
            id: heading
            text: "60"
        }

        Button
        {
            text: "send"
            onClicked: _mainController.fcu.heading(parseInt(heading.text))
            Component.onCompleted: _mainController.fcu.heading(parseInt(heading.text))
        }

        CheckBox
        {
            text: "⬤"
            Component.onCompleted: _mainController.fcu.headingDot(checked)
            onCheckedChanged: _mainController.fcu.headingDot(checked)
        }

        CheckBox
        {
            text: "----"
            Component.onCompleted: _mainController.fcu.headingDashed(checked)
            onCheckedChanged: _mainController.fcu.headingDashed(checked)
        }

        CheckBox
        {
            text: "LAT"
            Component.onCompleted: _mainController.fcu.lat(checked)
            onCheckedChanged: _mainController.fcu.lat(checked)
        }

        CheckBox
        {
            text: "TRK"
            onCheckedChanged: _mainController.fcu.track(checked)
            Component.onCompleted: _mainController.fcu.track(checked)
        }
    }

    RowLayout
    {
        Text
        {
            text: "Altitude"
        }

        TextField
        {
            id: altitude
            text: "35000"
        }

        Button
        {
            text: "send"
            onClicked: _mainController.fcu.altitude(parseInt(altitude.text))
            Component.onCompleted: _mainController.fcu.altitude(parseInt(altitude.text))
        }

        CheckBox
        {
            text: "⬤"
            Component.onCompleted: _mainController.fcu.altitudeDot(checked)
            onCheckedChanged: _mainController.fcu.altitudeDot(checked)
        }

        CheckBox
        {
            text: "----"
            Component.onCompleted: _mainController.fcu.altitudeDashed(checked)
            onCheckedChanged: _mainController.fcu.altitudeDashed(checked)
        }
    }

    RowLayout
    {
        Text
        {
            text: "Vertical speed"
        }

        TextField
        {
            id: verticalSpeed
            text: "-3000"
        }

        Button
        {
            text: "send"
            onClicked:
            {
                if(fpa.checked)
                {
                    _mainController.fcu.fpa(parseInt(parseFloat(verticalSpeed.text * 10)))
                }
                else
                {
                    _mainController.fcu.verticalSpeed(parseInt(verticalSpeed.text))
                }
            }
            Component.onCompleted:
            {
                _mainController.fcu.verticalSpeed(parseInt(verticalSpeed.text))
            }
        }

        CheckBox
        {
            text: "----"
            Component.onCompleted: _mainController.fcu.verticalSpeedDashed(checked)
            onCheckedChanged: _mainController.fcu.verticalSpeedDashed(checked)
        }

        CheckBox
        {
            id: fpa
            text: "FPA"
            onCheckedChanged:
            {
                if(checked)
                {
                    verticalSpeed.text = "-3.3"
                    _mainController.fcu.fpa(parseInt(parseFloat(verticalSpeed.text * 10)))
                }
                else
                {
                    verticalSpeed.text = "-3000"
                    _mainController.fcu.verticalSpeed(parseInt(verticalSpeed.text))
                }
            }
        }
    }

    RowLayout
    {
        CheckBox
        {
            text: "AP1"
            Component.onCompleted: _mainController.fcu.ap1(checked)
            onCheckedChanged: _mainController.fcu.ap1(checked)
        }

        CheckBox
        {
            text: "AP2"
            Component.onCompleted: _mainController.fcu.ap2(checked)
            onCheckedChanged: _mainController.fcu.ap2(checked)
        }

        CheckBox
        {
            text: "A/THR"
            Component.onCompleted: _mainController.fcu.athr(checked)
            onCheckedChanged: _mainController.fcu.athr(checked)
        }

        CheckBox
        {
            text: "LOC"
            Component.onCompleted: _mainController.fcu.athr(checked)
            onCheckedChanged: _mainController.fcu.loc(checked)
        }

        CheckBox
        {
            text: "EXPED"
            Component.onCompleted: _mainController.fcu.athr(checked)
            onCheckedChanged: _mainController.fcu.exped(checked)
        }

        CheckBox
        {
            text: "APPR"
            Component.onCompleted: _mainController.fcu.appr(checked)
            onCheckedChanged: _mainController.fcu.appr(checked)
        }
    }

    Loader
    {
        Layout.fillWidth: true
        Layout.fillHeight: true
        source: ""
    }
}
