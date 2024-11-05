//
// Created by mgarbowski on 11/5/24.
//

#ifndef GUICONTROLS_H
#define GUICONTROLS_H
#include <imgui.h>
#include <string>

#include "Position.h"
#include "Rect.h"
#include "RectRot.h"
#include "Size.h"

class GuiControls {
 public:
  static void sizeText(const std::string& label, const Size& size) {
    ImGui::Text("%s: width: %.2f", label.c_str(), size.width);
    ImGui::Text("%s: height: %.2f", label.c_str(), size.height);
  }

  static void positionText(const std::string& label, const Position& position) {
    ImGui::Text("%s: x: %.2f", label.c_str(), position.x);
    ImGui::Text("%s: y: %.2f", label.c_str(), position.y);
  }

  static void rotationText(const std::string& label, const float rotation) {
    ImGui::Text("%s: %.2f", label.c_str(), rotation);
  }

  static void rectText(const std::string& label, const Rect& rect) {
    positionText(label, rect.pos());
    sizeText(label, rect.size());
  }

  static void rectRotText(const std::string& label, const RectRot& rect) {
    positionText(label, rect.pos());
    sizeText(label, rect.size());
    rotationText(label, rect.rotation());
  }
};

#endif  // GUICONTROLS_H
