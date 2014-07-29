#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/BotManager.o \
	${OBJECTDIR}/GenerateUnsignedInt.o \
	${OBJECTDIR}/GetCurrentDateTime.o \
	${OBJECTDIR}/GameManager.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/_ext/1564822285/PrintSceneNodeImmediateChildren.o \
	${OBJECTDIR}/_ext/1564822285/Weapon.o \
	${OBJECTDIR}/Human.o \
	${OBJECTDIR}/Bot.o \
	${OBJECTDIR}/StateManager.o \
	${OBJECTDIR}/MovementTimer.o \
	${OBJECTDIR}/_ext/1564822285/ID.o \
	${OBJECTDIR}/_ext/1564822285/CatmullRomSpline.o \
	${OBJECTDIR}/debug.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -L/usr/local/Cellar/boost/1.49.0/lib /usr/local/irrlicht-1.7.3/lib/MacOSX/libIrrlicht.a /usr/local/Cellar/boost/1.49.0/lib/libboost_serialization-mt.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS/final

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS/final: /usr/local/irrlicht-1.7.3/lib/MacOSX/libIrrlicht.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS/final: /usr/local/Cellar/boost/1.49.0/lib/libboost_serialization-mt.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS/final: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS/final ${OBJECTFILES} ${LDLIBSOPTIONS} -framework OpenGL -framework Carbon -framework Cocoa -framework IOKit -lboost_serialization-mt

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/BotManager.o: BotManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/BotManager.o BotManager.cpp

${OBJECTDIR}/GenerateUnsignedInt.o: GenerateUnsignedInt.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/GenerateUnsignedInt.o GenerateUnsignedInt.cpp

${OBJECTDIR}/GetCurrentDateTime.o: GetCurrentDateTime.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/GetCurrentDateTime.o GetCurrentDateTime.cpp

${OBJECTDIR}/GameManager.o: GameManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/GameManager.o GameManager.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/_ext/1564822285/PrintSceneNodeImmediateChildren.o: /Users/lolski/UVA/gameprog/final/PrintSceneNodeImmediateChildren.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1564822285
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1564822285/PrintSceneNodeImmediateChildren.o /Users/lolski/UVA/gameprog/final/PrintSceneNodeImmediateChildren.cpp

${OBJECTDIR}/_ext/1564822285/Weapon.o: /Users/lolski/UVA/gameprog/final/Weapon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1564822285
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1564822285/Weapon.o /Users/lolski/UVA/gameprog/final/Weapon.cpp

${OBJECTDIR}/Human.o: Human.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Human.o Human.cpp

${OBJECTDIR}/Bot.o: Bot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bot.o Bot.cpp

${OBJECTDIR}/StateManager.o: StateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/StateManager.o StateManager.cpp

${OBJECTDIR}/MovementTimer.o: MovementTimer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/MovementTimer.o MovementTimer.cpp

${OBJECTDIR}/_ext/1564822285/ID.o: /Users/lolski/UVA/gameprog/final/ID.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1564822285
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1564822285/ID.o /Users/lolski/UVA/gameprog/final/ID.cpp

${OBJECTDIR}/_ext/1564822285/CatmullRomSpline.o: /Users/lolski/UVA/gameprog/final/CatmullRomSpline.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1564822285
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1564822285/CatmullRomSpline.o /Users/lolski/UVA/gameprog/final/CatmullRomSpline.cpp

${OBJECTDIR}/debug.o: debug.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/irrlicht-1.7.3/include -I/usr/local/Cellar/boost/1.49.0/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/debug.o debug.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/final.app/Contents/MacOS/final

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
