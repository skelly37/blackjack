add_library(
  BlackjackLib
  cards/Card.cpp
  cards/Deck.cpp
  communication/UserChoice.cpp
  communication/GameStatus.cpp
  player/Dealer.cpp
  player/Player.cpp
  player/User.cpp
  ui/CardWidget.cpp
  ui/CardsGrid.cpp
  ui/GameWindow.cpp
  ui/PushButton.cpp
  ui/PushButtonStates.cpp
  ui/PlayerStatsLabel.cpp
  ui/VerticalHalfBox.cpp)

target_link_libraries(BlackjackLib PUBLIC ${CONAN_LIBS})
target_compile_definitions(BlackjackLib
                           PUBLIC ASSETS_DIR="${CMAKE_SOURCE_DIR}/assets")
