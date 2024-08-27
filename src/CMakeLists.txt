add_library(BlackjackLib Dealer.cpp Deck.cpp Game.cpp Player.cpp User.cpp
                         UserDealerGame.cpp)

target_link_libraries(BlackjackLib PUBLIC ${CONAN_LIBS})
