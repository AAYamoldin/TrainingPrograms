import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // Слой с TaxtField`ами и Button для занесения записей в базу данных
    RowLayout {
        id: rowLayout
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 5

        spacing: 10

        Text {text: qsTr("Имя")}
        TextField {id: fnameField}
        Text {text: qsTr("Фамилия")}
        TextField { id: snameField}
        Text {text: qsTr("НИК")}
        TextField {id: nikField}

        Button {
            text: qsTr("Добавить")

            // Вносим новую запись в базу данных
            onClicked: {
                database.inserIntoTable(fnameField.text , snameField.text, nikField.text)
                myModel.updateModel() // И обновляем модель данных с новой записью
            }
        }
    }

    TableView {
        id: tableView
        anchors.top: rowLayout.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5

        TableViewColumn {
            role: "fname"
            title: "Имя"
        }
        TableViewColumn {
            role: "sname"
            title: "Фамилия"
        }
        TableViewColumn {
            role: "nik"
            title: "НИК"
        }

        model: myModel

        // Настройка строки в TableView для перехавата левого клика мыши
        rowDelegate: Rectangle {
            anchors.fill: parent
            color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white');
            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.RightButton | Qt.LeftButton
                onClicked: {
                    tableView.selection.clear()
                    tableView.selection.select(styleData.row)
                    tableView.currentRow = styleData.row
                    tableView.focus = true

                    switch(mouse.button) {
                    case Qt.RightButton:
                        contextMenu.popup() // Вызываем контексткное меню
                        break
                    default:
                        break
                    }
                }
            }
        }
    }

    // Контекстно меню предлагает удаление строки из базы данных
    Menu {
        id: contextMenu

        MenuItem {
            text: qsTr("Удалить")
            onTriggered: {
                /* Вызываем диалоговое окно,
                 * которое уточнит намерение удалить строку из базы данных
                 * */
                dialogDelete.open()
            }
        }
    }

    // Диалог подтверждения удаления строки из базы данных
    MessageDialog {
        id: dialogDelete
        title: qsTr("Удаление записи")
        text: qsTr("Подтвердите удаление записи из журнала")
        icon: StandardIcon.Warning
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        // При положительном ответе ...
        onAccepted: {
            /* ... удаляем строку по id,
             * который забираем из модели данных
             * по номеру строки в представлении
             * */
            database.removeRecord(myModel.getId(tableView.currentRow))
            myModel.updateModel();  // Обновляем модель данных
        }
    }
}
