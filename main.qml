import QtQuick 2.10
import QtQuick.Window 2.10
import MosaicEngine 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Ejemplo de QML / C++")

    // Instancial QmlMosaicEngine como un componente QML.
    MosaicEngine {
        id: mosaicEngine
    }

    Grid {
        columns: 3
        spacing: 10

        Repeater {
            // QmlMosaicEngine expone el estado de los mosaicos de MosaicEngine (C++) a
            // través de la propiedad mosaic. Esta propiedad sirve como modelo para Repeater.
            model: mosaicEngine.mosaic

            // El delegate para representar cada mosaico será el componente Tile.
            Tile {
                width: 70
                height: 70

                // Al hacer click un componente Tile, cambiar el estado de mosaico.
                // row, column y status son propiedades de los objetos listados en el modelo
                // mosaicEngine.mosaic
                occupy: status
                onClicked: mosaicEngine.occupyMosaic(row, column)
            }
        }
    }
}
