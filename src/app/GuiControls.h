/**
 * @ingroup app
 * @brief GUI controls for displaying information about objects in the simulation.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef GUICONTROLS_H
#define GUICONTROLS_H

#include <string>

#include "Position.h"
#include "Rect.h"
#include "RectRot.h"
#include "Size.h"

class GuiControls {
 public:
  static void sizeText( const std::string& label, const Size& size );

  static void positionText( const std::string& label, const Position& position );

  static void rotationText( const std::string& label, const float rotation );

  static void rectText( const std::string& label, const Rect& rect );

  static void rectRotText( const std::string& label, const RectRot& rect );
};

#endif  // GUICONTROLS_H
