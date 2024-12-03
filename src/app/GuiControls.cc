/**
 * @ingroup app
 * @brief Implementation of GuiControls
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "GuiControls.h"

#include <imgui.h>

void GuiControls::sizeText(const std::string& label, const Size& size) {
  ImGui::Text("%s: width: %.2f", label.c_str(), size.width);
  ImGui::Text("%s: height: %.2f", label.c_str(), size.height);
}

void GuiControls::positionText(const std::string& label, const Position& position) {
  ImGui::Text("%s: x: %.2f", label.c_str(), position.x);
  ImGui::Text("%s: y: %.2f", label.c_str(), position.y);
}

void GuiControls::rotationText(const std::string& label, const float rotation) {
  ImGui::Text("%s: %.2f", label.c_str(), rotation);
}

void GuiControls::rectText(const std::string& label, const Rect& rect) {
  positionText(label, rect.pos());
  sizeText(label, rect.size());
}

void GuiControls::rectRotText(const std::string& label, const RectRot& rect) {
  positionText(label, rect.pos());
  sizeText(label, rect.size());
  rotationText(label, rect.rotation());
}