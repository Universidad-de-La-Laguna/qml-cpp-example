#pragma once

#include "mosaicengine.h"
#include "qmlmosaicstatus.h"

#include <QObject>
#include <QQmlListProperty>

//
// Component para exponer MosaicEngine a QML.
//

class QmlMosaicEngine : public QObject
{
    Q_OBJECT

    // Propiedad 'mosaic' para exponer el estado del mosáico de MosaicEngine.
    // Se usa una lista QQmlListProperty de objetos QmlMosaicStatus. Cada instancia de
    // QmlMosaicStatus expone el estado de uno de los mosaicos en MosaicEngineStatus.
    Q_PROPERTY(QQmlListProperty<QmlMosaicStatus> mosaic READ mosaic NOTIFY mosaicChanged)

public:
    explicit QmlMosaicEngine(QObject *parent = nullptr);

    // Getter de la propiedad mosaic.
    inline QQmlListProperty<QmlMosaicStatus> mosaic() {
        // Construir el objeto QQmlListProperty<QmlMosaicStatus>
        return {this, nullptr, countMosaic, atMosaic};
    }

signals:
    // Señal ha emitir cuando el estado de un mosáico cambia.
    // Así QML sabe que ha habido un cambio en la propiedad 'mosaic'.
    void mosaicChanged();

public slots:
    // Exponer el método MosaicEngine::occupyMosaic() para ocupar un mosaico.
    bool occupyMosaic(int row, int column);

private:
    // Objeto MosaicEngine expuesto por cada instancia de este component.
    MosaicEngine mosaicEngine_;

    // Funciones para QQmlListProperty<QmlMosaicStatus>
    static QmlMosaicStatus* atMosaic(QQmlListProperty<QmlMosaicStatus>* property,
                                     int index);
    static int countMosaic(QQmlListProperty<QmlMosaicStatus>* property);
};
