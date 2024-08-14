add_library(BlackjackLib Deck.cpp Player.cpp)

target_link_libraries(BlackjackLib PUBLIC ${CONAN_LIBS})
