#include <ControlPanel.h>
#include <gtest/gtest.h>

namespace ControlPanelUnitTest {

TEST( ControlPanel, delayIsZeroWithDefaultMaxSpeed ) {
  const ControlPanel control_panel;
  EXPECT_EQ( control_panel.getDelayMicroseconds(), 0 );
}

}  // namespace ControlPanelUnitTest