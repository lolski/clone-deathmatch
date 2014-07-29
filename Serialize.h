/* 
 * File:   GraphSerialize.h
 * Author: lolski
 *
 * Created on December 5, 2012, 11:02 PM
 */

#ifndef SERIALIZE_H
#define	SERIALIZE_H

#include <irrlicht.h>
#include "LevelAIEditor.h"

namespace boost {
    namespace serialization {
        using namespace irr;
        using namespace irr::core;
        template<class Archive>
        void serialize(Archive &ar, vector3df &vec, const unsigned int version) {
            ar & vec.X;
            ar & vec.Y;
            ar & vec.Z;
        }
        template<class Archive>
        void serialize(Archive &ar, vector3di &vec, const unsigned int version) {
            ar & vec.X;
            ar & vec.Y;
            ar & vec.Z;
        }
        template<class Archive>
        void serialize(Archive &ar, VertexId id, const unsigned int version) {
            ar & id;
        }
        template<class Archive>
        void serialize(Archive &ar, LevelAIEditor &l, const unsigned int version) {
            ar & l.waypoint;
        }
        template<class Archive>
        void serialize(Archive &ar, WaypointNode &n, const unsigned int version) {
            ar & n.position;
            ar & n.type;
        }
        
    }
}

#endif	/* GRAPHSERIALIZE_H */

