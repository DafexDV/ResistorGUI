#ifndef RESISTORGUI_DOMAIN_RESISTOR_KIND_HPP
#define RESISTORGUI_DOMAIN_RESISTOR_KIND_HPP

#include <string>
#include <vector>

enum class ResistorKind
{
    FourBands,
    FiveBands,
    SixBands
};

inline const std::vector<ResistorKind> RESISTOR_KINDS{
    ResistorKind::FourBands,
    ResistorKind::FiveBands,
    ResistorKind::SixBands
};

std::string to_string(ResistorKind kind);

#endif