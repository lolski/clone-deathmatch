/* 
 * File:   SpawnPointCollection.h
 * Author: lolski
 *
 * Created on October 22, 2012, 6:01 PM
 */

#ifndef SPAWNPOINTCOLLECTION_H
#define	SPAWNPOINTCOLLECTION_H

#include <string>
#include <sstream>
#include <map>
#include <irrlicht.h>

using namespace irr::core;

typedef std::pair<const std::string, vector3df> SpawnPointEntry;
typedef std::map<const std::string, vector3df>::iterator SpawnPointCollectionIterator;

class SpawnPointCollection {
public:
    SpawnPointCollection() {
        
    }
    void addBotSpawnPoint(const std::string& key, const vector3df& loc) {
        SpawnPointEntry entry(key, loc);
        botSpawnPoints.insert(entry);
    }

    void addPlayerSpawnPoint(const std::string& key, const vector3df& loc) {
        SpawnPointEntry entry(key, loc);
        playerSpawnPoints.insert(entry);
    }
    void addBotSpawnPoint(const vector3df& loc) {
        std::stringstream out;
        int size = botSpawnPoints.size()-1;
        out << size;
        std::string key = out.str();
        SpawnPointEntry entry(key, loc);
        botSpawnPoints.insert(entry);
    }

    void addPlayerSpawnPoint(const vector3df& loc) {
        std::stringstream out;
        int size = botSpawnPoints.size()-1;
        out << size;
        std::string key = out.str();
        SpawnPointEntry entry(key, loc);
        playerSpawnPoints.insert(entry);
    }
    size_t removeBotSpawnPoint(const std::string& key) {
        size_t count = botSpawnPoints.erase(key);
        return count;
    }
    size_t removePlayerSpawnPoint(const std::string& key) {
        size_t count = playerSpawnPoints.erase(key);
        return count;
    }
    SpawnPointCollectionIterator getPlayerSpawnPoint(const std::string& key) {
        SpawnPointCollectionIterator it = playerSpawnPoints.find(key);
        return it;
    }
    SpawnPointCollectionIterator getBotSpawnPoint(const std::string& key) {
        SpawnPointCollectionIterator it = botSpawnPoints.find(key);
        return it;
    }
    bool debug;
    std::map<std::string, vector3df> botSpawnPoints, playerSpawnPoints;
private:

};

#endif	/* SPAWNPOINTCOLLECTION_H */

