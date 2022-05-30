################################################################################
#                                                                              #
#  Copyright (c) 2016, C3D Labs LLC                                            #
#  All rights reserved.                                                        #
#                                                                              #
#  This file is part of C3DVision Library                                      #
#  http://c3dlabs.com                                                          #
#                                                                              #
#  Exclusive rights to C3D Vision, any copies or components (parts) thereof    #
#  and other intellectual property belong to C3D Labs, LLC (the Rightholder).  # 
#  The license rights and restrictions are regulated by the Agreement between  #
#  the User and the Rightholder.                                               #
#                                                                              #
################################################################################

project(PneumocylinderConfigurator)

cmake_minimum_required(VERSION 3.4)

set(CMAKE_AUTOMOC TRUE)

INCLUDE_DIRECTORIES(${C3D_Math_INCLUDE_DIR} ${C3D_Vision_INCLUDE_DIR} ${QtVision_SOURCE_DIR}/Include)
ADD_DEFINITIONS(-DQT_NO_DEPRECATED_WARNINGS)

file(GLOB SRC_Configurator_h "*.h")
SOURCE_GROUP(Headers FILES ${SRC_Configurator_h})

file(GLOB SRC_Configurator_cpp "*.cpp")
SOURCE_GROUP(Sources FILES ${SRC_Configurator_cpp})

file(GLOB UI_Files "*.ui")
QT5_WRAP_UI(UI_Prop ${UI_Files})
SOURCE_GROUP(Forms FILES ${UI_Files})

file(GLOB RES_Configurator_rc "*.rc")
file(GLOB RCC_Configurator_qrc "*.qrc")
QT5_ADD_RESOURCES(RCC_Gui ${RCC_Configurator_qrc})
SOURCE_GROUP(Resources FILES ${RES_Configurator_rc} ${RCC_Configurator_qrc})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ADD_EXECUTABLE(${Configurator_OUTPUT} WIN32 ${SRC_Configurator_cpp} ${SRC_Configurator_h} ${RES_Configurator_rc} ${UI_Prop} ${RCC_Gui})
TARGET_LINK_LIBRARIES(${Configurator_OUTPUT} ${C3D_MATH_LIB} ${C3D_VIS_LIB} ${QtVision_OUTPUT} ${OPENGL_LIBRAREIS} ${STDLIB})
qt5_use_modules( ${Configurator_OUTPUT} Core Gui OpenGL Widgets )
