#pragma once

#include <array>

//
// Clase de estado de MosaicEngine.
//

enum class MosaicStatus
{
    Free,
    Occupied,
};

struct MosaicEngineStatus
{
    // Estado del mosaico
    std::array<std::array<MosaicStatus, 3>, 3> mosaic = {{
        {{MosaicStatus::Free, MosaicStatus::Free, MosaicStatus::Free}},
        {{MosaicStatus::Free, MosaicStatus::Free, MosaicStatus::Free}},
        {{MosaicStatus::Free, MosaicStatus::Free, MosaicStatus::Free}},
    }};
};
