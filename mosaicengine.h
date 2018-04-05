#pragma once

#include "mosaicenginestatus.h"

//
//  MosaicEngine gestiona el estado MosaicEngineStatus.
//

class MosaicEngine
{
public:

    // Obtener el objeto MosaicEngineStatus interno con el estado.
    inline const MosaicEngineStatus& status()
    {
        return status_;
    }

    // Ocupar un mosáico en concreto.
    // Modifica el estado del mosáico en la matriz statuc->mosaic.
    bool occupyMosaic(size_t row, size_t column);

private:
    MosaicEngineStatus status_;
};
