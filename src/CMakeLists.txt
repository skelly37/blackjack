add_library(Template Deck.cpp Player.cpp)

target_link_libraries(Template PUBLIC ${CONAN_LIBS})
