add_library(
  BlackjackLib
  cards/Card.cpp
  cards/Deck.cpp
  game/Game.cpp
  game/UserDealerGame.cpp
  io/IO.cpp
  io/TerminalIO.cpp
  player/Dealer.cpp
  player/Player.cpp
  player/User.cpp)

target_link_libraries(BlackjackLib PUBLIC ${CONAN_LIBS})
