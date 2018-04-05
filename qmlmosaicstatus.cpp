#include "qmlmosaicstatus.h"

QmlMosaicStatus::QmlMosaicStatus(QObject *parent)
    : QObject(parent), row_{0}, column_{0}, status_{Status::Free}
{

}

QmlMosaicStatus::QmlMosaicStatus(size_t row, size_t column, MosaicStatus status,
                                 QObject *parent)
    : QObject(parent), row_{row}, column_{column}, status_{static_cast<Status>(status)}
{

}
