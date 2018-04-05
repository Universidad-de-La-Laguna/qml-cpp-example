#include "qmlmosaicengine.h"
#include "qmlmosaicstatus.h"
#include "mosaicenginestatus.h"

#include <QQmlListProperty>
#include <QQmlEngine>

QmlMosaicEngine::QmlMosaicEngine(QObject *parent) : QObject(parent)
{

}

bool QmlMosaicEngine::occupyMosaic(int row, int column)
{
    if (mosaicEngine_.occupyMosaic(static_cast<size_t>(row), static_cast<size_t>(column))) {
        // Si la ocupación tuvo éxito, emitar la seal de que la propiedad 'mosaic' ha cambiado.
        emit mosaicChanged();
        return true;
    }
    return false;
}

//
// Funciones para QQmlListProperty<QmlMosaicStatus>
//
// Estas funciones se pasan el constructor de QQmlListProperty<QmlMosaicStatus> son
// llamadas de forma transparente desde QML cuando el engine de QML quiere conocer
// algun algún detalle o quiere manupular la lista.
//

// Obtener un elemento particular de QQmlListProperty<QmlMosaicStatus>

QmlMosaicStatus* QmlMosaicEngine::atMosaic(
        QQmlListProperty<QmlMosaicStatus> *property, int index)
{
    auto qmlMosaicEngine = qobject_cast<QmlMosaicEngine*>(property->object);
    auto& mosaic = qmlMosaicEngine->mosaicEngine_.status().mosaic;

    // Obtener las coordenadas 2D en la matriz mosaic.
    size_t row = static_cast<size_t>(index) / mosaic.size();
    size_t column = static_cast<size_t>(index) % mosaic.size();

    auto& status = mosaic.at(row).at(column);
    auto* qmlMosaicStatus = new QmlMosaicStatus(row, column, status);

    // Por defecto, los objetos creados por QML son de QML y los creados por C++ son
    // propiedad de C++. Excepto los devueltos por invocaciones implícitas a métodos de
    // C++. Sin embargo, esto no incluye los getter de las propiedades, así que mejor
    // asegurarse de que QML se haga cargo del nuevo objeto.
    // http://doc.qt.io/qt-5/qqmlengine.html#ObjectOwnership-enum
    QQmlEngine::setObjectOwnership(qmlMosaicStatus, QQmlEngine::JavaScriptOwnership);

    return qmlMosaicStatus;
}

// Obtener el número de elementos en QQmlListProperty<QmlMosaicStatus>
//
// Será el número de mosáicos en mosaicEngine_.status().mosaic.

int QmlMosaicEngine::countMosaic(QQmlListProperty<QmlMosaicStatus> *property)
{
    auto qmlMosaicEngine = qobject_cast<QmlMosaicEngine*>(property->object);
    auto& mosaic = qmlMosaicEngine->mosaicEngine_.status().mosaic;
    return static_cast<int>(mosaic.size() * mosaic[0].size());
}
