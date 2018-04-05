#pragma once

#include "mosaicenginestatus.h"

#include <QObject>

//
// Component para exponer MosaicEngineStatus a QML.
//

class QmlMosaicStatus : public QObject
{
    Q_OBJECT

    // Usamos CONSTANT para que QML sepa que estas propiedades no cambian.
    // Vamos a generar objetos QmlMosaicStatus nuevos cada vez que QML lo pida.
    Q_PROPERTY(int row MEMBER row_ CONSTANT)
    Q_PROPERTY(int column MEMBER column_ CONSTANT)
    Q_PROPERTY(Status status MEMBER status_ CONSTANT)

public:
    enum class Status
    {
        Free = static_cast<int>(MosaicStatus::Free),
        Occupied = static_cast<int>(MosaicStatus::Occupied),
    };
    Q_ENUM(Status)

    explicit QmlMosaicStatus(QObject *parent = nullptr);
    explicit QmlMosaicStatus(size_t row, size_t column, MosaicStatus status,
                             QObject *parent = nullptr);

signals:

public slots:

private:
    size_t row_;
    size_t column_;
    Status status_;
};
