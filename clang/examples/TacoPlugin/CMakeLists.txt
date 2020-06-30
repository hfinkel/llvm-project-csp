set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -g")

add_llvm_library(TacoTokensSyntax MODULE TacoTokensSyntax.cpp PLUGIN_TOOL clang)

if(LLVM_ENABLE_PLUGINS)
  set(LLVM_LINK_COMPONENTS
    Support
  )
  clang_target_link_libraries(TacoTokensSyntax PRIVATE
    clangAST
    clangBasic
    clangParse
    clangLex
    )
endif()
