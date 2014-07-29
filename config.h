/* 
 * File:   config.h
 * Author: lolski
 *
 * Created on September 14, 2009, 10:20 PM
 */

#ifndef _CONFIG_H
#define	_CONFIG_H

#include <irrlicht.h>

int const BOT_COUNT = 0;

// DISPLAY
int const WIDTH = 1024;
int const HEIGHT = 768;


// RESOURCES
char const * const MENU_BG = "/Users/lolski/UVA/gameprog/final/media/menu.png";
char const * const MENU_START = "/Users/lolski/UVA/gameprog/final/media/startgame.png";
char const * const MENU_CONTINUE = "/Users/lolski/UVA/gameprog/final/media/contgame.png";
char const * const MENU_EXIT = "/Users/lolski/UVA/gameprog/final/media/exitgame.png";
int const MENU_OPTION_WIDTH = 300;
int const MENU_OPTION_HEIGHT = 50;

char const * const MAP_ARCHIVE = "/Users/lolski/UVA/gameprog/final/media/map-20kdm2.pk3";
char const * const MAP_NAME = "20kdm2.bsp";
float const MAP_COORD[3] = {-1370, -130, -1400};
char const * const MODEL_NAME = "/Users/lolski/UVA/gameprog/final/media/sydney.md2";
char const * const MODEL_TEXTURE = "/Users/lolski/UVA/gameprog/final/media/sydney.bmp";

char const * const PARTICLE_BULLET = "/Users/lolski/UVA/gameprog/final/media/particle.bmp";

char const * const HUMAN_GUI_CROSSHAIR = "/Users/lolski/UVA/gameprog/final/media/crosshair.png";
char const * const HUMAN_GUI_HEALTH_0 = "/Users/lolski/UVA/gameprog/final/media/human_health_0.png";
char const * const HUMAN_GUI_HEALTH_20 = "/Users/lolski/UVA/gameprog/final/media/human_health_20.png";
char const * const HUMAN_GUI_HEALTH_40 = "/Users/lolski/UVA/gameprog/final/media/human_health_40.png";
char const * const HUMAN_GUI_HEALTH_60 = "/Users/lolski/UVA/gameprog/final/media/human_health_60.png";
char const * const HUMAN_GUI_HEALTH_80 = "/Users/lolski/UVA/gameprog/final/media/human_health_80.png";
char const * const HUMAN_GUI_HEALTH_100 = "/Users/lolski/UVA/gameprog/final/media/human_health_100.png";

char const * const SPAWN_POINT_BOT = "/Users/lolski/UVA/gameprog/final/media/spawnbot.bmp";
char const * const SPAWN_POINT_PLAYER = "/Users/lolski/UVA/gameprog/final/media/spawnplayer.bmp";

char const * const GRAPHVIZ_DUMP = "/Users/lolski/UVA/gameprog/final/waypoint/graphvizdump";

char const * const WAYPOINT1_PATH = "/Users/lolski/UVA/gameprog/final/waypoints/1.wpt";
char const * const WAYPOINT2_PATH = "/Users/lolski/UVA/gameprog/final/waypoints/2.wpt";
char const * const WAYPOINT3_PATH = "/Users/lolski/UVA/gameprog/final/waypoints/3.wpt";


#endif	/* _CONFIG_H */

