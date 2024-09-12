add_library(
  BlackjackLib
  cards/Card.cpp
  cards/Deck.cpp
  communication/UserChoice.cpp
  communication/GameStatus.cpp
  player/Dealer.cpp
  player/Player.cpp
  player/User.cpp
  ui/bottom_button_states/HitButtonState.cpp
  ui/bottom_button_states/PlayAgainButtonState.cpp
  ui/bottom_button_states/BottomButtonState.cpp
  ui/bottom_button_states/QuitButtonState.cpp
  ui/bottom_button_states/StandButtonState.cpp
  ui/CardWidget.cpp
  ui/CardsGrid.cpp
  ui/GameWindow.cpp
  ui/PushButton.cpp
  ui/PlayerStatsLabel.cpp
  ui/VerticalHalfBox.cpp
  BlackjackGame.cpp)

target_link_libraries(BlackjackLib PUBLIC ${CONAN_LIBS})
target_compile_definitions(BlackjackLib
                           PUBLIC ASSETS_DIR="${CMAKE_SOURCE_DIR}/assets")
