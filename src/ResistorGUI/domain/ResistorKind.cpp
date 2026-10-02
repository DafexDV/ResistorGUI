#include "ResistorGUI/domain/ResistorKind.hpp"

#include <string>
#include <stdexcept>

std::string to_string(ResistorKind kind)
{
    switch (kind)
    {
    case ResistorKind::FourBands:
        return "FourBands";

    case ResistorKind::FiveBands:
        return "FiveBands";

    case ResistorKind::SixBands:
        return "SixBands";
    }

    throw std::invalid_argument("Invalid ResistorKind");
}