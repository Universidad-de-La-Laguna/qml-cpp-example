#include "mosaicengine.h"
#include "mosaicenginestatus.h"

bool MosaicEngine::occupyMosaic(size_t row, size_t column)
{
    // Comprobar si el mosáico está libre.
    if (status_.mosaic.at(row).at(column) != MosaicStatus::Free) {
        return false;
    }

    // Si está libre, ocuparlo.
    status_.mosaic.at(row).at(column) = MosaicStatus::Occupied;
    return true;
}
