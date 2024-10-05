# Install script for directory: C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/pkgs/sdl2_x64-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/SDL2d.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/SDL2d.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/SDL2maind.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake"
         "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/SDL2Config.cmake"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/SDL2ConfigVersion.cmake"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/cmake/sdlfind.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_assert.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_atomic.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_audio.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_bits.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_blendmode.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_clipboard.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_copying.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_cpuinfo.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_egl.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_endian.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_error.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_events.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_filesystem.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_gamecontroller.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_gesture.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_guid.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_haptic.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_hidapi.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_hints.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_joystick.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_keyboard.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_keycode.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_loadso.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_locale.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_log.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_main.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_messagebox.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_metal.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_misc.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_mouse.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_mutex.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_name.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengl.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengl_glext.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_gl2.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_gl2ext.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_gl2platform.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_opengles2_khrplatform.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_pixels.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_platform.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_power.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_quit.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_rect.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_render.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_rwops.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_scancode.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_sensor.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_shape.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_stdinc.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_surface.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_system.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_syswm.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_assert.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_common.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_compare.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_crc32.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_font.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_fuzzer.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_harness.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_images.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_log.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_md5.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_memory.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_test_random.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_thread.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_timer.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_touch.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_types.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_version.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_video.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/SDL_vulkan.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/begin_code.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/include/close_code.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/include/SDL2/SDL_revision.h"
    "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/include-config-debug/SDL2/SDL_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licenses/SDL2" TYPE FILE FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/src/ase-2.28.2-705f8fad22.clean/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/sdl2.pc")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/plant/Desktop/Coding/03 - Desktop Development/FractalRenderer/vcpkg_installed/x64-windows/vcpkg/blds/sdl2/x64-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
